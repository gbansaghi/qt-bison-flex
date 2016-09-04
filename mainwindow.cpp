#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QSpinBox>

#include "testparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Choose file", QDir::current().absolutePath(), "Sample input files (*.sif)");

    if (path.isEmpty()) {
        ui->filePathEdit->clear();
        return;
    }

    QFileInfo fi(path);
    ui->filePathEdit->setText(fi.fileName());
    ui->filePathEdit->setToolTip(path);
}

void MainWindow::on_parseButton_clicked()
{
    if (ui->filePathEdit->text().isEmpty()) {
        return;
    }

    QFile f(ui->filePathEdit->toolTip());
    f.open(QFile::ReadOnly);
    QByteArray content(f.readAll());
    TestParser parser(content);

    resetResultWidgets();

    foreach (const ParseElement& e, parser.elements()) {
        addResultWidget(e.max, e.alignment);
    }
}

void MainWindow::resetResultWidgets()
{
    while (ui->resultsAreaContents->layout()->count() > 0) {
        QLayoutItem* item = ui->resultsAreaContents->layout()->takeAt(0);
        delete item->widget();
        delete item;
    }
}

void MainWindow::addResultWidget(int max, Qt::AlignmentFlag align)
{
    QSpinBox* sb = new QSpinBox(ui->resultsAreaContents);
    sb->setMaximum(max);

    QLabel* l = new QLabel(ui->resultsAreaContents);
    l->setText("Sample text");
    l->setAlignment(align);

    QFormLayout* layout = static_cast<QFormLayout*>(ui->resultsAreaContents->layout());
    layout->addRow(sb, l);
}

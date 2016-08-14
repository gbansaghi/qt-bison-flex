#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void browse();
    void parse();

private:
    Ui::MainWindow *ui;

    void resetResultWidgets();
    void addResultWidget(int max, Qt::AlignmentFlag align);
};

#endif // MAINWINDOW_H

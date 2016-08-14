#ifndef COMMON_H
#define COMMON_H

#include <QVector>

typedef struct ParseElement {
    int max;
    Qt::AlignmentFlag alignment;
} ParseElement;
typedef QVector<ParseElement> elements_t;

typedef struct ParserException {
    int lineNumber;
    QString what;
} ParserException;

#endif // COMMON_H

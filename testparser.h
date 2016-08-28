#ifndef TESTPARSER_H
#define TESTPARSER_H

#include <QVector>

#include "common.h"
#include "scanner.h"

class YYBufferGuard
{
    YY_BUFFER_STATE* mState;
public:
    YYBufferGuard(YY_BUFFER_STATE *state);
    ~YYBufferGuard();
};

class TestParser
{
    elements_t mElements;
public:
    TestParser(QByteArray data);
    elements_t& elements();
};

#endif // TESTPARSER_H

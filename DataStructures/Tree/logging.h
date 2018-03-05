#pragma once

#include <iostream>
using namespace std;

#define TEST_LOGGING 0

enum LOG_LEVEL {
    LOG_DEBUG,
    LOG_INFO,
    LOG_ERROR,
    LOG_NONE
};

class LOGGING
{
    LOG_LEVEL LL;
public:
    LOGGING() : LL(LOG_INFO) { }

    void setLogLevel(LOG_LEVEL aLL) { LL = aLL; }

    void log(string text, LOG_LEVEL aLL);
};
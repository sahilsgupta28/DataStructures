#include <iostream>
#include "logging.h"

void LOGGING::log(string text, LOG_LEVEL aLL)
{
    if (aLL >= LL)
        std::cout << text.c_str();
}

#if TEST_LOGGING

int main()
{
    LOGGING logger;

    logger.setLogLevel(LOG_DEBUG);

    logger.log("LOG_1", LOG_DEBUG);
    logger.log("LOG_2", LOG_INFO);
    logger.log("LOG_3", LOG_ERROR);
}

#endif
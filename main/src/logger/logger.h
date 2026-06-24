//this is what the logger interface can do.
#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
public:
    static void info(
        const char* message
    );

    static void warning(
        const char* message
    );

    static void error(
        const char* message
    );

    static void state(
        const char* message
    );
};

#endif
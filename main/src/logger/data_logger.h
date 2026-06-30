//this data logger file generates the csv file (dataset) for machine learning implementation
// uses the log record as input and outputs a csv file
#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include <Arduino.h>

//we  include  the log record file because that's what we are using 
#include "log_record.h"

class DataLogger
{
public:

    static String buildCSV(
        const LogRecord& record
    );

private:

    static const char*
    decisionToString(
        IrrigationDecision decision
    );

    static const char*
    stateToString(
        SystemState state
    );
};

#endif

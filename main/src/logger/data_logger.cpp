//this piece of code changes the format of the data output log
//into human readable and machine readable format

//...output instance
// 1520,32.4,42.1,18,950,CONTEXT_IRRIGATION,MONITORING

#include <Arduino.h>
#include "data_logger.h"

//implementation of decision to string
const char*
DataLogger::decisionToString(
    IrrigationDecision decision)
{
    switch(decision)
    {
        case IrrigationDecision::CRITICAL_IRRIGATION:
            return "CRITICAL_IRRIGATION";

        case IrrigationDecision::CONTEXT_IRRIGATION:
            return "CONTEXT_IRRIGATION";

        case IrrigationDecision::DO_NOT_IRRIGATE:
            return "DO_NOT_IRRIGATE";
    }

    return "UNKNOWN";
}

//state to string
const char*
DataLogger::stateToString(
    SystemState state)
{
    switch(state)
    {
        case SystemState::MONITORING:
            return "MONITORING";

        case SystemState::IRRIGATING:
            return "IRRIGATING";

        case SystemState::SETTLING:
            return "SETTLING";

        case SystemState::FAULT:
            return "FAULT";
    }

    return "UNKNOWN";
}

//complete building of csv file
//appending the timestamp, sensor data, decision and state
String
DataLogger::buildCSV(
    const LogRecord& record)
{
    String csv;

    csv += String(record.timestamp);
    csv += ",";

    csv += String(record.sensorData.temperature);
    csv += ",";

    csv += String(record.sensorData.humidity);
    csv += ",";

    csv += String(record.sensorData.soilMoisture);
    csv += ",";

    csv += String(record.sensorData.lightIntensity);
    csv += ",";

    csv += decisionToString(
        record.decision);

    csv += ",";

    csv += stateToString(
        record.state);

    return csv;
}
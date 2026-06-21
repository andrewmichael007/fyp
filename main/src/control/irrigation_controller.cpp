#include "irrigation_controller.h"

IrrigationDecision IrrigationController::evaluate( const SensorData& data)
{
    // priority 1:
    // emergency protection

    if(data.soilMoisture < 15)
    {
        return IrrigationDecision::CRITICAL_IRRIGATION;
    }

    // priority 2:
    // context-aware irrigation

    if(data.soilMoisture < 30 &&
       data.temperature > 30 &&
       data.humidity < 50)
    {
        return IrrigationDecision::CONTEXT_IRRIGATION;
    }

    return IrrigationDecision::DO_NOT_IRRIGATE;
}
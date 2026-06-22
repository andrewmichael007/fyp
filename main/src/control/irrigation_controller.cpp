#include "irrigation_controller.h"
#include "../../include/config.h"

IrrigationProfile IrrigationController::evaluate(const SensorData& data)
{
    //create an object call profile
    IrrigationProfile profile;

    // default
    profile.decision = IrrigationDecision::DO_NOT_IRRIGATE;

    profile.shouldIrrigate = false;

    profile.durationMs = 0;

    // priority 1:
    // critical  moisture

    if(data.soilMoisture < 15)
    {
        profile.decision = IrrigationDecision::CRITICAL_IRRIGATION;

        profile.shouldIrrigate = true;

        profile.durationMs = CRITICAL_IRRIGATION_DURATION_MS;

        return profile;
    }

    // priority 2:
    // context-aware rule

    if(
        data.soilMoisture < 30 &&
        data.temperature > 30 &&
        data.humidity < 50
    )
    {
        profile.decision = IrrigationDecision::CONTEXT_IRRIGATION;

        profile.shouldIrrigate = true;

        profile.durationMs = CONTEXT_IRRIGATION_DURATION_MS;

        return profile;
    }

    return profile;
}
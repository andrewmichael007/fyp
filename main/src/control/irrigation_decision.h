// this file indicates which irrigation decisions can take place

// there are three irrigation decisions
// 1. critical irrigation - Soil moisture dangerously low.
// 2. context irrigation - Environmental conditions suggest water stress is likely.

#ifndef IRRIGATION_DECISION_H
#define IRRIGATION_DECISION_H

enum class IrrigationDecision
{
    CRITICAL_IRRIGATION,
    CONTEXT_IRRIGATION,
    DO_NOT_IRRIGATE
};

#endif
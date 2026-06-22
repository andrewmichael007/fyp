//this file controls the state of the system
#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H

#include "system_state.h"

class SystemController
{
    //members of system controller class
public:
    SystemController();

    SystemState getState();

    void setState(SystemState state);

    unsigned long getStateStartTime();

private:
    SystemState currentState;

    unsigned long stateStartTime;
};

#endif
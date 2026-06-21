//this is a state engine. 

//this shows which state the system is in at every point in time

// at every point the system can either be in;
// ... monitoring
// ... irrigating 
// ... settling
// ... fualt

#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

enum class SystemState
{
    MONITORING,
    IRRIGATING,
    SETTLING,
    FAULT
};

#endif
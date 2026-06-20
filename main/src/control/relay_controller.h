//this file  indicates what the relay controller can do

// the relay controller only executes irrigation controller

#ifndef RELAY_CONTROLLER_H
#define RELAY_CONTROLLER_H

class RelayController
{
public:
    bool begin();
    void startIrrigation();
    void stopIrrigation();
};

#endif
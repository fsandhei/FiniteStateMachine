#ifndef STATE1_H
#define STATE1_H

#include "StateBase.h"
#include <iostream>

class State1 : public StateBase
{
    public:
    explicit State1(FSM& fsm);

    void onEntry() override;
    void onExit() override;

};

State1::State1(FSM& fsm)
    : StateBase{fsm}
{
}


void
State1::onEntry()
{
    std::cout << "Hello from State1!" << std::endl;
}


void
State1::onExit()
{
    std::cout << "Goodbye from State1!" << std::endl;
}

#endif 
#ifndef STATE2_H
#define STATE2_H

#include "StateBase.h"
#include <iostream>

class State2 : public StateBase
{
    public:
    explicit State2(FSM& fsm);

    void onEntry() override;
    void onExit() override;
};

State2::State2(FSM& fsm)
    : StateBase{fsm}
{
}


void
State2::onEntry()
{
    std::cout << "Hello from State 2!" << std::endl;   
}


void
State2::onExit()
{
    std::cout << "Goodbye from State 2!" << std::endl;
}

#endif
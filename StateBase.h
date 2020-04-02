#ifndef STATEBASE_H
#define STATEBASE_H

#include "FiniteStateMachine.h"
#include <iostream>
#include "SomeInterface.h"

class StateBase;
using FSM = FiniteStateMachine<StateBase>;

class StateBase
    : public FSM::StateBase
    , public SomeInterface
{
    public:
    explicit StateBase(FSM& fsm);
    void doSomething() final;

};

StateBase::StateBase(FSM& fsm)
    : FSM::StateBase{fsm}
{
}


void
StateBase::doSomething()
{
    std::cout<<"someInterface::doSomething()" << std::endl;
}

#endif 
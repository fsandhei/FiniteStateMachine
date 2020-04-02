#ifndef FUNCTIONALFSM_H
#define FUNCTIONALFSM_H

#include "FiniteStateMachine.h"
#include "SomeInterface.h"
#include "State.h"
#include "State1.h"
#include "State2.h"


class FunctionalFsm : public FSM, public SomeInterface
{
    public:
    explicit FunctionalFsm();
    void startStateMachine();
    void doSomething() override;
};


FunctionalFsm::FunctionalFsm()
{
    FSM::registerState<State1>(State::SomeState1);
    FSM::registerState<State2>(State::SomeState2);
}


void
FunctionalFsm::startStateMachine()
{
    changeState(State::SomeState1);
}


void 
FunctionalFsm::doSomething()
{
    currentState().doSomething();
}

#endif 

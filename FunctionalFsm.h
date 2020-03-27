#ifndef FUNCTIONALFSM_H
#define FUNCTIONALFSM_H

#include "FiniteStateMachine.h"
#include "StateBase.h"
#include "State.h"
#include "State1.h"
#include "State2.h"

class FunctionalFsm : public FSM 
{
    public:
    explicit FunctionalFsm();
    void startStateMachine();
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


#endif 
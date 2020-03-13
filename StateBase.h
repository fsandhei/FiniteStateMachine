#ifndef STATEBASE_H
#define STATEBASE_H

#include "FiniteStateMachine.h"

class StateBase;
using FSM = FiniteStateMachine<StateBase>;

class StateBase
    : public FSM::StateBase
{
    public:
    explicit StateBase(FSM& fsm);
};

StateBase::StateBase(FSM& fsm)
    : FSM::StateBase{fsm}
{
}

#endif 
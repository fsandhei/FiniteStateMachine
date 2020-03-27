#ifndef STATEBASE_H
#define STATEBASE_H

#include "FiniteStateMachine.h"
#include <vector>

template <typename... ValidStates>
class StateBase;

using FSM = FiniteStateMachine<StateBase>;

template <typename... ValidStates>
class StateBase
    : public FSM::StateBase
{
    public:
    explicit StateBase(FSM& fsm);

    private:
    std::vector<ValidStates> legalStates;
};

template <typename... ValidStates>
StateBase::StateBase(FSM& fsm)
    : FSM::StateBase{fsm}
    , legalStates{std::forward<ValidStates>()}
{
}

#endif 
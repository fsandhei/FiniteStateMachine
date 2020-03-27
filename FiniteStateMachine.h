#ifndef FINITESTATEMACHINE_H
#define FINITESTATEMACHINE_H

#include "State.h"
#include <map>
#include <memory>
#include <typeinfo>
#include <stdexcept>

template <typename StateBaseType>
class FiniteStateMachine
{
    public:
    class StateBase;
    explicit FiniteStateMachine() = default;
    FiniteStateMachine(FiniteStateMachine const&)            = delete;
    FiniteStateMachine(FiniteStateMachine&&)                 = delete;
    FiniteStateMachine& operator=(FiniteStateMachine const&) = delete;
    FiniteStateMachine& operator=(FiniteStateMachine&&)      = delete; 
    virtual ~FiniteStateMachine() = default; 

    StateBaseType& currentState();
    void changeState(State state);

    protected:
    template <typename StateType> 
    void registerState(State state);
    template <typename StateType, typename... Data> 
    void registerState(State state, Data&&... data);

    using StateMap = std::map<State, std::unique_ptr<StateBaseType>>;
    State currentState_;
    StateMap states_; 

    private:
    bool started{false};
    void throwIfStateNotRegistered(State state) const;
};


template <typename StateBaseType>
class FiniteStateMachine<StateBaseType>::StateBase
{
    public:
    explicit StateBase(FiniteStateMachine& fsm);
    StateBase(StateBase const&)            = delete;
    StateBase(StateBase&&)                 = delete;
    StateBase& operator=(StateBase const&) = delete;
    StateBase& operator=(StateBase&&)      = delete;
    virtual ~StateBase() = default;

    virtual void onEntry() = 0;
    virtual void onExit() = 0;

    protected:
    FiniteStateMachine& fsm_;

};


template <typename StateBaseType>
FiniteStateMachine<StateBaseType>::StateBase::StateBase(FiniteStateMachine& fsm)
    : fsm_{fsm}
{
}


template <typename StateBaseType>
StateBaseType&
FiniteStateMachine<StateBaseType>::currentState()
{
    auto currentStatePair = states_.find(currentState_);
    return *(currentStatePair->second);
}


template <typename StateBaseType>
void
FiniteStateMachine<StateBaseType>::changeState(State state)
{
    throwIfStateNotRegistered(state);
    if (currentState_ == state && !started)
    {
        currentState().onEntry();
        started = true;
        return;
    }

    currentState().onExit();

    auto newType = states_.find(state);
    if (newType != states_.end())
    {
        currentState_ = newType->first;
        newType->second->onEntry();
    }
}


template <typename StateBaseType>
template <typename StateType>
void
FiniteStateMachine<StateBaseType>::registerState(State state)
{
    states_[state] = std::make_unique<StateType>(*this);
}


template <typename StateBaseType>
template <typename StateType, typename... Data>
void
FiniteStateMachine<StateBaseType>::registerState(State state, Data&&... data)
{
    states_[state] = std::make_unique<StateType>(*this, std::forward<Data>(data)...);
}


template <typename StateBaseType>
void
FiniteStateMachine<StateBaseType>::throwIfStateNotRegistered(State state) const
{
    auto potentialStatePair = states_.find(state);
    if (potentialStatePair == states_.end())
    {
        throw std::out_of_range{ "State not registered." };
    }
}


#endif 

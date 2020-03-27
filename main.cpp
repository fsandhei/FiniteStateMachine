#include "FunctionalFsm.h"

int main()
{
    FunctionalFsm fsm{}; 

    fsm.startStateMachine();
    fsm.changeState(State::SomeState2);
    fsm.changeState(State::SomeState1);
}
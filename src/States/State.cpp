#include "States/State.h"

#include "States/StateMachine.h"

namespace States {

    State::State(StateMachine* pSM, States::stateID id) :
    pSM(pSM),
    id(id) { }

    State::~State() {
        pSM = nullptr;
    }

    void State::setStateMachine(StateMachine* pSM) {
        this->pSM = pSM;
    }

    void State::changeState(States::stateID id) {
        pSM->changeCurrentState(id);
    }

    States::stateID State::getID() const {
        return id;
    }

} // namespace States
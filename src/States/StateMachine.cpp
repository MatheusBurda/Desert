#include "States/StateMachine.h"

#include "States/State.h"

#include <iostream>

namespace States {

    StateMachine::StateMachine() { }

    StateMachine::~StateMachine() {
        std::map<stateID, State*>::iterator it;

        for (it = mapOfStates.begin(); it != mapOfStates.end(); ++it) {
            delete (it->second);
        }
    }

    void StateMachine::changeCurrentState(States::stateID id) {
        currentStateID = id;
        mapOfStates[currentStateID]->resetState();
    }

    void StateMachine::execCurrentState(float dt) {
        mapOfStates[currentStateID]->update(dt);
        mapOfStates[currentStateID]->render();
    }

    stateID StateMachine::getCurrentStateID() const {
        return currentStateID;
    }

    void StateMachine::insertState(States::State* pState) {
        if (pState == nullptr) {
            std::cout << "ERROR pointer to State NULL on StateMachine::insertState()" << std::endl;
            exit(1);
        }
        mapOfStates.insert(std::pair<stateID, State*>(pState->getID(), pState));
    }

} // namespace States
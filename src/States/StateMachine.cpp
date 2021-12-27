#include "States/StateMachine.h"

#include "States/State.h"

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

} // namespace States
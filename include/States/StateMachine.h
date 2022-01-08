#pragma once

#include "States/State.h"
#include <map>

namespace States {

    class StateMachine {
    protected:
        States::stateID currentStateID;
        States::stateID lastStateID;

        std::map<stateID, State*> mapOfStates;

    public:
        StateMachine();

        virtual ~StateMachine();

        void changeCurrentState(States::stateID id);

        void updateCurrentState(const float dt);

        void renderCurrentState();

        States::stateID getCurrentStateID() const;

        void insertState(States::State* pState);

        States::stateID getLastStateID() const;
    };

}
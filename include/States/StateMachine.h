#pragma once

#include "States/State.h"
#include <map>

namespace States {

    class StateMachine {
    protected:
        States::stateID currentStateID;

        std::map<stateID, State*> mapOfStates;

    public:
        StateMachine();

        virtual ~StateMachine();

        void changeCurrentState(States::stateID id);

        void execCurrentState(const float dt);

        States::stateID getCurrentStateID() const;

        void insertState(States::State* pState);
    };

}
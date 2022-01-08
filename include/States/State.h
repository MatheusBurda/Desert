#pragma once

namespace States {

    class StateMachine;

    enum stateID {
        unknown = -1,
        mainMenu = 0,
        newGame,
        playing,
        pauseMenu,
        loadGame,
        leaderboard,
        endGame
    };

    class State {

    private:
        StateMachine* pSM;
        stateID id;

    public:
        State(StateMachine* pSM = nullptr, States::stateID id = unknown);

        virtual ~State();

        void setStateMachine(StateMachine* pSM);

        void changeState(States::stateID id);

        States::stateID getID() const;

        virtual void update(float dt) = 0;

        virtual void render() = 0;

        virtual void resetState() = 0;
    };

}
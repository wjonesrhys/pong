#pragma once
#include <iostream>
#include <util.hpp>
#include <gameengine.hpp>

class GameEngine;

/**
 * A Virtual class used for contract purposes amongst the game states.
*/
class State {
    private:
        std::string stateName;

    // would be protected if actually used by other states
    protected:
        State(std::string getStateName);

    public:
        virtual ~State();

        virtual void onEnter();

        virtual void handleEvents();
        virtual void update();
        virtual void render();

        virtual void pause();
        virtual void resume();

        virtual void onExit();
        
        std::string getStateName();
};
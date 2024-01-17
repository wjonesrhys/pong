#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <state.hpp>
#include <menu.hpp>

class GameEngine;

class PauseState : public State {
    private:
        GameEngine* gameEngine;
        Menu menu;
        bool isActive;

    public:
        PauseState(GameEngine* gameEngine);
        ~PauseState();
        
        void onEnter() override;

        void handleEvents() override;
        void update() override;
        void render() override;

        void pause() override;
        void resume() override;

        void onExit() override; 
        
        void returnToGame();
};

#endif
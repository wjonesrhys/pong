#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <state.hpp>
#include <menu.hpp>
#include <gameengine.hpp>

class MainMenuState : public State {
    private:
        Menu menu;

    public:
        GameEngine* gameEngine;

        MainMenuState(GameEngine* gameEngine);
        ~MainMenuState();
        
        void onEnter() override;

        void handleEvents() override;
        void update() override;
        void render() override;

        void pause() override;
        void resume() override;

        void onExit() override; 
};

#endif
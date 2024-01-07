#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <state.hpp>
#include <menu.hpp>
#include <gameengine.hpp>

class PauseState : public State {
    private:
        GameEngine* gameEngine;
        Menu menu;

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
};
#ifndef ABOUTSTATE_H
#define ABOUTSTATE_H

#include <state.hpp>
#include <menu.hpp>
#include <gameengine.hpp>

class AboutState : public State {
    private:
        Menu menu;

    public:
        GameEngine* gameEngine;

        AboutState(GameEngine* gameEngine);
        ~AboutState();
        
        void onEnter() override;

        void handleEvents() override;
        void update() override;
        void render() override;

        void pause() override;
        void resume() override;

        void onExit() override; 
};

#endif
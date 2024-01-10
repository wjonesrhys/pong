#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include <state.hpp>
#include <gameengine.hpp>
#include <menu.hpp>
#include <player.hpp>
#include <ball.hpp>
#include <score.hpp>
#include <collision.hpp>

class PlayState : public State {
    private:
        GameEngine* gameEngine;
        Menu menu;
        bool paused;

        Collision collision;
        sf::Clock clock;
        float dt;

        sf::Font font;
        std::vector<Score*> scores;
        std::vector<Player*> players;
        std::vector<Ball*> balls;

    public:
        PlayState(GameEngine* gameEngine);
        ~PlayState();

        void onEnter() override;

        void handleEvents() override;
        void update() override;
        void render() override;

        void pause() override;
        void resume() override;

        void onExit() override; 

        void adjustScore(std::vector<sf::Vector2i> results);

        void setUpEntities();        
        void setIcon();

        void moveEntities(float dt);
        void drawEntities();
        void destroyEntities();

        void updateGame(float dt);
};
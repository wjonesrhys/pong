#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include <state.hpp>
#include <statemachine.hpp>
#include <menu.hpp>
#include <player.hpp>
#include <ball.hpp>
#include <score.hpp>
#include <collision.hpp>

class PlayState : public State {
    private:
        StateMachine& stateMachine;
        sf::RenderWindow& window;
        Menu menu;

        Collision collision;
        sf::Clock clock;
        float dt;

        sf::Font font;
        std::vector<Score*> scores;
        std::vector<Player*> players;
        std::vector<Ball*> balls;

    public:
        PlayState(sf::RenderWindow& renderWindow, StateMachine& stateMachine);
        ~PlayState();
        
        void onEnter() override;
        void onExit() override;
        void update() override;
        void render() override;

        void adjustScore(std::vector<sf::Vector2i> results);

        void setUpEntities();        
        void setIcon();

        void moveEntities(float dt);
        void drawEntities();
        void destroyEntities();

        void updateGame(float dt);
};
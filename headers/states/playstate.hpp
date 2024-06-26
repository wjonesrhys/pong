#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <state.hpp>
#include <menu.hpp>
#include <player.hpp>
#include <ball.hpp>
#include <rectangle.hpp>
#include <score.hpp>
#include <collision.hpp>
#include <gameengine.hpp>

class PlayState : public State {
    private:
        GameEngine* gameEngine;
        Menu menu;
        bool paused;

        sf::Clock clock;
        float dt;

        sf::Font font;
        
        std::vector<Score*> scores;
        std::vector<Player*> players;
        std::vector<Ball*> balls;
        std::vector<Rectangle*> rectangles;

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

        void moveEntities(float dt);
        void drawEntities();
        void destroyEntities();

        void updateGame(float dt);
};

#endif
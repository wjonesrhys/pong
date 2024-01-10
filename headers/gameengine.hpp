#pragma once
#include <iostream>
#include <util.hpp>
#include <state.hpp>

class State;

class GameEngine {
    private:
        std::vector<State*> stacked_states;
        bool running;

    public:
        sf::RenderWindow& window;
        sf::Event event;

        GameEngine(sf::RenderWindow& window);
        ~GameEngine();
        
        void handleEvents();
        void update();
        void render();

        void pushWithoutPop(State* state);
        void push(State* state);
        void pop();

        void clear();
        void close(); 

        void printStates();
        bool isRunning();
};

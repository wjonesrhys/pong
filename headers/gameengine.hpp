#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <state.hpp>
#include <SFML/Graphics.hpp>

class State;

class GameEngine {
    private:
        std::vector<State*> stacked_states;
        State* previousState;
        State* currentState;
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

        State* getPreviousState();

        void clear();
        void close(); 

        void printStates();
        bool isRunning();
};

#endif
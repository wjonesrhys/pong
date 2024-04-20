#include <iostream>
#include "gameengine.hpp"
#include "mainmenustate.hpp"

GameEngine::GameEngine(sf::RenderWindow& window) : window(window) {
    std:: cout << "game engine started!" << std::endl;

    // set main menu as the start state
    push(new MainMenuState(this));

    currentState = nullptr;
    previousState = nullptr;

    // set the game to running
    this->running = true;
}

GameEngine::~GameEngine() {
    //delete all states here?
    clear();

    delete currentState;
    delete previousState;
    std:: cout << "game engine ended!" << std::endl;
}

void GameEngine::handleEvents() {
    // std::cout << "handling events");
    while (window.pollEvent(event)) {
        for (State* state : stacked_states) {
            state->handleEvents();
        }
    }
}

void GameEngine::render() {
    for (State* state : stacked_states) {
        // std::cout << "rendering " + state->getStateName());
        state->render();
    }
}

void GameEngine::update() {
    for (State* state : stacked_states) {
        // std::cout << "updating" + state->getStateName());
        state->update();
    }
}

void GameEngine::pushWithoutPop(State* state) {

    previousState = stacked_states.back();
    currentState = state;

    stacked_states.push_back(state);
    for (State* state : stacked_states) {
        std::cout << state->getStateName() << std::endl;
    }

    state->onEnter();
}

void GameEngine::push(State* state) {
    if (stacked_states.size() != 0) {
        previousState = stacked_states.back();
        currentState = state;
        stacked_states.pop_back();
    }
    stacked_states.push_back(state);
    state->onEnter();
}

void GameEngine::pop() {
    if (!stacked_states.empty()) {
        previousState = stacked_states.back();
        std::cout << "state name: " << stacked_states.back()->getStateName() << std::endl;
        stacked_states.back()->onExit();
        stacked_states.pop_back();
        if (!stacked_states.empty()) {
            currentState = stacked_states.back();
        }
        stacked_states.back()->onEnter();
    }
}

State* GameEngine::getPreviousState() {
    return previousState;
}


void GameEngine::clear() {
    // very useful when you have hanging states (play when pause exit is called)
    // loop through all states to clear memory issues
    for (State* state : stacked_states) {
        state->onExit();
    }
    // clear up all states
    stacked_states.clear();
}

void GameEngine::printStates() {
    std:: cout << "------ states loaded: ------" << std::endl;
    for (State* state : stacked_states) {
        std:: cout << state->getStateName() << std::endl;
    }
    std:: cout << "----------------------------" << std::endl;
}

void GameEngine::close() {
    this->running = false;
}

bool GameEngine::isRunning() {
    return this->running;
}
#include "gameengine.hpp"
#include "mainmenustate.hpp"

GameEngine::GameEngine(sf::RenderWindow& window) : window(window) {
    print("game engine started!");

    // set main menu as the start state
    push(new MainMenuState(this));

    currentState = nullptr;
    previousState = nullptr;

    // set the game to running
    this->running = true;
}

GameEngine::~GameEngine() {
    //delete all states here?
    print("game engine ended!");
}

void GameEngine::handleEvents() {
    // print("handling events");
    while (window.pollEvent(event)) {
        for (State* state : stacked_states) {
            state->handleEvents();
        }
    }
}

void GameEngine::render() {
    for (State* state : stacked_states) {
        // print("rendering " + state->getStateName());
        state->render();
    }
}

void GameEngine::update() {
    for (State* state : stacked_states) {
        // print("updating" + state->getStateName());
        state->update();
    }
}

void GameEngine::pushWithoutPop(State* state) {
    previousState = stacked_states.back();
    currentState = state;

    stacked_states.push_back(state);
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
    //loop over states and clear up memory issues
    stacked_states.clear();
}

void GameEngine::printStates() {
    print("------ states loaded: ------");
    for (State* state : stacked_states) {
        print(state->getStateName());
    }
    print("----------------------------");
}

void GameEngine::close() {
    
    this->running = false;
}

bool GameEngine::isRunning() {
    return this->running;
}
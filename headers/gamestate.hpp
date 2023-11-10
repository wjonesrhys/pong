#pragma once
#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include <state.hpp>

#include <iostream>
#include <vector>

class GameState : public State {
public:
    GameState() {
        setStateName("State B");
    }

    void enter() {
        print("i");
        // Additional actions when entering State B
    }

    void exit() override {
        State::exit();
        // Additional actions when exiting State B
    }

    void update() override {
        State::update();
        // Additional actions when updating State B
    }
=======
#include <iostream>
#include <vector>

class GameState {
    private:

    public:
        void update();

>>>>>>> a6da76c (fix issues?)
};
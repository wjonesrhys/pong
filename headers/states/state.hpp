#ifndef STATE_H
#define STATE_H

#include <string>
/**
 * A virtual class use for all game states.
*/
class State {
    private:
        std::string stateName;

    // would be protected if actually used by other states
    protected:
        State(std::string getStateName);

    public:
        virtual ~State();

        virtual void onEnter();

        virtual void handleEvents();
        virtual void update();
        virtual void render();

        virtual void pause();
        virtual void resume();

        virtual void onExit();
        
        std::string getStateName();
};

#endif
#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>
#include "State.h"
#include "HistoryIterator.h"

class StateManager {
private:
    State* currentState;
    std::vector<State*> history;
    HistoryIterator* iterator;

    void storeCurrentState();

public:
    StateManager();
    ~StateManager();

    void setState(State* s);
    void restorePrevious();
    void restoreNext();
    HistoryIterator* getHistoryIterator();
};

#endif

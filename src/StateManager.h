#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>
#include "State.h"
#include "HistoryIterator.h"
#include "IStateManager.h"

class StateManager : public IStateManager {
private:
    State* currentState;
    std::vector<State*> history;
    HistoryIterator* iterator;

    void storeCurrentState();

public:
    StateManager();
    ~StateManager();

    IState* getCurrentState() override;

    void setState(State* s) override;
    void restorePrev() override;
    void restoreNext() override;
    HistoryIterator* getHistoryIterator();
};

#endif

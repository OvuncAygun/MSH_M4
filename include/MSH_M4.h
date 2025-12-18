#pragma once

#include "IStateManager.h"

#include <vector>

class MSH_M4 {
public:
    MSH_M4();
    ~MSH_M4();

    void initializeStates();
    void initializeStateManager();

    std::vector<IState*> getStates();
    IStateManager* getStateManager();

private:
    IStateManager* stateManager;
    std::vector<IState*> states;
};
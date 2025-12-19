#include "MSH_M4.h"
#include "State.h"
#include "StateManager.h"

MSH_M4::MSH_M4() = default;
MSH_M4::~MSH_M4() = default;

void MSH_M4::initializeStates() {
    Normal* normal = new Normal();
    HighPerformance* highPerf = new HighPerformance();
    LowPower* lowPower = new LowPower();
    Sleep* sleep = new Sleep();

    states.push_back(normal);
    states.push_back(highPerf);
    states.push_back(lowPower);
    states.push_back(sleep);
}

void MSH_M4::initializeStateManager() {
    stateManager = new StateManager();
    stateManager->setState(new Normal());
    static_cast<StateManager*>(stateManager)->getHistoryIterator();
}

IStateManager* MSH_M4::getStateManager() {
    return stateManager;
}

std::vector<IState*> MSH_M4::getStates() {
    return states;
}
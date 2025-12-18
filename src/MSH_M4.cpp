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

    states[0] = normal;
    states[1] = highPerf;
    states[2] = lowPower;
    states[3] = sleep;
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
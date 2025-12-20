#include "StateManager.h"
#include "ConcreteHistoryIterator.h"

StateManager::StateManager()
    : currentState(0) {
    iterator = new ConcreteHistoryIterator(history);
}

StateManager::~StateManager() {
    delete iterator;

    bool currentInHistory = false;
    for (State* s : history) {
        if (s == currentState) {
            currentInHistory = true;
            break;
        }
    }

    for (State* s : history) {
        delete s;
    }
    history.clear();

    if (currentState && !currentInHistory) {
        delete currentState;
    }
}

IState* StateManager::getCurrentState(){
    return currentState;
}

void StateManager::storeCurrentState() {
    if (currentState) {
        iterator->addState(currentState);
    }
}

void StateManager::setState(IState* s) {
    currentState = static_cast<State*>(s);
    storeCurrentState();
    currentState->apply();
}

void StateManager::restorePrev() {
    if (iterator && iterator->hasPrevious()) {
        currentState = iterator->previous();
        currentState->apply();
    }
}

void StateManager::restoreNext() {
    if (iterator && iterator->hasNext()) {
        currentState = iterator->next();
        currentState->apply();
    }
}

HistoryIterator* StateManager::getHistoryIterator() {
    return iterator;
}

#include "StateManager.h"
#include "ConcreteHistoryIterator.h"

StateManager::StateManager()
    : currentState(nullptr), iterator(nullptr) {}

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

void StateManager::storeCurrentState() {
    if (currentState) {
        history.push_back(currentState);
    }
}

void StateManager::setState(State* s) {
    storeCurrentState();
    currentState = s;
    currentState->apply();
}

void StateManager::restorePrevious() {
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
    delete iterator;
    iterator = new ConcreteHistoryIterator(history);
    return iterator;
}

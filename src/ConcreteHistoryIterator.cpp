#include "ConcreteHistoryIterator.h"

ConcreteHistoryIterator::ConcreteHistoryIterator(std::vector<State*>& h)
    : historyRef(h), index(h.empty() ? -1 : (int)h.size() - 1) {}

bool ConcreteHistoryIterator::hasNext() {
    return index + 1 < (int)historyRef.size();
}

State* ConcreteHistoryIterator::next() {
    if (hasNext()) {
        index++;
        return historyRef[index];
    }
    return 0;
}

bool ConcreteHistoryIterator::hasPrevious() {
    return index > 0;
}

State* ConcreteHistoryIterator::previous() {
    if (hasPrevious()) {
        index--;
        return historyRef[index];
    }
    return 0;
}

void ConcreteHistoryIterator::addState(State* state) {
    if (index + 1 < (int)historyRef.size()) {
        
        historyRef.erase(historyRef.begin() + index + 1, historyRef.end());
    }
    historyRef.push_back(state);
    index = ((int)historyRef.size()) - 1;
}
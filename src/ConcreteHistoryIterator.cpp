#include "ConcreteHistoryIterator.h"

ConcreteHistoryIterator::ConcreteHistoryIterator(std::vector<State*>& h)
    : historyRef(h), index(h.size()) {}

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
    return index - 1 >= 0;
}

State* ConcreteHistoryIterator::previous() {
    if (hasPrevious()) {
        index--;
        return historyRef[index];
    }
    return 0;
}

void ConcreteHistoryIterator::addState(State* state) {
    if (index < (int)historyRef.size() - 1) {
        
        for (size_t i = index + 1; i < historyRef.size(); ++i) {
            delete historyRef[i]; 
        }
        
        historyRef.erase(historyRef.begin() + index + 1, historyRef.end());
    }
    historyRef.push_back(state);
    index = historyRef.size() - 1;
}
#include "ConcreteHistoryIterator.h"

ConcreteHistoryIterator::ConcreteHistoryIterator(std::vector<State*>& h)
    : historyRef(h), index(h.size() - 1) {}

bool ConcreteHistoryIterator::hasNext() {
    return index + 1 < (int)historyRef.size();
}

State* ConcreteHistoryIterator::next() {
    if (hasNext()) {
        index++;
        return historyRef[index];
    }
    return nullptr;
}

bool ConcreteHistoryIterator::hasPrevious() {
    return index - 1 >= 0;
}

State* ConcreteHistoryIterator::previous() {
    if (hasPrevious()) {
        index--;
        return historyRef[index];
    }
    return nullptr;
}

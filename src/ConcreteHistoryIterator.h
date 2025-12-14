#ifndef CONCRETE_HISTORY_ITERATOR_H
#define CONCRETE_HISTORY_ITERATOR_H

#include "HistoryIterator.h"
#include <vector>

class ConcreteHistoryIterator : public HistoryIterator {
private:
    std::vector<State*>& historyRef;
    int index;

public:
    ConcreteHistoryIterator(std::vector<State*>& h);

    bool hasNext() override;
    State* next() override;
    bool hasPrevious() override;
    State* previous() override;
};

#endif

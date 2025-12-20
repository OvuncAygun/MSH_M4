#ifndef HISTORY_ITERATOR_H
#define HISTORY_ITERATOR_H

#include "State.h"

class HistoryIterator {
public:
    virtual ~HistoryIterator() {}
    virtual bool hasNext() = 0;
    virtual State* next() = 0;
    virtual bool hasPrevious() = 0;
    virtual State* previous() = 0;
    virtual void addState(State* state) = 0;
};

#endif

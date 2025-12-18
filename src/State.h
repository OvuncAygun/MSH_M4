#ifndef STATE_H
#define STATE_H

#include "IState.h"

#include <string>

// =============================
// Abstract State
// =============================
class State : public IState {
protected:
    std::string name;

public:
    State(const std::string& n);
    virtual ~State();

    virtual void apply() = 0;
    std::string getName() const override;
};

// =============================
// Concrete States
// =============================
class Normal : public State {
public:
    Normal();
    void apply() override;
};

class HighPerformance : public State {
public:
    HighPerformance();
    void apply() override;
};

class LowPower : public State {
public:
    LowPower();
    void apply() override;
};

class Sleep : public State {
public:
    Sleep();
    void apply() override;
};

#endif

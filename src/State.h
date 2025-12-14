#ifndef STATE_H
#define STATE_H

#include <string>

// =============================
// Abstract State
// =============================
class State {
protected:
    std::string name;

public:
    State(const std::string& n);
    virtual ~State();

    virtual void apply() = 0;
    std::string getName() const;
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

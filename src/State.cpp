#include "State.h"
#include <iostream>

// =============================
// State base
// =============================
State::State(const std::string& n) : name(n) {}

State::~State() {}

std::string State::getName() const {
    return name;
}

// =============================
// Concrete States
// =============================
Normal::Normal() : State("Normal") {}

void Normal::apply() {
    std::cout << "[State] Normal applied\n";
}

HighPerformance::HighPerformance()
    : State("HighPerformance") {}

void HighPerformance::apply() {
    std::cout << "[State] High Performance applied\n";
}

LowPower::LowPower() : State("LowPower") {}

void LowPower::apply() {
    std::cout << "[State] Low Power applied\n";
}

Sleep::Sleep() : State("Sleep") {}

void Sleep::apply() {
    std::cout << "[State] Sleep applied\n";
}

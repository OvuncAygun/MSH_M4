#pragma once

#include "IState.h"

class IStateManager {
public:
    virtual ~IStateManager() = default;

    virtual IState* getCurrentState() const = 0;

    virtual void setState(const IState& state) = 0;

    virtual void restorePrev() = 0;
    virtual void restoreNext() = 0;
};
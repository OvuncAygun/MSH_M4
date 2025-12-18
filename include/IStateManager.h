#pragma once

#include "IState.h"

class IStateManager {
public:
    virtual ~IStateManager() = default;

    virtual IState* getCurrentState() = 0;

    virtual void setState(IState* s) = 0;

    virtual void restorePrev() = 0;
    virtual void restoreNext() = 0;
};
#pragma once
#include "Die.h"

/*This is the header file for the NumberDie derrived class*/

class NumberDie :
    public Die
{
    //Member functions
    std::string roll();
    std::string getFaces();
};


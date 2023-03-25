#pragma once
#include "Die.h"

/*This is the header file for the derived class: SpecialDie*/

class SpecialDie :
    public Die
{
    //member functions - both are virtual and will be overwritten
    std::string roll(); 
    std::string getFaces(); 
};


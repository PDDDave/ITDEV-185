#pragma once
#include "Item.h"
class FreshProduce :
    public Item
{
    private:
        double pounds = 0.0;
    public:
        FreshProduce(std::string name, double price, double pounds, bool pickup);
        void calcPrice();
        double getPounds();
        void setPounds(double);
        
};


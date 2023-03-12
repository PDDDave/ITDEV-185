#pragma once
#include "Item.h"
//MeasuredProduct Header file
class MeasuredProduct :
    public Item
{
    private:
        int quantity = 0;
    public:
        MeasuredProduct(std::string name, double price, int quantity, bool pickup);
        void calcPrice();
        int getQuantity();
        void setQuantity(int);
};


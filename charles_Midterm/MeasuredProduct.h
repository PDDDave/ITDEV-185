#pragma once
#include "Item.h"

//This is the header file for the MeasuredProduct derived class

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


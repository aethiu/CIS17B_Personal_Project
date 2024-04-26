/*
 * File:   Item.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:36 AM
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
private:
    unsigned int sku = 0;
    unsigned long stock;
    std::string name;
    std::string description;
    std::string img;
    float price = 0.0f;
};

#endif /* ITEM_H */


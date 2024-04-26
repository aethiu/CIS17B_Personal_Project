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
    Item() =default;
    Item(unsigned int sku,
         unsigned long quantity,
         std::string name,
         std::string description,
         float price);

    unsigned int get_sku() const noexcept { return sku_; };
    unsigned long get_quantity() const noexcept { return quantity_; };
    std::string get_name() const noexcept { return name_ ;}
    std::string get_description() const noexcept { return description_ ;}
    float get_price() const noexcept { return price_; };

private:
    unsigned int sku_ = 0;
    unsigned long quantity_;
    std::string name_;
    std::string description_;
    std::string img_;
    float price_ = 0.0f;
};

#endif /* ITEM_H */


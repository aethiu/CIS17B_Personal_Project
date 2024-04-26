/*
 * File:   Cart.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:59 AM
 */

#ifndef CART_H
#define CART_H

#include "Item.h"

class Cart {
public:
    void add_item(Item* item);
    void remove_item(Item* item);

private:
    struct CartItem {
        Item *item;
        size_t quantity;
    };

    CartItem *items_;
    size_t quantity_;
    float subtotal_;

    void update_total();
};

#endif /* CART_H */


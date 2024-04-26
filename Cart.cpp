/*
 * File:   Cart.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 10:59 AM
 */

#include "Cart.h"

void Cart::add_item(Item* item) { }

void Cart::remove_item(Item* item) { }

void Cart::update_total() {
    float subtotal=0;
    for (size_t i=0; i<quantity_; i++) {
        subtotal += items_[i].item->get_price();
    }
    subtotal_ = subtotal;
}

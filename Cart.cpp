/*
 * File:   Cart.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 10:59 AM
 */

#include "Cart.h"

Cart::Cart(ItemService &item_service) : item_service_(&item_service) { }

void Cart::add_item(const Item* item) {
    if (item == nullptr) return;
    items_.push_back(item);
}

const Item* Cart::remove_item(const Item* item) {
    for (auto i=items_.begin(); i != items_.end(); i++) {
        if ((*i)->get_sku() == item->get_sku()) {
            const Item* removed = *i;
            items_.erase(i);
            return removed;
        }
    }
    return nullptr;
}

float Cart::get_subtotal() const noexcept {
    float subtotal = 0.0f;
    for (const auto& item : items_) {
        subtotal += item->get_price();
    }
    return subtotal;
}

/*
 * File:   Cart.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 10:59 AM
 */

#include "Cart.h"

void Cart::add_item(Item* item) {
    items_[item->get_sku()]++;
    update_total();
}

void Cart::remove_item(const Item* item) {
    if (items_.count(item->get_sku()) == 0) return; // Item not in cart
    if (items_[item->get_sku()] == 1) {
        items_.erase(item->get_sku()); // Remove from cart
    } else {
        items_[item->get_sku()] -= 1; // Decrement quantity in cart
    }
}

Item** Cart::get_items() const {
    size_t size = items_.size();
    Item **items = new Item*[size];
    size_t i = 0;
    for (const auto& [sku, quantity] : items_) {
        items[i++] = item_service_->get_item(sku);
    }
    return items;
}

void Cart::update_total() {
    float subtotal=0;
    for (const auto& [sku, quantity] : items_) {
        subtotal_ += item_service_->get_item(sku)->get_price() * quantity;
    }
    subtotal_ = subtotal;
}

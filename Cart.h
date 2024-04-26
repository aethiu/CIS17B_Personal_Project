/*
 * File:   Cart.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:59 AM
 */

#ifndef CART_H
#define CART_H

#include <unordered_map>

#include "ItemService.h"

class Cart {
public:
    Cart(ItemService *item_service) : item_service_(item_service) { }
    void add_item(Item* item);
    void remove_item(const Item* item);

    Item** get_items() const;
    size_t get_total_items() const { return items_.size(); }

private:
    ItemService *item_service_;
    std::unordered_map<unsigned int, unsigned long> items_; // key=sku, value=quantity
    float subtotal_;

    void update_total();
};

#endif /* CART_H */


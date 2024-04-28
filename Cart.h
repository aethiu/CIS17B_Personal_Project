/*
 * File:   Cart.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:59 AM
 */

#ifndef CART_H
#define CART_H

#include <vector>

#include "ItemService.h"

class Cart {
public:
    Cart(ItemService *item_service);

    void add_item(const Item* item);
    const Item* remove_item(const Item* item);

    const std::vector<const Item*>& get_items() const { return items_; }
    size_t get_num_items() const { return items_.size(); }
    float get_subtotal();

private:
    ItemService *item_service_;
    std::vector<const Item*> items_;
};

#endif /* CART_H */


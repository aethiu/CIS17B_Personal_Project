/*
 * File:   ItemService.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 11:57 AM
 */

#include "ItemService.h"

ItemService::ItemService() {
  add_item(new Item(1, 20, 12.99, "Test Item 1", "Test Item 1 Description"));
  add_item(new Item(2, 111, 0.01, "Test Item 2", "Test Item 2 Description"));
  add_item(new Item(3, 62, 99.99, "Test Item 3", "Test Item 3 Description"));
}

Item* ItemService::get_item(unsigned int sku) const {
    for (size_t i=0; i<num_items_; i++) {
        if (items_[i]->get_sku() == sku) return items_[i];
    }
    return nullptr;
}

void ItemService::add_item(Item *item) {
    items_.push_back(item);
    num_items_ = items_.size();
}

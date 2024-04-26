/*
 * File:   ItemService.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 11:57 AM
 */

#include "ItemService.h"

Item* ItemService::get_item(unsigned int sku) const {
    for (size_t i=0; i<num_items_; i++) {
        if (items_[i]->get_sku() == sku) return items_[i];
    }
    return nullptr;
}
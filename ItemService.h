/*
 * File:   ItemService.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 11:57 AM
 */

#ifndef ITEMSERVICE_H
#define ITEMSERVICE_H

#include "Item.h"

class ItemService {
public:
    ItemService() =default;
    ItemService(Item** items, size_t size) : items_(items), num_items_(size) { }
    virtual ~ItemService() =default;
    virtual Item* get_item(unsigned int sku) const;
protected:
    size_t num_items_ = 0;
private:
    Item **items_;
};

#endif /* ITEMSERVICE_H */


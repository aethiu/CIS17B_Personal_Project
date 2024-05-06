/*
 * File:   ItemService.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 11:57 AM
 */

#ifndef ITEMSERVICE_H
#define ITEMSERVICE_H

#include "Item.h"
#include "ItemRepository.h"

#include <vector>

class ItemService {
public:
    ItemService(ItemRepository& repo) : repo_(repo);
    virtual ~ItemService() =default;
    virtual const Item* get_item(unsigned int sku) const { return repo_.read_item(sku); }
    virtual void add_item(Item *item);

private:
    ItemRepository& repo_;
};

#endif /* ITEMSERVICE_H */


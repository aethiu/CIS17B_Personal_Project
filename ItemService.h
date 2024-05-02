/*
 * File:   ItemService.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 11:57 AM
 */

#ifndef ITEMSERVICE_H
#define ITEMSERVICE_H

#include "Item.h"

#include <vector>

class ItemService {
public:
    ItemService() =default;
    virtual ~ItemService() =default;
    virtual Item* get_item(unsigned int sku) const;
    virtual void add_item(Item *item);

protected:
    size_t num_items_ = 0;

private:
    std::vector<Item*> items_;
};

#endif /* ITEMSERVICE_H */


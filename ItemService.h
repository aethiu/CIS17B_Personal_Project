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
    ItemService();
//    ItemService(ItemRepository &repo) : repo_(repo) { }
    virtual ~ItemService() =default;
    virtual const std::vector<Item*>& get_items() noexcept { return items_; };
    virtual Item* get_item(unsigned int sku) const;
//    virtual const Item* get_item(unsigned int sku) const { return repo_.read_item(sku); }
    virtual void add_item(Item *item);

protected:
  size_t num_items_ = 0;

private:
//    ItemRepository& repo_;
    std::vector<Item*> items_;
};

#endif /* ITEMSERVICE_H */


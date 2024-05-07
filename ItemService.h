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
    ItemService(ItemRepository &repo) : repo_(repo) { }

    std::vector<const Item*> get_all_items() const { return std::move(repo_.read_table()); }

    const Item* get_item(unsigned int sku) const { return repo_.read_row(sku); }

    void add_item(const Item &item);

private:
    ItemRepository& repo_;
};

#endif /* ITEMSERVICE_H */


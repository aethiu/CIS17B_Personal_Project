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
    const Item* add_item(const Item &item) { return repo_.create_row(item.get_sku(), item); }
    void remove_item(unsigned int sku) { repo_.delete_row(sku); }
    const Item* update_item(const Item& item) { return repo_.update_row(item.get_sku(), item); }

private:
    ItemRepository& repo_;
};

#endif /* ITEMSERVICE_H */


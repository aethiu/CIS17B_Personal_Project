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

    /** \brief Returns an array of all the items in the catalog
     *
     * @return vector of items
     */
    std::vector<const Item*> get_all_items() const { return std::move(repo_.read_all_items()); }

    const Item* get_item(unsigned int sku) const { return repo_.read_item(sku); }

    void add_item(const Item &item);

private:
    ItemRepository& repo_;
};

#endif /* ITEMSERVICE_H */


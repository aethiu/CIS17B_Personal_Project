/*
 * File:   Cart.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:59 AM
 */

#ifndef CART_H
#define CART_H

#include "Item.h"

#include <vector>

class Cart {
public:
    /** \brief Adds an item to the cart.
     *
     * Returns immediately if item is nullptr.
     * @param item Item to add to the cart
     */
    void add_item(const Item* item);

    /** \brief Removes an item from the cart.
     *
     * Returns nullptr if item is not in the cart.
     * @param item Item to remove from the cart
     * @return Removed item or nullptr if no item was removed
     */
    const Item* remove_item(const Item* item);

    const std::vector<const Item*>& get_items() const noexcept { return items_; }
    size_t get_num_items() const noexcept { return items_.size(); }
    float get_subtotal() const noexcept;

private:
    std::vector<const Item*> items_;
};

#endif /* CART_H */


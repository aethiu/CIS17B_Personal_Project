/*
 * File:   Cart.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:59 AM
 */

#ifndef CART_H
#define CART_H

#include "Item.h"

#include <map>
#include <vector>

/** \brief Shopping cart
 *
 */
class Cart {
public:
    /** \brief Adds an item to the cart or increase an quantity of an item in the cart.
     *
     * Returns immediately if item is nullptr.
     *
     * @param item Item to add to the cart
     */
    void add_item(const Item*);

    /** \brief Removes an item from the cart.
     *
     * Returns nullptr if item is not in the cart.
     *
     * @param item Item to remove from the cart
     * @return Item removed from cart or nullptr if no item was removed
     */
    const Item* remove_item(const Item* item);

    /** \brief Set the quantity of an item
     *
     * Does not remove an item from the cart if the quantity is set to 0
     * Returns immediately if item is nullptr
     *
     * @param item
     * @param quantity
     * @return Updated quantity or 0 if item was not found
     */
    unsigned long set_quantity(const Item* item, unsigned long quantity);
    unsigned long set_quantity(unsigned int sku, unsigned long quantity);

    //! Get the quantity of an item in the cart
    unsigned long get_quantity(const Item* item) const { return get_quantity(item->get_sku()); }
    unsigned long get_quantity(unsigned int sku) const;

    //! Get a map of SKUs that maps an item's SKU to the quantity of the item in the cart.
    const std::map<unsigned int, unsigned long>& get_quantities() const noexcept { return quantities_; }

    /** \brief Get the items in the cart
     *
     * Each item is unique, i.e. quantity of each item in the cart cannot be deduced from the returned vector.
     * To get the quantity of each item, use Cart::get_quantities
     *
     * @return Vector of items in cart
     */
    const std::vector<const Item*>& get_items() const noexcept { return items_; }

    //! Get the total number of items in the cart, e.g. sum of the quantities
    size_t get_num_items() const noexcept;

    float get_subtotal() const noexcept;

private:
  std::vector<const Item*> items_;
  // Keep separate quantity map because PHP maps can't use const Item* pointers as keys like C++
  std::map<unsigned int, unsigned long> quantities_;
};

#endif /* CART_H */


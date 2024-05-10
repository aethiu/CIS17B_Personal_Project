/*
 * File:   Order.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 11:03 AM
 */

#ifndef ORDER_H
#define ORDER_H

#include "Cart.h"
#include "User.h"

#include <map>

class Order {
public:
    using OrderNum = unsigned long;

    Order() =default;

    /** \brief Constructs an order
     *
     * Clients should use OrderService::create_order() rather than calling this constructor directly.
     *
     * @param order_number
     * @param user
     * @param subtotal
     * @param date
     * @param items
     */
    Order(OrderNum order_number, unsigned int user_id, float subtotal, float tax, float shipping, float total, const std::string date, std::map<unsigned int, unsigned long> items);

    OrderNum get_order_num() const noexcept { return order_num_; }
    //! Returns the user that created the order
    const unsigned int get_user_id() const noexcept { return user_id_; }
    //! Returns the items in the order as a map of SKUs to quantities
    const std::map<unsigned int, unsigned long>& get_items() const { return items_; }
    //! Returns the subtotal
    float get_subtotal() const noexcept { return subtotal_; }
    //! Returns the tax
    float get_tax() const noexcept { return tax_; }
    //! Returns the shipping
    float get_shipping() const noexcept { return tax_; }
    //! Returns the calculated total
    float get_total() const noexcept { return total_; }
    //! Returns the ISO 8601 formatted date that the order was created
    std::string get_date() const noexcept { return date_; }

    bool operator==(OrderNum order_num) const { return order_num_ == order_num; }

private:

    OrderNum order_num_ = -1;
    unsigned int user_id_ = 0;
    float subtotal_ = 0.0f, tax_ = 0.0f, shipping_ = 0.0f, total_ = 0.0f;
    std::string date_ = "YYYY-mm-ddTHH:MM:SS"; // ISO 8601 format in UTC
    std::map<unsigned int, unsigned long> items_; // std::map has a copy assignment overload, but std::unordred_map's is deleted
};

#endif /* ORDER_H */


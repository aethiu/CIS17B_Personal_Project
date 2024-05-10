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

#include <unordered_map>

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
    Order(OrderNum order_number, const User &user, float subtotal, std::string date, const std::unordered_map<unsigned int, unsigned long>& items);

    //! Returns tax that was added to total
    float get_tax() const noexcept { return subtotal_*tax_rate_; }
    //! Returns shipping fee
    static float get_shipping_cost() noexcept { return shipping_cost_; }

    OrderNum get_order_num() const noexcept { return order_num_; }
    //! Returns the user that created the order
    const User* get_user() const noexcept { return user_; }
    //! Returns the items in the order as a map of SKUs to quantities
    const std::unordered_map<unsigned int, unsigned long>& get_items() const { return items_; }
    //! Returns the subtotal
    float get_subtotal() const noexcept { return subtotal_; }
    //! Returns the calculated total
    float get_total() const noexcept { return subtotal_+get_tax()+get_shipping_cost(); }
    //! Returns the ISO 8601 formatted date that the order was created
    std::string get_data() const noexcept { return date_; }

    bool operator==(OrderNum order_num) const { return order_num_ == order_num; }

private:
    static constexpr float tax_rate_ = 0.07f;
    static constexpr float shipping_cost_ = 10.00f;

    OrderNum order_num_ = -1;
    const User *user_ = nullptr;
    float subtotal_ = 0.0f;
    std::string date_ = "YYYY-mm-ddTHH:MM:SS"; // ISO 8601 format in UTC
    const std::unordered_map<unsigned int, unsigned long> items_;
};

#endif /* ORDER_H */


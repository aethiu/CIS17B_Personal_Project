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
     * @param cart
     */
    Order(OrderNum order_number, const User &user, const Cart &cart);

    //! Returns tax that was added to total
    float get_tax() const noexcept { return cart_->get_subtotal()*tax_rate_; }
    //! Returns shipping fee
    static float get_shipping_cost() noexcept { return shipping_cost_; }

    OrderNum get_order_num() const noexcept { return order_num_; }
    //! Returns the user that created the order
    const User* get_user() const noexcept { return user_; }
    //! Returns the cart used to create the order
    const Cart* get_cart() const noexcept { return cart_; }
    //! Returns the calculated total
    float get_total() const noexcept { return total_; }
    //! Returns the ISO 8601 formatted date that the order was created
    std::string get_data() const noexcept { return date_; }

    bool operator==(OrderNum order_num) const { return order_num_ == order_num; }

private:
    static constexpr float tax_rate_ = 0.07f;
    static constexpr float shipping_cost_ = 10.00f;

    OrderNum order_num_ = -1;
    const User *user_;
    float total_;
    std::string date_ = "YYYY-mm-ddTHH:MM:SS"; // ISO 8601 format in UTC
    const Cart *cart_;

    float calculate_total(float subtotal) const noexcept;
};

#endif /* ORDER_H */


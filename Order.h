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
    Order(const Cart *cart, const User *user);
private:
    static constexpr float tax_rate_ = 0.07f;
    static constexpr float shipping_cost = 10.00f;

    const Cart *cart_;
    float total_;
    std::string date_;
    User *user_;
};

#endif /* ORDER_H */


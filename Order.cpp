/*
 * File:   Order.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 11:03 AM
 */

#include "Order.h"

#include <utility>

Order::Order(OrderNum order_num, const User &user, float subtotal, std::string date, const std::unordered_map<unsigned int, unsigned long>& items)
        : user_(&user)
        , subtotal_(subtotal)
        , date_(std::move(date))
        , items_(items) {
}

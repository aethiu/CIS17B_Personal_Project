/* 
 * File:   OrderService.h
 * Author: Theopolis Armstrong
 *
 * Created on May 6, 2024, 10:03 PM
 */

#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "ItemService.h"
#include "Order.h"
#include "OrderRepository.h"

class OrderService {
public:
    OrderService(OrderRepository& repository, const ItemService &item_service)
    : item_service_(item_service)
    , repo_(repository)
    { }

    //! Returns tax rate
    float get_tax_rate() const noexcept { return tax_rate_; }
    //! Returns shipping fee
    float get_shipping_cost() noexcept { return shipping_cost_; }

    Order create_order(const User&, const Cart&);

    Order::OrderNum get_new_order_num() const;

    const Order* submit_order(const Order&);

private:
    static constexpr float tax_rate_ = 0.07f;
    static constexpr float shipping_cost_ = 10.00f;

    OrderRepository& repo_;
    const ItemService& item_service_;

};

#endif /* ORDERSERVICE_H */


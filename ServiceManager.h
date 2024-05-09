/* 
 * File:   ServiceManager.h
 * Author: Theopolis Armstrong
 *
 * Created on May 1, 2024, 6:54 PM
 */

#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <utility>

#include "UserService.h"
#include "ItemService.h"
#include "OrderService.h"

// Singleton registry for services such as ItemService and UserService
class ServiceManager {
public:
    static ServiceManager& instance() {
        static ServiceManager instance("user_db.bin", "item_db.bin", "order_db.bin");
        return instance;
    }
private:
    ServiceManager(std::string user_db_filename, std::string item_db_filename, std::string order_db_filename)
    : user_repo_(std::move(user_db_filename))
    , item_repo_{std::move(item_db_filename)}
    , order_repo_(std::move(order_db_filename))
    , user_service_{user_repo_}
    , item_service_{item_repo_}
    , order_service_{order_repo_, item_service_}
    { }

public:
    UserService* get_user_service() { return &user_service_; }
    ItemService* get_item_service() { return &item_service_; }
    OrderService* get_order_service() { return &order_service_; }
private:
    ItemRepository item_repo_;
    UserRepository user_repo_;
    OrderRepository order_repo_;
    UserService user_service_;
    ItemService item_service_;
    OrderService order_service_;
};

#endif /* SERVICEMANAGER_H */


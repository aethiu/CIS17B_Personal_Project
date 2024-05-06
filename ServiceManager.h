/* 
 * File:   ServiceManager.h
 * Author: Theopolis Armstrong
 *
 * Created on May 1, 2024, 6:54 PM
 */

#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include "UserService.h"
#include "ItemService.h"

// Singleton registry for services such as ItemService and UserService
class ServiceManager {
public:
    static ServiceManager& instance() {
        static ServiceManager instance("item_db.bin");
        return instance;
    }
private:
    ServiceManager(std::string item_db_filename) : item_repo_{item_db_filename}, item_service_{item_repo_} { }

public:
    UserService* get_user_service() { return &user_service_; }
    ItemService* get_item_service() { return &item_service_; }
private:
    ItemRepository item_repo_;
    UserService user_service_;
    ItemService item_service_;
};

#endif /* SERVICEMANAGER_H */


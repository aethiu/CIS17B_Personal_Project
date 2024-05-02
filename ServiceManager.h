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
        static ServiceManager instance;
        return instance;
    }
private:
    ServiceManager() =default;

public:
    UserService *get_user_service() { return &user_service_; }
    ItemService *get_item_service() { return &item_service_; }
private:
    UserService user_service_;
    ItemService item_service_;
};

#endif /* SERVICEMANAGER_H */


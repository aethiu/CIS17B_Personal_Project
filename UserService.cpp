/*
 * File:   UserService.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 1, 2024, 6:43 PM
 */

#include "UserService.h"

// Randomly generate user ID's until we find a free ID
unsigned int UserService::get_new_id() const {
    unsigned int id = rand()%10000; // should be changed max possible ID
    if (repo_.read_row(id) == nullptr) {
      return id;
    }
    return get_new_id();
}

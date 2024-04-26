/*
 * File:   User.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:56 AM
 */

#ifndef USER_H
#define USER_H

#include <string>

#include "Cart.h"

class User {
public:

private:
    unsigned int id_ = 0;
    std::string username_;
    std::string password_;
    Cart cart_;
};

#endif /* USER_H */


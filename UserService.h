/* 
 * File:   UserService.h
 * Author: Theopolis Armstrong
 *
 * Created on May 1, 2024, 6:43 PM
 */

#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "User.h"

#include <string>

class UserService {
public:
    virtual ~UserService() =default;

    User* get_user(std::string username);

private:
};

#endif /* USERSERVICE_H */


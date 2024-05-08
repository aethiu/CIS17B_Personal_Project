/* 
 * File:   UserService.h
 * Author: Theopolis Armstrong
 *
 * Created on May 1, 2024, 6:43 PM
 */

#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "User.h"
#include "UserRepository.h"

#include <string>

class UserService {
public:
    UserService(UserRepository& repo) : repo_(repo) { }

    const User* add_user(const User& user) { return repo_.create_row(user.get_id(), user); }

private:
    UserRepository& repo_;
};

#endif /* USERSERVICE_H */


/*
 * File:   User.h
 * Author: Theopolis Armstrong
 *
 * Created on April 26, 2024, 10:56 AM
 */

#ifndef USER_H
#define USER_H

#include <string>
#include <utility>

class User {
public:
    User(unsigned int id, bool is_admin, std::string username, std::string password)
        : id_(id), username_(std::move(username)), password_(std::move(password)), is_admin_(is_admin) { }

    bool is_admin() const noexcept { return is_admin_; }
    unsigned int get_id() const noexcept { return id_; }
    const std::string& get_username() const noexcept { return username_; }
    const std::string& get_password() const noexcept { return password_; }
private:
    unsigned int id_ = 0;
    bool is_admin_ = false;
    std::string username_;
    std::string password_;
};

#endif /* USER_H */


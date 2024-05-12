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
    User() =default;
    User(unsigned int id, bool is_admin, std::string username, std::string password)
        : id_(id), username_(std::move(username)), password_(std::move(password)), is_admin_(is_admin) { }

    unsigned int get_id() const noexcept { return id_; }
    bool is_admin() const noexcept { return is_admin_; }
    const std::string& get_username() const noexcept { return username_; }
    const std::string& get_password() const noexcept { return password_; }

    void set_id(unsigned int id) noexcept { id_ = id; }
    void set_admin(bool is_admin) noexcept { is_admin_ = is_admin; }
    void set_username(std::string username) noexcept { username_ = std::move(username); }
    void set_password(std::string password) noexcept { password_ = std::move(password); }

    bool operator==(const User& user) const;
    bool operator==(const unsigned int rhs) const { return id_ == rhs; }

private:
    unsigned int id_ = 0;
    bool is_admin_ = false;
    std::string username_;
    std::string password_;
};

#endif /* USER_H */


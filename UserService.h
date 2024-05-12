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
#include <vector>

class UserService {
public:
    UserService(UserRepository& repo) : repo_(repo) { }

    const User* get_user(unsigned int id) const { return repo_.read_row(id); }
    const User* find_user(std::string username, std::string password) const { return repo_.find_user(username, password); }
    const User* add_user(const User& user) { return repo_.create_row(user.get_id(), user); }
    const User* update_user(const User& user) { return repo_.update_row(user.get_id(), user); }
    void remove_user(unsigned int id) { repo_.delete_row(id); }
    const std::vector<const User*> get_users() { return std::move(repo_.read_table()); }

    /** \brief Get a new, unused ID
     *
     * ID are guaranteed to be unused at the time of calling.
     * Subsequent calls without adding a new User with the returned ID are not guaranteed to be unused.
     *
     * @return Unused user ID
     */
    unsigned int get_new_id() const;

private:
    UserRepository& repo_;
};

#endif /* USERSERVICE_H */


/* 
 * File:   UserRepository.h
 * Author: Theopolis Armstrong
 *
 * Created on May 5, 2024, 6:59 PM
 */

#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "Repository.h"

#include "User.h"

#include <vector>

class UserRepository : public Repository {
public:
    UserRepository() =default;
    UserRepository(std::string db_filename) : Repository(db_filename) { load(); }

    void create_user(const User& user);
    const User* read_user(unsigned int id) const;
    const User* read_user(std::string username) const;
    void update_user(unsigned int id, const User& user);
    void delete_user(unsigned int id);

private:
    void load() override;
    void save() const override;

    std::vector<User> users_;
};

#endif /* USERREPOSITORY_H */


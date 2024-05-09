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

class UserRepository : public Repository<unsigned int, User> {
public:
    UserRepository() =default;
    UserRepository(std::string db_filename) : Repository<unsigned int, User>(std::move(db_filename)) { load(); }

    const User* find_user(const std::string& username, const std::string& password) const;

private:
    void load_row(std::ifstream &db) override;
    void save_row(std::ofstream &db, const User& row) const override;
};

#endif /* USERREPOSITORY_H */


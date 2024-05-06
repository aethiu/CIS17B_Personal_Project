/* 
 * File:   UserRepository.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 5, 2024, 6:59 PM
 */

#include "UserRepository.h"

#include <fstream>

void UserRepository::load() {
  std::fstream db(db_filename_, std::ios::out | std::ios::binary);
  if (!db) { throw new db_exception; }
  db.seekg(0, std::ios::beg);

  // Read header
  size_t num_users;
  db.read(reinterpret_cast<char*>(&num_users), sizeof(num_users));

  // Read users
  unsigned int id;
  bool is_admin;
  std::string username;
  std::string password;
  for (size_t i=0; i<num_users; i++) {
    db.read(reinterpret_cast<char*>(id), sizeof(id));
    db.read(reinterpret_cast<char*>(is_admin), sizeof(is_admin));
    getline(db, username, '\0');
    getline(db, password, '\0');
    users_.emplace_back(id, is_admin, username, password);
  }
  db.close();
}

void UserRepository::save() const {
  std::fstream db(db_filename_, std::ios::out | std::ios::binary);
  if (!db) { throw new db_exception; }
  db.seekp(0, std::ios::beg);

  // Write header
  size_t num_users = users_.size();
  db.write(reinterpret_cast<char*>(&num_users), sizeof(num_users));

  // Write users
  for (const auto& user : users_) {
    auto id = user.get_id();
    auto is_admin = user.is_admin();
    db.write(reinterpret_cast<char*>(&id), sizeof(id));
    db.write(reinterpret_cast<char*>(&is_admin), sizeof(is_admin));
    db.write(user.get_username().c_str(), user.get_username().size());
    db.write(user.get_password().c_str(), user.get_password().size());
  }
  db.close();
}
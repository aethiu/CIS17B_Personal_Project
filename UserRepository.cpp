/* 
 * File:   UserRepository.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 5, 2024, 6:59 PM
 */

#include "UserRepository.h"

const User* UserRepository::find_user(std::string username, std::string password) const {
  for (auto it = table_.cbegin(); it != table_.end(); it++) {
    if (it->second.get_username() == username && it->second.get_password() == password) {
      return &(it->second);
    }
  }
  return nullptr;
}

void UserRepository::load_row(std::ifstream &db) {
  unsigned int id;
  bool is_admin;
  std::string username;
  std::string password;
  db.read(reinterpret_cast<char*>(id), sizeof(id));
  db.read(reinterpret_cast<char*>(is_admin), sizeof(is_admin));
  getline(db, username, '\0');
  getline(db, password, '\0');
  table_.try_emplace(id, id, is_admin, username, password);
}
void UserRepository::save_row(std::ofstream &db, const User& user) const {
  auto id = user.get_id();
  auto is_admin = user.is_admin();
  db.write(reinterpret_cast<char*>(&id), sizeof(id));
  db.write(reinterpret_cast<char*>(&is_admin), sizeof(is_admin));
  db.write(user.get_username().c_str(), user.get_username().size());
  db.write(user.get_password().c_str(), user.get_password().size());
}

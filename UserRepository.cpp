/* 
 * File:   UserRepository.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on May 5, 2024, 6:59 PM
 */

#include "UserRepository.h"

const User* UserRepository::find_user(const std::string& username, const std::string& password) const {
  for (const auto& [key, user] : table_) {
    if (user.get_username() == username && user.get_password() == password) {
      return &user;
    }
  }
  return nullptr;
}

void UserRepository::load_row(std::ifstream &db) {
  unsigned int id;
  bool is_admin;
  std::string username;
  std::string password;
  db.read(reinterpret_cast<char*>(&id), sizeof(id));
  db.read(reinterpret_cast<char*>(&is_admin), sizeof(is_admin));
  getline(db, username, '\0');
  getline(db, password, '\0');
  table_.try_emplace(id, id, is_admin, username, password);
}
void UserRepository::save_row(std::ofstream &db, const User& user) const {
  unsigned int id = user.get_id();
  bool is_admin = user.is_admin();
  db.write(reinterpret_cast<char*>(&id), sizeof(id));
  db.write(reinterpret_cast<char*>(&is_admin), sizeof(is_admin));
  db.write(user.get_username().c_str(), user.get_username().size()+1);
  db.write(user.get_password().c_str(), user.get_password().size()+1);
}

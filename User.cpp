/*
 * File:   User.cpp
 * Author: Theopolis Armstrong
 * 
 * Created on April 26, 2024, 10:56 AM
 */

#include "User.h"

bool User::operator==(const User& user) const {
  return id_ == user.get_id()
      && is_admin_ == user.is_admin()
      && username_ == user.get_username()
      && password_ == user.get_password();
}

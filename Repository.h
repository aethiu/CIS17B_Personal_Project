/* 
 * File:   Repository.h
 * Author: Theopolis Armstrong
 *
 * Created on May 5, 2024, 5:57 PM
 */

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <exception>
#include <string>
#include <utility>

class db_exception : public std::exception {
  const char* what() const noexcept override {
    return "Error connecting to database.\n";
  }
};

class Repository {
public:
  Repository() =default;
  Repository(std::string  db_filename) : db_filename_(std::move(db_filename)) { }
  virtual ~Repository() =default;

protected:
  std::string db_filename_;

  virtual void load() =0;
  virtual void save() const =0;
};

#endif /* REPOSITORY_H */


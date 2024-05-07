/* 
 * File:   Repository.h
 * Author: Theopolis Armstrong
 *
 * Created on May 5, 2024, 5:57 PM
 */

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <exception>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

class db_connection_exception : public std::exception {
  const char* what() const noexcept override {
    return "Error connecting to database.\n";
  }
};

/** \brief Repository represents database table data and handles reading and writing to a binary file.
 *
 * @tparam K Primary key
 * @tparam T Class representing row data
 */
template<class K, class T>
class Repository {
public:
  Repository() =default;
  Repository(std::string  db_filename) : db_filename_(std::move(db_filename)) { }
  virtual ~Repository() =default;

  /** \brief Create a new row in the table
   *
   * @param key Primary key
   * @param value Row object
   * @return Pointer to stored value
   */
  virtual const T* create_row(const K &key, const T &value) {
    table_.insert({key, value});
    save();
    return &table_[key];
  }

  /** \brief Retrieve a single row
   *
   * @param key Primary key
   * @return Pointer to stored row object or nullptr if no row matches the primary key
   */
  virtual const T* read_row(const K &key) const {
    auto it = table_.find(key);
    return it == table_.end() ? nullptr : &(it->second);
  }

  /** \brief Get all data in a table
   *
   * @return vector of pointers to row objects
   */
  virtual std::vector<const T*> read_table() const {
    std::vector<const T*> table;
    for (const auto& [key, value] : table_){
      table.push_back(&value);
    }
    return table;
  }

  /** \brief Update table row at key with data from value member variables
   *
   * Changing a value's key member variable does not change the key in the Repository's private table.
   * If value and key comparison fails, the function exits without attempting to update and returns nullptr.
   * To change a value's key, create a new row with Repository::create_row then delete the old row with Repository::delete_row.
   *
   * @param key Primary key
   * @param value Row object with updated members
   * @return Pointer to updated object or nullptr if no object was updated
   */
  virtual const T* update_row(const K &key, const T &value) {
    if (!(value == key)) { return nullptr; } // operator== is assumed to be implemented but not !=
    if (table_.count(key) == 0) { return nullptr; }
    table_[key] = value;
    save();
    return &table_[key];
  }

  /** \brief Deletes a row from the table
   *
   * Pointers to the deleted value are invalid once this function is called.
   *
   * @param key Primary key
   */
  virtual void delete_row(const K &key) {
    table_.erase(key);
    save();
  }

protected:
  std::string db_filename_;
  std::unordered_map<K, T> table_; // Local storage of binary file database table

  /** \brief Inserts a row into the table from a binary file
   *
   * Subclasses of Repository<> are required to implement this function to deserialize and emplace a single object into the table storage.
   *
   * @param db Database binary file
   */
  virtual void load_row(std::ifstream &db) =0;
  /** \brief Writes a row from the table to a binary file
   *
   * Subclasses of Repository<> are required to implement this function to serialize objects to the binary file database.
   *
   * @param db Database binary file
   */
  virtual void save_row(std::ofstream &db, const T&) const =0;

  //! Loads data from binary file into table storage
  void load() {
    std::ifstream db(db_filename_, std::ios::out | std::ios::binary);
    if (!db) { throw new db_connection_exception; }
    db.seekg(0, std::ios::beg);
    table_.clear();

    // Read header
    size_t num_rows;
    db.read(reinterpret_cast<char*>(&num_rows), sizeof(num_rows));

    // Read rows
    for (size_t i=0; i<num_rows; i++) {
      load_row(db);
    }
    db.close();
  }

  //! Writes data to binary file from table storage
  void save() const {
    std::ofstream db(db_filename_, std::ios::out | std::ios::binary);
    if (!db) { throw new db_connection_exception; }
    db.seekp(0, std::ios::beg);

    // Write header
    size_t num_rows = table_.size();
    db.write(reinterpret_cast<char*>(&num_rows), sizeof(num_rows));

    // Write rows
    for (const auto& [_, row] : table_) {
      save_row(db, row);
    }
    db.close();
  }
};

#endif /* REPOSITORY_H */


//
// Created by Abyl Ikhsanov on 16/03/2023.
//

#ifndef BUILD_BLOCK_H
#define BUILD_BLOCK_H

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <openssl/evp.h>
#include <future>

class Block
{
public:
  Block() = delete;
  Block(const int& id, const int& noice, const std::string& data);
  std::string sha256(const std::string& data);
  void hashCompleteCallback();
  void startGetHashAsync(unsigned int& difficulty);
  std::string getHash(const unsigned int& difficulty);

private:
  int id_;
  int noice_;
  std::string hash_;
  std::string data_;

};

#endif //BUILD_BLOCK_H

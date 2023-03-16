//
// Created by Abyl Ikhsanov on 16/03/2023.
//

#include <PrivateBlockchain/block.h>

Block::Block(const int &id, const int &noice, const std::string& data)
: id_(id), noice_(noice), data_(data)
{
  this->hash_ = sha256(std::to_string(id) + std::to_string(noice));
}

std::string Block::sha256(const std::string &data)
{
  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hash_len;
  EVP_MD_CTX* md_ctx = EVP_MD_CTX_new();
  EVP_DigestInit_ex(md_ctx, EVP_sha256(), nullptr);
  EVP_DigestUpdate(md_ctx, data.c_str(), data.size());
  EVP_DigestFinal_ex(md_ctx, hash, &hash_len);
  EVP_MD_CTX_free(md_ctx);
  std::stringstream ss;
  for(int i = 0; i < hash_len; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }
  return ss.str();
}

std::string Block::getHash(const unsigned int& difficulty)
{
  std::string goal_hash;
  for (unsigned int i = 0; i < difficulty; i++)
    goal_hash.append("0");
  while (this->hash_.substr(0, difficulty) != goal_hash)
  {
    this->noice_++;
    this->hash_ = this->sha256(std::to_string(this->id_) + std::to_string(this->noice_));
  }
  return this->hash_;
}

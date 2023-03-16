//
// Created by Abyl Ikhsanov on 16/03/2023.
//
#include <PrivateBlockchain/block.h>
#include <future>

bool recHash = false;

void callbackAtHash(const std::string& hash)
{
  std::cout << "Hash is " << hash << std::endl;
  recHash = true;
}

int main(int argc, char** argv)
{
  Block block(0, 0, "Test Block");
  unsigned int difficulty = 3;

  std::future<std::string> getHashFuture = std::async(std::launch::async, [&block, difficulty] () {
    return block.getHash(difficulty);
  });

  auto getHashCallbackThread = std::thread([&getHashFuture](){
    callbackAtHash(getHashFuture.get());
  });

  getHashCallbackThread.detach();

  while (not recHash)
    std::this_thread::sleep_for(std::chrono::seconds(1));
  return 0;
}
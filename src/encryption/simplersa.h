#include "key.h"

#include <string>

namespace RSA
{

    RSA::KeyPair generate_simple_keypair(int x, int y);
    std::string encrypt_simple(std::string key, std::string msg);
    std::string decrypt_simple(std::string key, std::string c);

}
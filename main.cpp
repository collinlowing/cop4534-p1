#include <iostream>

#include "Cipher.hpp"

int main() {
    Cipher cipher;
    std::string key = cipher.getKey();
    std::string message = "thisisamessage";
    std::string resizedKey = cipher.resize(key, message);
    std::cout << "Hello World! " << resizedKey << std::endl;
    return 0;
}

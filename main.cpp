#include <iostream>

#include "Cipher.hpp"

int main()
{
    Cipher cipher;
    const char * key = cipher.getKey();
	std::cout << "Hello World! " << key << std::endl;
	return 0;
}

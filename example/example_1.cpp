#include <iostream>
#include <iomanip>
#include <crng.h>

void print_hex(const uint8_t* data, size_t len){
	for (size_t i = 0; i < len; i++) {
		std::cout << std::hex
			<< std::setw(2)
			<< std::setfill('0')
			<< (int)data[i];
	}
	std::cout << std::dec << std::endl;
}

int main() {

	// 1 example : 
	unsigned int buff; 
	if (crng_fill(&buff, sizeof(unsigned int)) == 0) {
		std::cout << "rng value 1 : " << buff << std::endl;
	}

	// 2 example : 
	uint64_t buffer = crng_u64();
	std::cout << "rng value 2 : " << buffer << std::endl;

	// 3 example : 
	std::cout << "rng value 3 : " << crng_u64() << std::endl;

	// 4 example :
	uint8_t salt[16];
	if (crng_fill(salt, sizeof(salt)) == 0) {
		std::cout << "salt : ";
		print_hex(salt, sizeof(salt));
	}


	return 0;
}
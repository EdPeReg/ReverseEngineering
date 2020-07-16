/* 2020-07-14 
 *
 *	https://crackmes.one/crackme/5e66aea233c5d4439bb2dde8
 *
 * */

#include <iostream>
#include <string>
#include <random>

int main() {
	std::string pass;
	std::random_device r;
	std::default_random_engine re(r());
	std::uniform_int_distribution<int> uniform_dist(97,122); // a-z.

	int numKeys = 0;
	std::cout << "Enter the number of keys to be generated: ";
	std::cin >> numKeys;

	int i = 1;
	while(numKeys--) {
		int asciiSum = 0;
		// Generate a random string until its size is greater than 1000.
		while(true) {
			int asciiVal = uniform_dist(re); // Generate the randon number.
			asciiSum += asciiVal;
			pass += asciiVal;

			if(asciiSum > 1000) {
				break;
			} 
		}

		std::cout << i << " -> " << pass << '\n';
		i++;
		pass.clear(); // Clear the previous pass.
	}

	return 0;
}

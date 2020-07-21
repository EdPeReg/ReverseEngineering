#include <iostream>
#include <random>

int main() {
	std::random_device rd;
	std::default_random_engine re(rd());
	std::uniform_int_distribution<int> uniform_dist(48, 122); // 0 to z.
	
	std::string pass;

	int numKeys;
	std::cout << "Number of keys to be generated --> ";
	std::cin >> numKeys;

	while(numKeys--) {
		// Generate the correct password and stop until accomplish the 
		// requirements.
		while(true) {
			// The second character should be @.
			if(pass.size() == 1) {
				pass += '@';
			}

			int asciiVal = uniform_dist(re);
			pass += asciiVal;

			// Pass should be size 5 and their ascii sum from positions
			// 2, 3, and 4 should be 300.
			if(pass.size() == 5) {
				if(pass.at(2) + pass.at(3) + pass.at(4) == 300) {
					break;
				} 
				// Reset pass to start again.
				else {
					pass.clear();
				}
			} 
		}

		std::cout << pass <<'\n';
		pass.clear();
	}

	return 0;
}

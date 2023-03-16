#include <cstdint>
#include <iostream>

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int oneBits = 0;

		while (n) { // while n is not 0
			oneBits += n & 1; // if last bit is 1, result is 1, otherwise 0 (n % 2)
			n >>= 1; // shift bits one place to the right (n /= 2)
		}

		return oneBits;
	}
};

int main() {
	Solution s;

	std::cout << s.hammingWeight(0b00000000000000000000000000001011) << '\n';
	std::cout << s.hammingWeight(0b00000000000000000000000010000000) << '\n';
	std::cout << s.hammingWeight(0b11111111111111111111111111111101) << '\n';
}
#include <iostream>

using namespace std;

int main() {
	string s;
	s += "V" + string(8 - 5, 'I');
	std::cout << s << std::endl;
	return 0;
}

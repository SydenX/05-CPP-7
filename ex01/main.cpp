#include "iter.hpp"

void print(std::string str){
	std::cout << str << std::endl;
}

int total = 0;
void sum(int const &i){
	total += i;
}

int main( void ) {
	std::string listString[3] = {"1", "2", "3"};
	::iter(&listString, 3, &print);

	int listInt[4] = {50, 100, 10, -10};
	::iter(&listInt, 4, &sum);
	std::cout << total << std::endl;
	total = 0;
	return 0;
}
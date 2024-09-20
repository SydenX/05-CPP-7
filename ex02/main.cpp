#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 10
int main(int, char**)
{
	// Fill one array with random numbers
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++){
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	std::cout << "TEST 1 -> Try to access out of bound array" << std::endl;
	Array<int> tmp;
	try{
		for (int i = 0; i < 1 + 1; i++)
			std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl;
	}catch(const std::exception& e){
		std::cerr << std::endl;
		std::cerr << e.what() << '\t';
		std::cerr << "1 You tried to access past the last element of the array" << std::endl << std::endl;
	}


	std::cout << "TEST 2 -> Copy numbers array to tmp array, then create test array from tmp array, compare if values matches." << std::endl;
	tmp = numbers;
	Array<int> test(tmp);
	try{
		for (int i = 0; i < MAX_VAL; i++){
			if (tmp[i] != test[i]){
				std::cerr << "didn't save the same value!!";
				return 1;
			}
			std::cout << "tmp[" << i << "]:\t\t" << tmp[i] << std::endl;
			std::cout << "test[" << i << "]:\t" << test[i] << std::endl;
		}
		std::cout << std::endl;
	}catch(const std::exception& e){
		std::cerr << e.what() << '\t';
		std::cerr << "2 You tried to access past the last element of the array" << std::endl;
	}

	std::cout << "TEST 3 -> Check if first value of arrays matches;" << std::endl;
	std::cout << "test[1]:\t" << test[1] << std::endl;
	std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl;
	std::cout << "numbers[1]:\t" << numbers[1] << std::endl << std::endl;

	std::cout << "TEST 4 -> Modify values from certain arrays and check if it's changes others values or not." << std::endl;
	int oldn = numbers[1];
	test[1] = 12345891;
	numbers[1] = 6578;
	std::cout << "test[1]:\t" << test[1] << std::endl;
	std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl;
	std::cout << "numbers[1]:\t" << numbers[1] << std::endl << std::endl;
	numbers[1] = oldn;

	std::cout << "TEST 5 -> recheck if values have not changed during previous tests in numbers array" << std::endl;
    for (int i = 0; i < MAX_VAL; i++){
        if (mirror[i] != numbers[i]){
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		if (i == MAX_VAL - 1)
			std::cout << std::endl;
    }

	std::cout << "TEST 6 -> Try negative index" << std::endl;
    try{
        numbers[-2] = 0;
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n' << std::endl;
    }

	std::cout << "TEST 7 -> Try index with the array's size or behind" << std::endl;
    try{
        numbers[MAX_VAL] = 0;
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n' << std::endl;
    }
    delete [] mirror;//
    return 0;
}
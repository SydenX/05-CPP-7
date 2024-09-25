#ifndef ITER
# define ITER

#include <iostream>

template < typename T, typename F >
void iter(T *add, int const len, void (*fun)(F)){
	for (int i = 0; i < len; i++){
		fun((add)[i]);
	}
}

#endif
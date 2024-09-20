#ifndef ITER
# define ITER

#include <iostream>

template < typename T, typename F>
void iter(T const &add, int const len, F const &fun){
	for (int i = 0; i < len; i++){
		fun((*add)[i]);
	}
}

#endif
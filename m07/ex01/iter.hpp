#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T>
void	print(T &elem) {
	std::cout << elem << std::endl;
}

template<typename T>
void iter(const T * arr, unsigned int & len, void (*fun)(const T &)) {
	unsigned int	i = 0;

	while (i < len) {
		fun(arr[i]);
		i++;
	}
}

#endif

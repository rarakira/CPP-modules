#include "Array.hpp"

template<typename T>
Array<T>::Array(): _size(0), _arr(NULL) {
	std::cout	<< COLOUR_NEW
				<< "Array default constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

template<typename T>
Array<T>::Array(unsigned int size): _size(size), _arr(new T[size]) {
	std::cout	<< COLOUR_NEW
				<< "Array constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

template<typename T>
Array<T>::Array (Array<T> const & src): _size(src.size()), _arr(new T[src.size()])  {
	unsigned int	i = 0;

	while (i < this->_size) {
		this->_arr[i] = src._arr[i];
		i++;
	}
	std::cout	<< COLOUR_NEW
				<< "Array copy constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs) {
	unsigned int	i = 0;

	if (this->_size)
		delete [] this->_arr;
	this->_size = rhs.size();
	this->_arr = new T[this->_size];
	while (i < this->_size) {
		this->_arr[i] = rhs._arr[i];
		i++;
	}
	std::cout	<< COLOUR_NEW
				<< "Assignation operator called"
				<< COLOUR_FIN
				<< std::endl;
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete [] this->_arr;
	std::cout	<< COLOUR_DELETE
				<< "Array destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

template<typename T>
T & Array<T>::operator[](const unsigned int index) const {
	if (index >= this->_size)
		throw std::overflow_error("Index out of bounds");
	return this->_arr[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

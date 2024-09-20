#ifndef ARRAY
# define ARRAY

#include <iostream>

template < typename T >
class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array<T>(): _array(new T[0]), _size(0) {};
		Array<T>(unsigned int n): _array(new T[n]), _size(n) {};
		Array<T>(const Array &ref){
			this->_array = new T[ref.size()];
			for(unsigned int i = 0; i < ref.size(); i++)
				this->_array[i] = ref._array[i];
			this->_size = ref.size();
		};
		Array &operator=(const Array<T> &ref){
			if (this->_array != NULL)
				delete []_array;
			this->_array = new T[ref.size()];
			for(unsigned int i = 0; i < ref.size(); i++)
				this->_array[i] = ref._array[i];
			this->_size = ref.size();
			return *this;
		};

		class ArrayOutOfBoundException : public std::exception {
			public:
				virtual const char *what() const throw(){
					return "ArrayOutOfBound";
				};
		};
		T &operator[](unsigned int index){
			if (index >= _size || index < 0)
				throw ArrayOutOfBoundException();
			return _array[index];
		}
		
		~Array<T>(){
			delete []_array;
		};
		unsigned int size() const {
			return _size;
		};
};

#endif
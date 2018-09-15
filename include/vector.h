#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <typename Tr>
class Vector {
public:
	typedef typename Tr::T T;
	typedef typename Tr::Operation Operation;
             
private:
	T* data;
	int dataSize;
	int dimensions;
	int* dimensionSizes;
	Operation op;

public:
	Vector() : data(nullptr) {

	};
             
	Vector(int dimensions, int* dimensionSize) : dimensions(dimensions) {
		// TODO
		this->dimensionSizes = new int[dimensions];
		dataSize = 0;
		for(int i=0; i<dimensions; i++){
			this->dimensionSizes[i] = dimensionSize[i];
			dataSize *= dimensionSize[i];
		}
		data = new T[dataSize];
	}
             
	void set(T datum, int* coordinates); // TODO
             
	T get(int* coordinates); // TODO
	void print();
	~Vector();
};


template <typename Tr>
void Vector<Tr>::set(Vector<Tr>::T datum, int* coordinates){
	data[op(coordinates, dimensionSizes, dimensions)] = datum;
}

template <typename Tr>
typename Vector<Tr>::T Vector<Tr>::get(int* coordinates){
	return 	data[op(coordinates, dimensionSizes, dimensions)];
}


template <typename Tr>
void Vector<Tr>::print(){
	
}
template <typename Tr>
Vector<Tr>::~Vector(){
	dimensions = 0;
	dataSize = 0;
	delete[] dimensionSizes;
	delete[] data;
}
#endif

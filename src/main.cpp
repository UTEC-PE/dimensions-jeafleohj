#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {      
    int operator()(int* coordinates, int* sizes, int dimensions) {
		int prod = 1;
		int pos = coordinates[0];
		for(int i = 0; dimensions-1 > i; i++){
			prod *= sizes[i];
			pos += prod*coordinates[i+1];
		}
		return pos;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    system("clear");
	const int dim = 2;
	int m[] = {2,2,3,4,3}, *pm = m;
	Vector<Integer> v(4, m);
	int k[] = {1,1,2,3,4}, *pk=k;
	v.set(6, pk);
	cout << v.get(pk) << "\n";
    return EXIT_SUCCESS;
}

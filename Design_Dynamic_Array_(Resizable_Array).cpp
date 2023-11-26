#include <bits/stdc++.h>
using namespace std;

class DynamicArray {
private:
	int *arr;
	int size = 0;
	int index = -1;
public:

	DynamicArray(int capacity) {
		if (capacity > 0){
			arr = new int[capacity];
			size = capacity;
		}
	}

	int get(int i) {
		return i >= size ? -1 : arr[i];
	}

	void set(int i, int n) {
		if (i < size) {
			arr[i] = n;
		}
	}

	void pushback(int n) {
		if (index >= (size - 1)) {
			resize();
		}
		index++;
		arr[index] = n;
	}

	int popback() {
		if (index >= 0) {
			index--;
		}
		return arr[index + 1];
	}

	void resize() {
		int *newArr = new int[size * 2];
		for (int i = 0; i< size; i++){
			newArr[i] = arr[i];
		}
		arr = newArr;
		size = size * 2;
	}

	int getSize() {
		return index + 1;
	}

	int getCapacity() {
		return size;
	}
};
int main() {
	return 0;
}

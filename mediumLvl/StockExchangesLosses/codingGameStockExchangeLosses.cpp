#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <limits>

using namespace std;

int main() {

	int count;
	int min;
	int a;
	int b;
	int buff;
	int index;
	vector<int> array = {1, 5, 4, 10, 8, 4, 5, 42, 41};
	count = 6;

	min = 0;
	index = 0;
	for (int i = index + 1; i < count; ++i) {
		buff = array[i] - array[index];
		if (buff < 0 && buff < min) {
			min = buff;
		}
		else if (buff > 0) {
			index = i;
		}
	}

	cout << min << endl;
	return (0);
}
#include <iostream>

using namespace std;

void output(int* data, unsigned int count){
	cout << '(';

	for (int i = 0; i < count-1; i++)
		cout << data[i] << ", ";

	cout << data[count - 1] << ')' << endl;
}

unsigned int swapc = 0, compare = 0;

void bubble(int* data, unsigned int count){
	bool changed = true;

	while (changed){
		changed = false;

		for (unsigned i = 0; i < count -1; i++){
			
			compare += 1;

			if (data[i] > data[i+1]){
				swapc += 1;

				const int tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			
				changed = true;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	unsigned int count = 8;
	int *data = new int[count];

	for (int i = 0; i < count/2; i++){
		data[2*i] = i+1;
		data[2*i+1] = count/2 + i+1; 
	}

	output(data, count);
	bubble(data, count);
	output(data, count);
	cout << compare << endl << swapc << endl;

	return 0;
}
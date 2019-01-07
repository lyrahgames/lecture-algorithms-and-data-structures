#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
	// for (int i = 1; i < 8; i++){
	// 	const int n = 1<<i;

	// 	cout << n << ", " << 10*n*log2(n) << ", " << 3*n*n << endl;
	// }

	int n;

	for (int i = 8; i<=16; i++){
		if (10*i*log2(i) < 3*i*i){
			n = i;
			break;
		}
	}

	cout << n << endl;

	return 0;
}
#include <iostream>

using namespace std;

long multiply(long a, long b, long modulo) {
	return ((a % modulo) * (b % modulo)) % modulo;
}

int main(void) {
	long n, temp, modulo = 1000000007;
	cin >> n;
	long product = 1;
	while(n--) {
		cin >> temp;
		product = multiply(temp, product, modulo);
	}
	cout << product << endl;
	return 0;
}

#include <iostream>
// For using fill to reinitialise array
#include <algorithm>

#define MAX 200

using namespace std;

int len = 1;

int multiply(int res[], long temp) {
	int carry = 0;

	for (int i = 0; i < len; i++) {
		int prod = res[i] * temp + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}

	while(carry) {
		res[len] = carry % 10;
		carry = carry / 10;
		len++;
	}
	return 0;
}

int factorial(int res[], int num) {
	for (int i = 1; i <= num; i++) {
		multiply(res, i);
	}
}

int main(void) {
	long n, num;
	cin >> n;
	int res[MAX] = {0};
	res[0] = 1;
	while(n--) {
		// Reinitialising the array for each test case
		fill(res, res + MAX, 0);
		res[0] = 1;

		// Reinitialising the array for each test case.
		::len = 1;

		cin >> num;
		factorial(res, num);
	
		for(int i = len - 1; i >= 0; i--) {
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}

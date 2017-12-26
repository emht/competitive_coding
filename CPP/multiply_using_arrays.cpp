#include <iostream>
#include <vector>
#include <set>

using namespace std;

int multiply(int res[], long temp, int len) {
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
	return len;
}

int main(void) {
	long n, temp;
	cin >> n;
	int res[15] = {0}, len = 1;
	res[0] = 1;
	while(n--) {
		cin >> temp;
		len = multiply(res, temp, len);
	}
	for(int i = len - 1; i >= 0; i--) {
		cout << res[i];
	}
	cout << endl;
	return 0;
}

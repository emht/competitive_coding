/** Project Euler #2
 * Even Fibonacci Numbers
 * Platform: Hackerrank
 * Key:
 */

// Implement DP to save TLE error

#include <iostream>
using namespace std;

int main(void) {
	int cases;
	cin >> cases;
//	cout << cases;
	unsigned long long int pre, cur, total, n, temp;
	while(cases--) {
		pre = total = 0;
		cur = 1;

		cin >> n;

		while(cur <= n) {
			if (cur % 2 == 0) {
				total += cur;
			}
			temp = cur;
			cur = pre + cur;
			pre = temp;
		}
		cout << total << endl;
	}
	return 0;
}

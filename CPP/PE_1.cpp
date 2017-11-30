/* Project Euler question 1
 * Multiple of 3 and 5
 * Platform: Hackerrank
 * Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler001
 * Concept: Simple arithmetic and handling large integers in your code.
 * Find the sum of multiples of 3 and 5 belowe than number "n".
 */

#include <iostream>
using namespace std;

int main(void) {
	long int n;
	unsigned long long count_3, count_5, count_15, res;
	int cases;
	cin >> cases;
	while(cases--) {
		cin >> n;
		// To exclude the last element
		n--;

		count_3 = n / 3;
		count_5 = n / 5;
		count_15 = n / 15;

		count_3 = count_3 * (count_3 + 1) / 2;
		count_5 = count_5 * (count_5 + 1) / 2;
		count_15 = count_15 * (count_15 + 1) / 2;

		res = (3 * count_3 + 5 * count_5) - (15 * count_15);
		cout << res << endl;
	}
	return 0;
}

/* Codechef March challenge 2018 div2 
 * Minion Chef and bananas
 * Platform: codechef
 * Link: https://www.codechef.com/MARCH18B/problems/MINEAT
 * Concept: Binary search to find correct K
 * Status: passed
 */

#include <iostream>
#include <algorithm> //Sort function
#include <cmath> // Ceil function
using namespace std;

#define FOR(I, A, B) for(int I = (A); I < (B); ++I)

long long find_k(long long pile[], long long hours, long long low, long long max, long num_pile); 

int main(void) {
	int testcase;
	cin >> testcase;

	long num_pile;
	long long hours, k, max = 0;
	double average = 0;

	while(testcase--) {
		cin >> num_pile >> hours;
		long long pile[num_pile];

		FOR (i, 0, num_pile) {
			cin >> pile[i];
			average = average + pile[i];
			if (pile[i] > max) { max = pile[i]; }
		}

		average = average / num_pile;

		if (hours == num_pile) {
			// Initialising k with the largest size
			k = max;
			cout << k << endl;
		}
		else {
			k = find_k(pile, hours, 0, max, num_pile);	
			cout << k << endl; 
		}
	}
	return 0;
}

long long find_k(long long pile[], long long hours, long long low, long long max, long num_pile) {
	if (max >= low) {
		long long mid = (low + max) / 2, sum = 0, k = mid;
//		cout << "K is: " << k << endl;
	
		FOR(i, 0, num_pile) {
			if (pile[i] % k == 0) { sum = sum + pile[i] / k; }
			else { sum = sum + (pile[i] / k) + 1; }
//			cout << "sum is: " << sum << endl;
		}

		if (low == mid && max == mid + 1)
			return mid + 1;
	
		if (sum <= hours) { return find_k(pile, hours, low, mid, num_pile); }
		else if (sum > hours) { return find_k(pile, hours, mid, max, num_pile); }
	}
}

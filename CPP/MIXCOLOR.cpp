/* Codechef March challenge 2018 div2 
 * Mix the Colors 
 * Platform: codechef
 * Link: https://www.codechef.com/MARCH18B/problems/MIXCOLOR
 * Concept: Simple Sorting and condition verification. O(n2)
 * Status: Passed
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(I, A, B) for(int I = (A); I < (B); ++I)

int main(void) {
	long testcase, num_colors, min_op;
	cin >> testcase;

	// Setting up the precision factor for cout double
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(8);

	while(testcase--) {
		cin >> num_colors;
		long long color[num_colors];

		min_op = 0;

		FOR(i, 0, num_colors) {
			cin >> color[i];
		}
	
		sort(color, color + num_colors);

		FOR(i, 0, num_colors) {
			if (color[i] == color[i + 1]) {
				min_op++;
			}
		}

		cout << min_op << endl;
	}
	return 0;
}

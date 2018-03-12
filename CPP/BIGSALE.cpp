/* Codechef March challenge 2018 div2 
 * A Big Sale
 * Platform: codechef
 * Link: https://www.codechef.com/MARCH18B/problems/BIGSALE
 * Concept:  printing using cout upto n decimal digits and thus more precise answer
 * Status: PASSED 
 */

#include <iostream>
using namespace std;

#define FOR(I, A, B) for(int I = (A); I < (B); ++I)

int main(void) {
	int testcase;
	double effective_price, sell_price, total_loss;
	cin >> testcase;
	long int num_recipes;

	// Setting up the precision factor for cout double
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(8);

	while(testcase--) {
		total_loss = 0;
		cin >> num_recipes;
		int quantity[num_recipes], discount[num_recipes];
		double price[num_recipes];

		FOR(i, 0, num_recipes) {
			effective_price = sell_price = 0;
			cin >> price[i] >> quantity[i] >> discount[i];
						
			// LOGIC
			effective_price = (price[i] * (100 + discount[i])) / 100;
			sell_price = (effective_price * (100 - discount[i])) / 100;
			total_loss = (quantity[i] * (price[i] - sell_price)) + total_loss;

		}

		cout << total_loss << endl;
	}
}

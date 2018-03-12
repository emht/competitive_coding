/* Codechef March challenge 2018 div2 
 * Minion Chef and bananas
 * Platform: codechef
 * Link: https://www.codechef.com/MARCH18B/problems/MINEAT
 * Concept: Correct from my side. Missing some critical test cases, IDK which ones :/
 * Status: Failed
 */

#include <iostream>
#include <algorithm> //Sort function
using namespace std;

#define FOR(I, A, B) for(int I = (A); I < (B); ++I)

int main(void) {
	int testcase;
	long int num_pile, hour, k, temp_hour;
	float temp;
	cin >> testcase;

	bool decrease = false, increase = false;

	while(testcase--) {
		cin >> num_pile >> hour;
		long int pile_size[num_pile], average = 0, total_sum = 0, temp_sum;

		for (int i = 0; i < num_pile; i++) {	
			cin >> pile_size[i];
			total_sum = pile_size[i] + total_sum;
		}

		average = total_sum / num_pile;
	
		// Sort the array
		sort(pile_size, pile_size + num_pile);

		if (hour == num_pile) {
			// Initialising k with the largest size
			k = pile_size[num_pile - 1];
			cout << k << endl;
		}
		else {
			// Logic when hour != num_pile
			k = average;
			//cout << "K is: " << k << endl;
			decrease = increase = false;

			temp_sum = total_sum;
			temp_hour = hour;
			temp = 0;

			FOR(i, 0, num_pile) {
				if (pile_size[i] <= k) {
					temp_sum = temp_sum - pile_size[i];
					temp_hour--;
				}
				else {
					temp_sum = temp_sum - k;
					temp_hour--;
				}
			}

			temp = float(temp_sum) / temp_hour;
			//cout << "temp is: " << temp << endl;
			if (temp < k) { decrease = true;}
			else if (temp > k) { increase = true;}
			else if (temp == k) { cout << k << endl; }

			if (increase) {
				while(temp > k) {
					k++;
					//continue with k, final k is the answer
					temp_sum = total_sum;
					temp_hour = hour;

					FOR(i, 0, num_pile) {
						if (pile_size[i] <= k) {
							temp_sum = temp_sum - pile_size[i];
							temp_hour--;
						}
						else {
							temp_sum = temp_sum - k;
							temp_hour--;
						}
					}
					temp = float(temp_sum) / temp_hour;
				}
				cout << k << endl;
			}
			else if (decrease) {
				while (temp < k) {
					// continue with k - 1, k+1 is the answer
					k--;
					//cout << "K is: " << k << endl;
					temp_sum = total_sum;
					temp_hour = hour;

					FOR(i, 0, num_pile) {
						if (pile_size[i] <= k) {
							temp_sum = temp_sum - pile_size[i];
							temp_hour--;
						}
						else {
							temp_sum = temp_sum - k;
							temp_hour--;
						}
					}
					temp = float(temp_sum) / temp_hour;
					//cout << "temp is: " << temp << endl;
				}
				cout << k + 1 << endl;
			}
		}
	}
	return 0;
}

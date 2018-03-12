/* Codechef March challenge 2018 div2 
 * Minion Chef and bananas
 * Platform: codechef
 * Link: https://www.codechef.com/MARCH18B/problems/MINEAT
 * Concept: Understand the question more carefully 
 * Status: Failed
 */

#include <iostream>
#include <algorithm> //Sort function
#include <cstring> //memcpy function
using namespace std;

#define FOR(I, A, B) for(int I = (A); I < (B); ++I)

int check_K(long piles[], int count, int k, long sum, int hour) {
	long temp_piles[count];
	memcpy (temp_piles, piles, count * sizeof(long));
	int j = 0;
	while (j < count) {
		if (hour != 0) {
			if (temp_piles[j] <= k) {
				hour--;
				sum = sum - temp_piles[j];
				j++;
			}
			else {
				temp_piles[j] = temp_piles[j] - k;
				sum = sum - k;
				hour--;
			}
		}
		else 
			break;
	}

	if (sum > 0) { return 1; }
	else if (sum == 0 && hour == 0) { return 0; }
	else if (sum == 0 && hour > 0) { return -1; }
	else if (sum < 0) { return -1; } 
}

int main(void) {
	int testcase;
	int output, num_pile, hour, k;
	cin >> testcase;

	while(testcase--) {
		cin >> num_pile >> hour;
		long int pile_size[num_pile], average = 0, total_sum = 0;

		for (int i = 0; i < num_pile; i++) {	
			cin >> pile_size[i];
			total_sum = pile_size[i] + total_sum;
		}

		// Logic to calculate k
		average = total_sum / num_pile;

		// Start k with the average size of banana pile, if time left, reduce k else increase.
		k = average;
		
		// Sort the array
		sort(pile_size, pile_size + num_pile);
	
		output = check_K(pile_size, num_pile, k, total_sum, hour);

		while (output != 0) {
			if (output == 1) {
				k++;
			}
			else if (output == -1) {
				k--;
			}		
			
			// Call function check_K(k);
			output = check_K(pile_size, num_pile, k, total_sum, hour);
		}
			cout << k << endl;
	}

	return 0;
}

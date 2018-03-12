/* Codechef March challenge 2018 div2 
 * Chef and Glove
 * Platform: codechef
 * Link: https://www.codechef.com/MARCH18B/problems/CHEGLOVE
 * Concept: 
 * Status: Passed
 */

#include <iostream>
using namespace std;

#define FOR(I, A, B) for(int I = (A); I < (B); ++I)

int main(void) {
 int testcase, fingers;
 cin >> testcase;

 bool front, back;

 while(testcase--) {
 	front = back = false;
	cin >> fingers;
	long int fin_len[fingers], glove_len[fingers];
	FOR(i, 0, fingers) {
		cin >> fin_len[i];
	}
	FOR(i, 0, fingers) {
		cin >> glove_len[i];
	}

	// Check for front side possibility
	FOR(i, 0, fingers) {
		if (fin_len[i] <= glove_len[i]) {
			front = true;
		}
		else {
			front = false;
			break;
		}
	}
	
	// Check for back side possibility
	FOR(i, 0, fingers) {
		if(fin_len[i] <= glove_len[fingers - i - 1]) {
			back = true;
		}
		else {
			back = false;
			break;
		}
	}

	// Check for both side
	if (front && back) {
		cout << "both" << endl;
	}
	else if (front) {
		cout << "front" << endl;
	}
	else if (back) {
		cout << "back" << endl;
	}
	else {
		cout << "none" << endl;
	}
 }
}

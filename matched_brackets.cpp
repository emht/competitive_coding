/*
 * Name: Matched Brackets
 * Platform: Codechef
 * link: https://www.codechef.com/ZCOPRAC/problems/ZCO12001
 * Key: String manipulation
 */

#include <iostream>
#include <set>
#include <iterators>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int temp;

	multiset <int, greater <int> > input;
	multiset <int, greater <int> > :: iterator itr;
	
	for(int i = 0; i < N; i++) {
		cin >> temp;
		input.insert(temp);
	}

	
	return 0;
}


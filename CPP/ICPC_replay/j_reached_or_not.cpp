/** Name: J: Reached safely or not
  * Link: https://www.codechef.com/KOL17ROL/problems/ZUBREACH
  * Platform: Codechef
  */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	//Variable declaration
	int cases;
	int m, n, rx, ry;
	int cx, cy; // to store current value of x and y
	int strlength;
	string moves;
	char temp;
	string output;

	cin >> cases;

	while(cases--) {
		cx = cy = 0;

		cin >> m >> n;
		cin >> rx >> ry;
		cin >> strlength;
		cin >> moves;
		
		for (int i = 0; i < strlength; i++) {
			temp = moves[i];
			switch(temp) {
				case 'U':
					cy += 1;
					break;

				case 'D':
					cy -= 1;
					break;

				case 'R':
					cx += 1;
					break;

				case 'L':
					cx -= 1;
					break;
			}
		}

		//Logic
		if (cx == rx && cy == ry)
			output = "REACHED";
		else if (cx < 0 || cx > m || cy < 0 || cy > n)
			output = "DANGER";
		else
			output = "SOMEWHERE";

		cout << output << endl;
	}

	return 0;
}

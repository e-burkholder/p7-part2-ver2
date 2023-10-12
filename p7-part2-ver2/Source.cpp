#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	//every second run a sim that picks an int (-1 to 1) and adds to regular coordinates
	//run for 120 seconds
	int step, x = 0, y = 0;
	double min, distance, avgDistance2, avgDistance=0, numDist = 0, stepNum, totalDistance=0, exp, expDist, dist, sec;

	srand(time(0));
	cout << "Enter number of minutes for each drunkard to stagger: ";
	cin >> min;
	sec = min * 60;
	for (int i = 0; i < 10000; i++) {
		x = 0;
		y = 0;
		for (int a = 0; a < sec; a++) {
			step = rand() % 9 + 1;

			switch (step) {
			case (1): (--x, y++); break;
			case (2): (--x, y); break;
			case (3): (--x, y--); break;
			case (4): (x, y); break;
			case (5): (x, y++);  break;
			case (6): (x, y--);  break;
			case (7): (x++, y);break;
			case (8): (x++, y++);  break;
			case (9): (x++, y--); break;
			}

		}
		totalDistance += sqrt(pow(x, 2) + pow(y, 2));
	}
	exp = (4 + 4 * (sqrt(2))) / 9;
	expDist = sqrt(exp * sec);
	dist = totalDistance / 10000;

	cout << "Expected Distance: " << expDist << endl;
	cout << "Average Distance: " << dist;
	return 0;
}
#include "TList.h"
#include "TPolinom.h"

using namespace std;

void main() {
	cout << "		The polynomial test\n";

	int ms1[][2] = { {-1, 200}, {1,400} , {3,101}, {7, 210}, {10, 100} };
	int mn1 = sizeof(ms1) / (2 * sizeof(int));

	TPolinom p(ms1, mn1);
	cout << p;
}
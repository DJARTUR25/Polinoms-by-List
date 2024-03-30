#include "TList.h"

using namespace std;										//comment this file if you want to test HEADLIST or POLINOMS

void main() {
	
	cout << "				Testing of integer lists		" << endl;
	TList<int> L;
	int op = 1;
	cout << "			Choose the operation:	" << endl;
	cout << "		0 : finish test;" << endl;
	cout << "		1 : insert element before current;" << endl;
	cout << "		2 : insert element before first;" << endl;
	cout << "		3 : insert element after last;" << endl;
	cout << "		4 : output the list;" << endl;
	cout << "		5 : delete first element in list;" << endl;
	cout << "		6 : delete current element in list;" << endl;
	cout << "		7 : delete last element in list;" << endl;
	cout << "		9 : operations." << endl;
	cout << endl << endl;
	while (op != 0) {
		cout << "		Choose the operation:	" << endl;
		cout << "	";
		cin >> op;
		switch (op) {

			case 0:
			{
				cout << "			Testing finished		" << endl;
				break;
			}

			case 1:
			{
				cout << "		Enter the integer number what insert before current in list	" << endl << "	";
				int num;
				cin >> num;
				L.InsCurr(num);
				cout << "		Entered!	" << endl;
				break;
			}

			case 2:
			{
				cout << "		Enter the integer number what insert before first in list	" << endl << "	";
				int num;
				cin >> num;
				L.InsFirst(num);
				cout << "		Entered!	" << endl;
				break;
			}

			case 3:
			{
				cout << "		Enter the integer number what insert after last in list	" << endl << "	";
				int num;
				cin >> num;
				L.InsLast(num);
				cout << "		Entered!	" << endl;
				break;
			}

			case 4:
			{
				cout << "		Your list: " << endl << "	";
				L.Print();
				cout << endl;
				break;
			}

			case 5:
			{
				cout << "		Deleting first one..." << endl;
				L.DelFirst();
				cout << "		Deleted!" << endl;
				break;
			}

			case 6:
			{
				cout << "		Deleting current item..." << endl;
				L.DelCurr();
				cout << "		Deleted!" << endl;
				break;
			}

			case 7:
			{
				cout << "		Deleting last one..." << endl;
				L.DelLast();
				cout << "		Deleted!" << endl;
				break;
			}

			case 9:
			{
				cout << "				Operations:		" << endl;
				cout << "		0 - finish test;" << endl;
				cout << "		1 - insert element before current;" << endl;
				cout << "		2 - insert element before first;" << endl;
				cout << "		3 - insert element after last;" << endl;
				cout << "		4 - output list;" << endl;	
				cout << "		5 - delete first element;" << endl;
				cout << "		6 - delete current element;" << endl;
				cout << "		7 - delete last element;" << endl;
				cout << "		9 - operations;" << endl;
				break;
			}
			default:
			{
				cout << "		Unlnown command. Try again \n";
				break;
			}
		}
	}
}
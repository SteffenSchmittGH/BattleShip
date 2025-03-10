// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include <vector>
using namespace std;

// Add your project's header files here
// #include "CFraction.h"
// #include "GridPosition.h"
#include "part2tests.h"
#include "part3tests.h"
/**
 */
// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "BattleShip_schmitt_763534 started." << endl << endl;
	/*Testcase Excersize 2.2.1*/
#if 0
	cout << "Testcase 2.2.1" << endl;
	Board myBoard(10,10);
	ConsoleView myView(&myBoard);

	myBoard.getOwnGrid().placeShip(Ship{GridPosition{"B2"},GridPosition{"B4"}});
	myBoard.getOwnGrid().placeShip(Ship{GridPosition{"D4"},GridPosition{"G4"}});
	myBoard.getOwnGrid().placeShip(Ship{GridPosition{"F6"},GridPosition{"F9"}});

	cout << endl;
	myView.print();
#endif
	/*part2tests.cpp*/
#if 1
	Board myBoard(10,10);
	part1tests();
	part2test(&myBoard);
	part3tests(&myBoard);
	ConsoleView myView(&myBoard);
	myView.print();
#endif
	return 0;
}

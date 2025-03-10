/*
 * part2tests.cpp
 *
 *  Created on: 08.01.2025
 *      Author: schmi
 */
#include "part2tests.h"
using namespace std;

void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}


void part1tests () {
    // Test GridPosition constructor
    assertTrue(GridPosition{'A', 1}.isValid(), "A1 not considered valid");
    assertTrue(!GridPosition{'A', -1}.isValid(), "A-1 considered valid");
    assertTrue(!GridPosition{'@', 1}.isValid(), "@1 considered valid");
    GridPosition fromRowCol{'A', 1};
    GridPosition fromString{"A1"};
    assertTrue(fromRowCol.getRow() == fromString.getRow()
            && fromRowCol.getColumn() == fromString.getColumn(),
            "different constructors return different objects");

    // Test getters and cast to string
    GridPosition pos1 = GridPosition{'B', 13};
    assertTrue(pos1.getRow() == 'B',
            "GridPosition::GridPosition doesn't set row properly.");
    assertTrue(pos1.getColumn() == 13,
            "GridPosition::GridPosition doesn't set column properly.");
    assertTrue((string)pos1 == "B13", "Conversion to string fails.");

    // Test comparison
    assertTrue(!(GridPosition{"A1"} < GridPosition{"A1"}),
            "Same positions considered different by '<'");
    assertTrue(GridPosition{"A1"} < GridPosition{"B1"},
            "Position with bigger row not considered greater");
    assertTrue(GridPosition{"A1"} < GridPosition{"A2"},
            "Position with bigger column not considered greater");
    assertTrue(GridPosition{"C21"} == GridPosition{"C21"},
            "Equal positions not considered equal.");

    // Test Ship Constructor
    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"C3"}}.isValid(),
            "Can create non-aligned ship.");
    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B2"}}.isValid(),
            "Can create ship of size 1.");
    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B7"}}.isValid(),
            "Can create ship of size 6.");

    // Length
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.length() == 3,
            "Length is not 3");
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.length() == 4,
            "Length is not 4");

    // Occupied area
    assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.occupiedArea()
            == set<GridPosition>{GridPosition{"B2"}, GridPosition{"C2"},
                    GridPosition{"D2"}, GridPosition{"E2"}},
            "Occupied area not correct");
    cout << "Test_APT_LIPP" << endl;
    return;
}

void part2test (Board * board) {
	assertTrue(!(board->getOwnGrid().placeShip(Ship{GridPosition{"C3"},
							GridPosition{"E6"}})), "Diagonal Ship was placed!");
	assertTrue(board->getOwnGrid().placeShip(Ship{GridPosition{"I3"},
							  GridPosition{"I5"}}),"Ship could not be placed!");
	assertTrue(!(board->getOwnGrid().placeShip(Ship{GridPosition{"J4"},
						   GridPosition{"H4"}})),"Ships can cross each other!");
	assertTrue((board->getOwnGrid().placeShip(Ship{GridPosition{"D2"},
							 GridPosition{"D6"}})),"Ship could not be placed!");
	assertTrue(!((board->getOwnGrid().placeShip(Ship{GridPosition{"F2"},
				  GridPosition{"F6"}}))),"Two Ships with length 5 can be set!");
	assertTrue((board->getOwnGrid().placeShip(Ship{GridPosition{"A5"},
							 GridPosition{"A7"}})),"Ship could not be placed!");
	assertTrue((board->getOwnGrid().placeShip(Ship{GridPosition{"A1"},
		   GridPosition{"A3"}})),"More than 3 Ships with length 3 can be set!");
	assertTrue(!(board->getOwnGrid().placeShip(Ship{GridPosition{"J5"},
									 GridPosition{"J6"}})),"Ships can Allign!");

	assertTrue(board->getOwnGrid().placeShip(Ship{GridPosition{"I7"},
			                 GridPosition{"I10"}}),"Ship could not be placed!");
	assertTrue(board->getOwnGrid().placeShip(Ship{GridPosition{"G1"},
				              GridPosition{"J1"}}),"Ship could not be placed!");
	assertTrue(!(board->getOwnGrid().placeShip(Ship{GridPosition{"G10"},
			  GridPosition{"D10"}})),"3rd Ship with length 4 could be placed!");
	assertTrue(board->getOwnGrid().placeShip(Ship{GridPosition{"F3"},
		                      GridPosition{"G3"}}),"Ship could not be placed!");
	assertTrue(board->getOwnGrid().placeShip(Ship{GridPosition{"F5"},
		                      GridPosition{"G5"}}),"Ship could not be placed!");
	assertTrue(board->getOwnGrid().placeShip(Ship{GridPosition{"F7"},
		                      GridPosition{"G7"}}),"Ship could not be placed!");
	assertTrue(board->getOwnGrid().placeShip(Ship{GridPosition{"F9"},
		                      GridPosition{"G9"}}),"Ship could not be placed!");
	assertTrue(!(board->getOwnGrid().placeShip(Ship{GridPosition{"C10"},
		           GridPosition{"D10"}})),"5th Ship with length 2 was placed!");

	cout << "part2tests End!" << endl;
	return;
}

/*
 * part3tests.cpp
 *
 *  Created on: 08.01.2025
 *      Author: schmi
 */

#include "part3tests.h"
#include "Shot.h"
#include <iostream>
using namespace std;
void assertTrue3(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

void checkResult_hit(Shot::impact result, string str, bool success){
	bool successfully_hit = false;
	if(result == Shot::impact::HIT){
		successfully_hit = true;
	}else if(result == Shot::impact::NONE) {
		successfully_hit = false;
	}else if(result == Shot::impact::SUNKEN){
		successfully_hit = true;
	}else{
		cout << "Undefined behaviour for takeBlow()!" << endl;
	}
	if(success){
		assertTrue3(successfully_hit,str);
	}else{

	}
}


void checkResult_sunken(Shot::impact result, string str, bool success){
	bool sunken = false;
	if(result == Shot::impact::HIT){
		sunken = false;
	}else if(result == Shot::impact::NONE) {
		sunken = false;
	}else if(result == Shot::impact::SUNKEN){
		sunken = true;
	}else{
		cout << "No ship sunken!" << endl;
	}
	if(success){
		assertTrue3(sunken,str);
	}else{

	}
}

void part3tests(Board * board){
	Shot::impact result =
			             board->getOwnGrid().takeBlow(Shot{GridPosition{"F3"}});

	result = board->getOwnGrid().takeBlow(Shot{GridPosition{"B2"}});
	checkResult_hit(result, "HIT at B3!", false);

	result = board->getOwnGrid().takeBlow(Shot{GridPosition{"G3"}});
	checkResult_sunken(result, "Ship not Sunken!", true);

	result = board->getOwnGrid().takeBlow(Shot{GridPosition{"G1"}});
	checkResult_hit(result, "G1 missed!!", true);

	result = board->getOwnGrid().takeBlow(Shot{GridPosition{"H1"}});
	checkResult_hit(result, "H1 missed!", true);

	result = board->getOwnGrid().takeBlow(Shot{GridPosition{"I1"}});
	checkResult_hit(result, "I1 missed!", true);

	result = board->getOwnGrid().takeBlow(Shot{GridPosition{"J1"}});
	checkResult_hit(result, "J1 missed!", true);

	//testcases shotResult:

	board->getOppGrid().shotResult(Shot::impact::HIT, Shot{GridPosition{"F2"}});
	board->getOppGrid().shotResult(Shot::impact::HIT, Shot{GridPosition{"J3"}});
	board->getOppGrid().shotResult(Shot::impact::SUNKEN,
													  Shot{GridPosition{"F3"}});

	board->getOppGrid().shotResult(Shot::impact::NONE,
													  Shot{GridPosition{"C1"}});
	board->getOppGrid().shotResult(Shot::impact::HIT, Shot{GridPosition{"J6"}});

	board->getOppGrid().shotResult(Shot::impact::HIT, Shot{GridPosition{"E5"}});
	board->getOppGrid().shotResult(Shot::impact::HIT, Shot{GridPosition{"E8"}});
	board->getOppGrid().shotResult(Shot::impact::HIT, Shot{GridPosition{"E6"}});
	board->getOppGrid().shotResult(Shot::impact::SUNKEN,
													  Shot{GridPosition{"E7"}});

	board->getOppGrid().shotResult(Shot::impact::NONE,Shot{GridPosition{"A1"}});
	board->getOppGrid().shotResult(Shot::impact::HIT, Shot{GridPosition{"A2"}});
	cout << "part3tests End!" << endl;
	return;
}



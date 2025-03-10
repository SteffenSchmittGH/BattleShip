/*
 * ConsoleView.cpp
 *
 *  Created on: 12.12.2024
 *      Author: schmi
 */

#include "ConsoleView.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

ConsoleView::ConsoleView(Board* board) {
	// TODO Auto-generated constructor stub
	m_ownBoard = board;
	int actualRows;
	int actualCols;
	actualRows = (m_ownBoard->getOwnGrid().getRows() + 2);
	actualCols = (m_ownBoard->getOwnGrid().getColumns() + 1)*2 + 1;
	printBoard = new char*[actualRows];
	for(int i = 0; i < actualRows; ++i){
		printBoard[i] = new char[actualCols];
	}
	for (int currentRow = 0; currentRow < actualRows; ++currentRow) {
		printBoard[currentRow] = new char[actualCols];
	    for (int currentCol = 0; currentCol < actualCols; ++currentCol) {
	    	if(currentCol == actualCols/2||currentCol == actualCols/2+1){
	    		printBoard[currentRow][currentCol] = ' ';
	    	}else{
	    		printBoard[currentRow][currentCol] = '~';
	    	}
	    }
	}
	/*Place 1 at the most right position of 1st row*/
	for(int col = 0; col < actualCols; col++){
		if(col==actualCols-1 || col==actualCols/2-1){
			printBoard[0][col] = '1';
		}else{
			printBoard[0][col] = ' ';
		}
	}
	printBoard[1][1] = '1';
	for(int col = 2; col < actualCols/2; col++){
		if(col != actualCols/2-1){
			printBoard[1][col] = printBoard[1][col - 1] + 1;
		}else{
			printBoard[1][col] = '0';
		}
	}
	printBoard[2][0] = 'A';
	for(int row = 3; row < actualRows; row++){
			printBoard[row][0] = printBoard[row - 1][0] + 1;
	}
	printBoard[2][actualCols/2+1] = 'A';

	for(int row = 3; row < actualRows; row++){
			printBoard[row][actualCols/2+1] = printBoard[row-1][0] + 1;
	}
	printBoard[1][actualCols/2+2] = '1';
	for(int col = actualCols/2+3; col < actualCols; col++){
		if(col != actualCols-1){
			printBoard[1][col] = printBoard[1][col - 1] + 1;
		}else{
			printBoard[1][col] = '0';
		}
	}
	printBoard[1][0] = ' ';
}

ConsoleView::~ConsoleView() {
	// TODO Auto-generated destructor stub
	/*delete 2-D array*/
	// Delete each row
	int actualRows;
	actualRows = m_ownBoard->getOwnGrid().getRows();
	for (int rows = 0; rows < actualRows; ++rows) {
	    delete[] printBoard[rows]; // Delete each allocated row
	}

	// Delete the array of pointers
	delete[] printBoard;
}

void ConsoleView::print(){
	/*Identify numbers of rows and cols*/

	/*Allocate and init 2-D dynamic Array*/

	/*Find all Ships and put them into 2-D dynamic char array*/
	/*Therefore find all Ships, figure out their rows and cols and
	 * safe an mark in the 2-D Array, regardingly*/
	/* 1. Find all Ships */
	vector<Ship> ownShips = m_ownBoard->getOwnGrid().getShips();
	/* 2. Extract the first string and figure out rows and cols */
	/*Store the occupied Area of those ships*/
	set<GridPosition> occArea;
	/*Store the GridPositions of those ships*/
	GridPosition occupiedArea_GridPosition;
	/*Extract rows and columns*/
	char row = 0;
	int columns = 0;
	/*Since row is a char, some kind of conversion is needed.*/
	int row_int_occArea = 0;
	/*Extract ShotAt from OwnGrid.*/
	set<GridPosition> l_shotAt = m_ownBoard->getOwnGrid().getShots();
	for(auto it_shots=l_shotAt.begin();it_shots!=l_shotAt.end();it_shots++){
		/*Read out Rows and Columns*/
		columns = (*it_shots).getColumn();
		row = (*it_shots).getRow();
		row_int_occArea = (int)(row - 63);
		for(auto it = ownShips.begin(); it != ownShips.end(); it++){
			occArea = (*it).occupiedArea();
			for(auto it_else=occArea.begin();it_else!=occArea.end();it_else++){
				if(!((*it_else) == GridPosition(row,columns))){
					printBoard[row_int_occArea][columns] = '^';
					break;
				}
			}
		}
	}
	for(auto it = ownShips.begin(); it != ownShips.end(); it++){
		/*Iterate through the Ships Available on OwnBoard
		 * and get the occupiedArea*/
		occArea = (*it).occupiedArea();
		for(auto it_set = occArea.begin(); it_set != occArea.end(); it_set++){
			/*iterate through the occupied areas and read out the
			 * single GridPositions*/
			occupiedArea_GridPosition = *it_set;
			/*Read out Rows and Columns*/
			columns = occupiedArea_GridPosition.getColumn();
			row = occupiedArea_GridPosition.getRow();
			row_int_occArea = (int)(row - 63);
			printBoard[row_int_occArea][columns] = '#';
			for(auto it_shts=l_shotAt.begin();it_shts!=l_shotAt.end();it_shts++)
			{
				if((*it_shts) == GridPosition(row,columns)){
					printBoard[row_int_occArea][columns] = 'O';
					break;
				}
			}
		}
	}

	//fill OponentGrid
	//index of char** for opponentGrid must be adapted.
	//2.2 Get opponentGrid's sunkenShips and shots.
	std::vector<Ship> oppsnknShps=m_ownBoard->getOppGrid().getSunkenShips();
	std::map<GridPosition, Shot::impact> opp_shots;
	opp_shots = m_ownBoard->getOppGrid().getShotMap();
	// col 13  is where opp grid starts in printBoard
	/*mapping:
	 * col: 13 -> (0) offset
	 */
	// printBoard[2][13] = 'F';
	//2.3 get col and row from opp_shots pair.first
	char opp_row;
	int opp_col;
	int opp_grid_offset_row = 0;
	int opp_grid_offset_col = 12;// 12 due to B1,G1,.. never has 0 as column
	for(auto pair : opp_shots){
		opp_row = pair.first.getRow() + opp_grid_offset_row;
		opp_col = pair.first.getColumn() + opp_grid_offset_col;
		if(pair.second == Shot::impact::HIT){
			printBoard[(int)(opp_row-63)][opp_col] = 'O';
		}else if(pair.second == Shot::impact::NONE){
			printBoard[(int)(opp_row-63)][opp_col] = '^';
		}else{
			// Sunken handled via opp_sunkenShips
		}
	}
	std::set<GridPosition> occArea1;
	for(auto it_snknShps=oppsnknShps.begin();
									    it_snknShps!=oppsnknShps.end();
																  it_snknShps++)
	{
		occArea1 = (*it_snknShps).occupiedArea();
		for(auto it_occArea=occArea1.begin();
										it_occArea!=occArea1.end();
																   it_occArea++)
		{
			int column = (*it_occArea).getColumn() + opp_grid_offset_col;
			char row = (*it_occArea).getRow();
			int row2int = (int)(row-63) + opp_grid_offset_row;
			printBoard[row2int][column] = '#';
		}
	}
	/*3. cout 2-D char array*/
	int actualRows;
	int actualCols;
	actualRows = (m_ownBoard->getOwnGrid().getRows() + 2);
	actualCols = (m_ownBoard->getOwnGrid().getColumns() + 1)*2 + 1;

	for(int row = 0; row < actualRows; row++){
		for(int col = 0; col < actualCols; col++){
			cout << printBoard[row][col] << " ";
		}
		cout << endl;
	}
	return;
}


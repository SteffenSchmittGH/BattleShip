/*
 * OpponentGrid.cpp
 *
 *  Created on: 12.12.2024
 *      Author: schmi
 */

#include "OpponentGrid.h"
using namespace std;
#include <iostream>

OpponentGrid::OpponentGrid(int rows, int columns) {
	m_rows = rows;
	m_columns = columns;
}

OpponentGrid::~OpponentGrid() {

}

int OpponentGrid::getRows(){
	return m_rows;
}

int OpponentGrid::getColumns(){
	return m_columns;
}


void OpponentGrid::shotResult(Shot::impact const result, Shot shot){
	m_shots.insert(pair<GridPosition, Shot::impact>(shot.getTargetPosition(),
																	   result));
	if(result == Shot::impact::SUNKEN){
		char row = shot.getTargetPosition().getRow(); //last hit
		int column = shot.getTargetPosition().getColumn(); //last hit
		int col_array[6] = { };
		int col_array_index = 0;
		bool rowFound = false;
		bool goforrow = true;
		for(auto pair : m_shots){
			if(pair.first.getRow() == row &&
			(pair.second==Shot::impact::HIT||pair.second==Shot::impact::SUNKEN))
			{
				char row_lower = row+1;
				char row_up = row-1;
				auto it_lower = m_shots.find(
							    GridPosition{row_lower,pair.first.getColumn()});
				auto it_up = m_shots.find(
							     GridPosition{row_up,pair.first.getColumn()});
				if(it_lower != m_shots.end()){
				   if(m_shots.at(GridPosition{row_lower,pair.first.getColumn()})
														  == Shot::impact::HIT){
						goforrow = false;
				   }
				}
				if(it_up != m_shots.end()){
					if(m_shots.at(GridPosition{row_up,pair.first.getColumn()})
														  == Shot::impact::HIT){
						goforrow = false;
					}
				}
				if(goforrow){
					col_array[col_array_index++] = pair.first.getColumn();
					rowFound = true;
				}
			}
		}
		if(rowFound){
			for(int cols = 0; cols < 6; cols++){
				if(col_array[cols+1] == 0){
					GridPosition stern(row,col_array[cols]);
					GridPosition bow(row,col_array[0]);
					m_sunkenShips.push_back(Ship(bow,stern));
					break;
				}
			}
		}
		col_array_index = 0;
		char row_array[6] = { };
		bool colFound = false;
		bool goforcol = true;
		for(auto pair : m_shots){
			if(pair.first.getColumn() == column &&
			(pair.second==Shot::impact::HIT||pair.second==Shot::impact::SUNKEN))
			{
				int col_right = column + 1;
				int col_left = column -1;
			    auto it_right = m_shots.find(
			    				   GridPosition{pair.first.getRow(),col_right});
				auto it_left = m_shots.find(
						            GridPosition{pair.first.getRow(),col_left});
				if(it_right != m_shots.end()){
					if(m_shots.at(GridPosition{row,col_right})
													      == Shot::impact::HIT){
						goforcol = false;
					}
				}
				if(it_left != m_shots.end()){
					if(m_shots.at(GridPosition{row,col_left})
													      == Shot::impact::HIT){
						goforcol = false;
					}
				}
				if(goforcol){
					row_array[col_array_index++] = pair.first.getRow();
					colFound = true;
				}
			}
		}
		if(colFound){
			for(int rows =0; rows < 6; rows++){
				if(row_array[rows+1] == '\0'){
					GridPosition stern(row_array[rows],column);
					GridPosition bow(row_array[0],column);
					m_sunkenShips.push_back(Ship(bow,stern));
					break;
				}
			}
		}
	}
}


std::vector<Ship> OpponentGrid::getSunkenShips(){
	return m_sunkenShips;
}

std::map<GridPosition,Shot::impact> OpponentGrid::getShotMap(){
	return m_shots;
}

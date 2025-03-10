/*
 * OwnGrid.cpp
 *
 *  Created on: 11.12.2024
 *      Author: schmi
 */

#include "OwnGrid.h"
#include <iostream>
using namespace std;


OwnGrid::OwnGrid(int rows, int cols) : m_rows(rows), m_cols(cols) {
	m_trackNumberOfPlacedShips.insert(pair<int,int>(5,1));
	m_trackNumberOfPlacedShips.insert(pair<int,int>(4,2));
	m_trackNumberOfPlacedShips.insert(pair<int,int>(3,3));
	m_trackNumberOfPlacedShips.insert(pair<int,int>(2,4));
	countHITs = 0;
}

OwnGrid::~OwnGrid() {
	// TODO Auto-generated destructor stub
}

int OwnGrid::getRows(){
	return m_rows;
}

int OwnGrid::getColumns(){
	return m_cols;
}

bool OwnGrid::placeShip(const Ship& addShip){
/*********************No Diagonal Ships*********************************/
	if(!addShip.isValid()){
		return false;
	}
/************* No Overlap (Ships don't touch each other) **********************/
	set<GridPosition> alreadyBlockedArea;
	set<GridPosition> occupiedAreaNewShip;
	occupiedAreaNewShip = addShip.occupiedArea();
	for(auto it_ownShips = m_ownShips.begin();
									it_ownShips != m_ownShips.end();
																  it_ownShips++)
	{
		alreadyBlockedArea = (*it_ownShips).blockedArea();
		for(auto it_blocked = alreadyBlockedArea.begin();
									it_blocked != alreadyBlockedArea.end();
																   it_blocked++)
		{
			for(auto it_occupiedNewShip = occupiedAreaNewShip.begin();
							it_occupiedNewShip != occupiedAreaNewShip.end();
														   it_occupiedNewShip++)
			{
				if(*it_blocked == *it_occupiedNewShip){
					return false;
				}
			}
		}
	}
/*********** Track Ships number and length ************************************/
	for(auto pair : m_trackNumberOfPlacedShips){
		//cout << pair.first << " - " << pair.second << endl;
		if(pair.first == addShip.length()){
			if(pair.second > 0){
				int a = pair.second - 1;
				m_trackNumberOfPlacedShips[pair.first] = a;
			}else{
				/*No Ships with length addShip.length() available anymore*/
				return false;
			}
		}
	}
/**************Keep Maximum Number of Ships and Set Ship **********************/
	if(m_ownShips.size() < MAX_OWN_SHIPS){
		m_ownShips.push_back(addShip);
		return true;
	}else{
		return false;
	}
}

const vector<Ship> OwnGrid::getShips(){
	return m_ownShips;
}

Shot::impact OwnGrid::takeBlow(const Shot& shot){
	int countHITGridPositions = 0;
	bool sunkenShips[10] = { };
	int indexSunkenShips = 0;
	// creating array which shows which ship already sunken
	for(auto it_ownShips = m_ownShips.begin();
										it_ownShips != m_ownShips.end();
																  it_ownShips++)
	{
		set<GridPosition> occArea = (*it_ownShips).occupiedArea();
		countHITGridPositions = 0;
		for(auto it_occArea = occArea.begin();
										it_occArea != occArea.end();
																   it_occArea++)
		{
			for(auto it_shotAt = m_shotAt.begin();
											it_shotAt != m_shotAt.end();
																	it_shotAt++)
			{
				if(*it_occArea == *it_shotAt){
					countHITGridPositions++;
					break;
				}
			}
			if(countHITGridPositions == (*it_ownShips).length()){
				sunkenShips[indexSunkenShips] = 1;
			}
		}
		indexSunkenShips++;
	}
	//start actual processing of vector with unsunken ships
	m_shotAt.insert(shot.getTargetPosition());

	//2. make a copy of the vector of ships without sunken ships
	vector<Ship> leftShips;
	indexSunkenShips = 0;
	for(auto it_ownShips = m_ownShips.begin();
										it_ownShips != m_ownShips.end();
																  it_ownShips++)
	{
		if(!sunkenShips[indexSunkenShips++]){
			leftShips.push_back(*it_ownShips);
		}
	}
	//3. use this copied vector instead of origin ship vector
	set<GridPosition> occupiedArea;
	for(auto it_over_own_ships = leftShips.begin();
										it_over_own_ships != leftShips.end();
															it_over_own_ships++)
	{
		occupiedArea = (*it_over_own_ships).occupiedArea();
		for(auto it_over_occupiedArea = occupiedArea.begin();
								it_over_occupiedArea != occupiedArea.end();
														 it_over_occupiedArea++)
		{
			for(auto it_over_shotAt = m_shotAt.begin();
										it_over_shotAt != m_shotAt.end();
															   it_over_shotAt++)
			{
				if(*it_over_occupiedArea == *it_over_shotAt){
					countHITs++;
				}
			}
		}
		if(countHITs == (*it_over_own_ships).length()){
			countHITs = 0;
			return Shot::SUNKEN;
		}
		countHITs = 0;
	}
	for(auto it_over_own_ships = leftShips.begin();
							it_over_own_ships != leftShips.end();
														it_over_own_ships++)
	{
		occupiedArea = (*it_over_own_ships).occupiedArea();
		for(auto it_over_occupiedArea = occupiedArea.begin();
						it_over_occupiedArea != occupiedArea.end();
													 it_over_occupiedArea++)
		{
			if(*it_over_occupiedArea == shot.getTargetPosition()){
				countHITs = 0;
				return Shot::HIT;
			}
		}
	}
	return Shot::NONE;
}

std::set<GridPosition> OwnGrid::getShots(){
	return m_shotAt;
}

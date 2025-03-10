/*
 * Ship.cpp
 *
 *  Created on: 10.12.2024
 *      Author: schmi
 */

#include "Ship.h"
#include <iostream>
using namespace std;


Ship::Ship() : m_bow(), m_stern(){

}

Ship::Ship(const GridPosition& bow, const GridPosition& stern)
: m_bow(bow), m_stern(stern) {
	//m_bow = bow;
	//m_stern = stern;
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}


bool Ship::isValid() const{
	bool row_column_validation = false;
	if(m_stern.isValid() && m_bow.isValid()){
		row_column_validation = true;
	}

	bool horizontal_or_vertical = false;
	if(m_bow.getColumn()==m_stern.getColumn()||m_bow.getRow()==m_stern.getRow())
	{
		horizontal_or_vertical = true;
	}

	bool length_validation;
	if(this->length() >= 2 && this->length() <= 5){
		length_validation = true;
	}else{
		length_validation = false;
	}

	if(row_column_validation && length_validation && horizontal_or_vertical){
		return true;
	}

	return false;
}

GridPosition Ship::getBow() const{
	return m_bow;
}

GridPosition Ship::getStern() const{
	return m_stern;
}

int Ship::length() const{
	bool boat_horizontal;
	if(m_bow.getColumn() == m_stern.getColumn()){
		boat_horizontal = false;
	}

	if(m_bow.getRow() == m_stern.getRow()){
		boat_horizontal = true;
	}

	int diff = 0;
	if(!boat_horizontal){
		if(m_bow.getRow() > m_stern.getRow()){
			diff = m_bow.getRow() - m_stern.getRow() + 1;
		}else{
			diff = m_stern.getRow() - m_bow.getRow() + 1;
		}
	}else{
		if(m_bow.getColumn() > m_stern.getColumn()){
			diff = m_bow.getColumn() - m_stern.getColumn() + 1;
		}else{
			diff = -m_bow.getColumn() + m_stern.getColumn() + 1;
		}
	}

	return diff;
}

std::set<GridPosition> Ship::occupiedArea() const{
	set<GridPosition> occupied_area;
	if(m_bow.getColumn() == m_stern.getColumn()){
		if(m_stern.getRow() > m_bow.getRow()){// == doesnt make sense here
			for(char i = m_stern.getRow(); i >= m_bow.getRow(); i--){
				GridPosition GridPositionToAdd(i,m_bow.getColumn());
				occupied_area.insert(GridPositionToAdd);
			}
		}else{
			for(char i = m_bow.getRow(); i >= m_stern.getRow(); i--){
				GridPosition GridPositionToAdd(i,m_bow.getColumn());
				occupied_area.insert(GridPositionToAdd);
			}
		}
	}

	if(m_bow.getRow() == m_stern.getRow()){
		if(m_stern.getColumn() > m_bow.getColumn()){
			for(int i = m_stern.getColumn(); i >= m_bow.getColumn(); i--){
				GridPosition GridPositionToAdd(m_bow.getRow(),i);
				occupied_area.insert(GridPositionToAdd);
			}
		}else {
			for(int i = m_bow.getColumn(); i >= m_stern.getColumn(); i--){
				GridPosition GridPositionToAdd(m_bow.getRow(),i);
				occupied_area.insert(GridPositionToAdd);
			}
		}
	}

	return occupied_area;
}

std::set<GridPosition> Ship::blockedArea() const{
	set<GridPosition> GridPosition_1;
	set<GridPosition> occArea = this->occupiedArea();
	bool obere_grenze = false;
	bool untere_grenze = false;
	bool linke_grenze = false;
	bool rechte_grenze = false;
	bool keine_grenze = false;

	 //iterate through occupied Area

	for(auto it = occArea.begin(); it != occArea.end(); it++){
		if((*it).getColumn() == 1){
			linke_grenze = true;
		}
		if((*it).getColumn() == 10){
			rechte_grenze = true;
		}
		if((*it).getRow() == 'A'){
			obere_grenze = true;
		}
		if((*it).getRow() == 'J'){
			untere_grenze = true;
		}
		if(!(obere_grenze||untere_grenze||rechte_grenze||linke_grenze))
		{
			keine_grenze = true;
		}
		//1 nur wenn obere_grenze, linke_grenze und rechte_grenze (keine)
		if(obere_grenze||linke_grenze||rechte_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow() + 1,(*it).getColumn());
			GridPosition_1.insert(myGrid);
		}
		//2 nur wenn untere_grenze, obere_grenze und rechte_grenze (keine)
		if(untere_grenze||obere_grenze||rechte_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow() - 1,(*it).getColumn());
			GridPosition_1.insert(myGrid);
		}
		//3 obere_grenze,untere_grenze,linke_grenze
		if(untere_grenze||obere_grenze||linke_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow(),(*it).getColumn() + 1);
			GridPosition_1.insert(myGrid);
		}
		//4 obere_grenze,untere_grenzen,rechte_grenzen
		if(untere_grenze||obere_grenze||rechte_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow(),(*it).getColumn() - 1);
			GridPosition_1.insert(myGrid);
		}
		//5 obere_grenze, linke_grenze
		if(obere_grenze||linke_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow() + 1,(*it).getColumn() + 1);
			GridPosition_1.insert(myGrid);
		}
		//6 obere_grenze, rechte_grenze
		if(obere_grenze||rechte_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow() + 1,(*it).getColumn() - 1);
			GridPosition_1.insert(myGrid);
		}
		//7 untere_grenze, linke_grenze
		if(untere_grenze||linke_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow() - 1,(*it).getColumn() + 1);
			GridPosition_1.insert(myGrid);
		}
		//8 untere_grenze, rechte_grenze
		if(untere_grenze||rechte_grenze||keine_grenze){
			GridPosition myGrid((*it).getRow() - 1,(*it).getColumn() - 1);
			GridPosition_1.insert(myGrid);
		}

	}

	return GridPosition_1;
}


/*
 * GridPosition.cpp
 *
 *  Created on: 10.12.2024
 *      Author: schmi
 */

#include "GridPosition.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

GridPosition::GridPosition(){
	m_row = '0';
	m_column = 0;
}

GridPosition::GridPosition(char row, int column) {
	if(row >= 'A' && row <= 'Z'){
		m_row = row;
	}else{
		m_row = '0';
	}
	if(column >= 1){
		m_column = column;
	}else{
		m_column = 0;
	}
}

GridPosition::GridPosition(string position) {
	if(position[0] >= 'A' && position[0] <= 'Z'){
		m_row = position[0];
	}else{
		m_row = '0';
	}
	if(stoi(position.substr(1))){
		m_column = stoi(position.substr(1));
	}else{
		m_column = 0;
	}
}

GridPosition::~GridPosition() {
	// TODO Auto-generated destructor stub
}

bool GridPosition::isValid() const{
	bool ret1,ret2;
	/*Check Validation for m_row*/
	if(m_row >= 'A' && m_row <= 'Z'){
		ret1 = true;
	}else{
		ret1 = false;
	}
	/*Check Validation for m_column*/
	if(m_column >= 1){
		ret2 = true;
	}else{
		ret2 = false;
	}
	return ret1&ret2;
}

char GridPosition::getRow() const{
	return m_row;
}

int GridPosition::getColumn() const{
	return m_column;
}

bool GridPosition::operator <(const GridPosition other) const{
	if(this->getRow() < other.getRow()){
		return true;
	}else if(other.getRow() == this->getRow()){
		if(this->getColumn() < other.getColumn()){
			return true;
		}
	}else{
		return false;
	}
	return false;
}



bool GridPosition::operator ==(const GridPosition other)const{
	if(other.getRow() == m_row && other.getColumn() == m_column){
		return true;
	}
	return false;
}

GridPosition::operator std::string() const {
	string field_column;
	field_column = to_string(m_column);
	string ret = m_row + field_column;
	return ret;
}

std::ostream& operator<<(std::ostream& os, GridPosition obj) {
    os <<  obj.getRow() << obj.getColumn() << " "; // Customize as needed
    return os;
}

/*
 * Board.cpp
 *
 *  Created on: 12.12.2024
 *      Author: schmi
 */

#include "Board.h"
/**
 * @brief Constructor for the Board class.
 *
 * @param rows The number of rows in the board.
 * @param cols The number of columns in the board.
 */
Board::Board(int rows, int cols) : m_ownGrid(rows,cols), m_oppGrid(rows,cols){

}
/**
 * @brief Destructor for the Board class.
 */
Board::~Board() {
	// TODO Auto-generated destructor stub
}
/**
 * @brief Get the number of rows in the board.
 *
 * @return The number of rows.
 */
int Board::getRows(){
	return m_ownGrid.getRows();
}
/**
 * @brief Get the number of columns in the board.
 *
 * @return The number of columns.
 */
int Board::getColumns(){
	return m_ownGrid.getColumns();
}
/**
 * @brief Get a reference to the player's own grid.
 *
 * @return A reference to the OwnGrid object.
 */
OwnGrid& Board::getOwnGrid(){
	return m_ownGrid;
}
/**
 * @brief Get a reference to the opponent's grid.
 *
 * @return A reference to the OpponentGrid object.
 */
OpponentGrid& Board::getOppGrid(){
	return m_oppGrid;
}


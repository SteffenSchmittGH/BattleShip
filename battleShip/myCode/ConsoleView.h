/*
 * ConsoleView.h
 *
 *  Created on: 12.12.2024
 *      Author: schmi
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"
class ConsoleView
{
private:
	Board* m_ownBoard;
	///< A pointer that points to the created instance of #Board.
	char** printBoard;
	///< 2-Dim. array for printing placed, HIT, Sunken Ships and misses, etc.
public:
	/**
	 * @brief Constructor for the ConsoleView class. Initializes the two
	 * dimensional array printBoard with row description and column desctiption.
	 *
	 * @param board Pointer to the Board object.
	 */
	ConsoleView(Board* board);
	/**
	 * @brief Destructor for the ConsoleView class.
	 */
	virtual ~ConsoleView();
	/**
	 * @brief Print the current state of the board to the console.
	 */
	void print();
};

#endif /* CONSOLEVIEW_H_ */

/*
 * GridPosition.h
 *
 *  Created on: 10.12.2024
 *      Author: schmi
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>
class GridPosition
{
private:
char m_row;
///< The row index of a #GridPosition
int m_column;
///< The column index of a #GridPosition represented as a numeric value.

public:
/**
 * @brief Default constructor for the GridPosition class.
 * Initializes the position to invalid default values.
 */
	GridPosition();

	/**
	 * @brief Parameterized constructor to initialize GridPosition with row
	 * and column.
	 *
	 * @param row Character representing the row ('A'-'Z').
	 * @param column Integer representing the column (>= 1).
	 */
	GridPosition(char row, int column);

	/**
	 * @brief Constructor to initialize GridPosition from a string position
	 * (e.g., "A1").
	 *
	 * @param position String containing the position in the format "RowColumn".
	 */
	GridPosition(std::string position);

	/**
	 * @brief Checks if the current GridPosition is valid.
	 * GridPosition is Valid if Letter is between A and Z and Number
	 * greater or equal 1.
	 *
	 * @return true if the position is valid, false otherwise.
	 */
	bool isValid() const;

	/**
	 * @brief Returns row of GridPosition
	 *
	 * @return Character of the GridPositions row
	 */
	char getRow() const;

	/**
	 * @brief Gets the column integer of the GridPosition.
	 *
	 * @return Integer representing the column.
	 */
	int getColumn() const;

	/**
	 * @brief Converts the GridPosition to a string representation.
	 *
	 * @return String representing the GridPosition (e.g., "A1").
	 */
	operator std::string() const;

	/**
	 * @brief Overloaded equality operator for comparing two GridPositions.
	 *
	 * @param other Another GridPosition to compare with.
	 * @return true if both GridPositions are equal.
	 */
	bool operator==(const GridPosition other)const;

	/**
	 * @brief Overloaded less-than operator for comparing two GridPositions.
	 * Order A1 to J10
	 *
	 * @param other Another GridPosition to compare with.
	 * @return true if this GridPosition is less than the other.
	 */
	bool operator < (const GridPosition other) const;

	/**
	 * @brief Destructor for the GridPosition class.
	 */
	virtual ~GridPosition();
};
/**
 * @brief Overloaded stream insertion operator for outputting a GridPosition.
 *
 * @param os Output stream object.
 * @param obj GridPosition to output.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, GridPosition obj) ;
#endif /* GRIDPOSITION_H_ */

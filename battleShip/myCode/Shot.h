/*
 * Shot.h
 *
 *  Created on: 18.12.2024
 *      Author: schmi
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"
class Shot {
private:
	GridPosition m_targetPosition;
	///< #GridPosition of a #Shot.
public:
	enum impact {NONE,HIT,SUNKEN,};
	///< public enum, describes impact of shots
	/**
	 * @brief Constructor for the Shot class.
	 *
	 * @param targetPosition The GridPosition representing the target of the
	 * shot.
	 *
	 * Initializes a Shot object with the specified target position.
	 */
	Shot(GridPosition targetPosition);

	/**
	 * @brief Destructor for the Shot class.
	 *
	 * Currently, no specific cleanup is required.
	 */
	virtual ~Shot();

	/**
	 * @brief Retrieves the target position of the shot.
	 *
	 * @return The GridPosition representing the target of the shot.
	 */
	GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */

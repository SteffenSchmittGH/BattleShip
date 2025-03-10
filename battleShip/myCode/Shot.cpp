/*
 * Shot.cpp
 *
 *  Created on: 18.12.2024
 *      Author: schmi
 */

#include "Shot.h"

Shot::Shot(GridPosition targetPosition) {
	// TODO Auto-generated constructor stub
	m_targetPosition = targetPosition;
}

Shot::~Shot() {
	// TODO Auto-generated destructor stub
}

GridPosition Shot::getTargetPosition() const{
	return m_targetPosition;
}


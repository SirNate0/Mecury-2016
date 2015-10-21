/*
 * Walls.h
 *
 *  Created on: Oct 21, 2015
 *      Author: nathan
 */

#pragma once

#include <math.h>
#include <algorithm>

class Wall
{
private:
	const double L;
	double d1, d2, r1, r2, theta, phi;
	double straightToWall;
	//phi is the angle relative to parallel to the wall
public:
	void calculate(double R1, double R2)
	{
		r1 = R1;
		r2 = R2;
		theta = atan(L/(r2 - r1));
		d2 = r2 * sin(theta);
		d1 = r1 * sin(theta);
		straightToWall = r2 * tan(theta) - L;
	}
	double angleFromWall()
	{
		return phi;
	}
	double distanceToWallTransverse()
	{
		return std::min(r1,r2);
	}
	double distanceToWallForward()
	{
		return straightToWall;
	}
};




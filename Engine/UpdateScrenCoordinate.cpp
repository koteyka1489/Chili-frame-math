#include "UpdateScrenCoordinate.h"




UpdateScrenCoordinate::UpdateScrenCoordinate(std::vector<Shape>& shapesIN)
	:
	shapesUPS(shapesIN)
	
{
}

UpdateScrenCoordinate UpdateScrenCoordinate::operator=(UpdateScrenCoordinate& rhs)
{
	shapesUPS = rhs.shapesUPS;
	return *this;
}

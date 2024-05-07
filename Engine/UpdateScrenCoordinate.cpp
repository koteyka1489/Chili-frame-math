#include "UpdateScrenCoordinate.h"




UpdateScrenCoordinate::UpdateScrenCoordinate(std::vector<Drawable> shapesIN, Camera& cam)
	:
	shapesUPS(shapesIN),
	cam(cam)
	
{
}

UpdateScrenCoordinate UpdateScrenCoordinate::operator=(UpdateScrenCoordinate& rhs)
{
	shapesUPS = rhs.shapesUPS;
	return *this;
}

void UpdateScrenCoordinate::Update()
{
	for (auto& s : shapesUPS)
	{
		s.Update();
	}
}

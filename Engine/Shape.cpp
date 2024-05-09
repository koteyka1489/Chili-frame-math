#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(float x, float y, int nVert, float radius, Color clr)
{
	this->clr = clr;
	const float dtheta = 2.0f * 3.14159f / float(nVert);

	for (int i = 0; i < nVert; i++)
	{
		float nx = x + radius * cos(float(i) * dtheta);
		float ny = y + radius * sin(float(i) * dtheta);
		points.emplace_back(nx, ny);
	}

	center = Vec2{ x, y };
	this->radius = radius;
}

Shape& Shape::operator=(const Shape& rhs)

{
	points = rhs.points;
	clr = rhs.clr;
	center = rhs.center;
	radius = rhs.radius;
	speedSqale = rhs.speedSqale;
	sizeScale = rhs.sizeScale;
	speedVec = rhs.speedVec;
	rebounded = rhs.rebounded;
	return *this;
}

Shape::Shape(const Shape& rhs)
{
	*this = rhs;
}


void Shape::SetCenter()
{
	float sumX = 0;
	float sumY = 0;
	for (int i = 0; i < points.size(); i++)
	{
		sumX += points[i].x;
		sumY += points[i].y;
	}
	center.x = sumX / points.size();
	center.y = sumY / points.size();
	
}

void Shape::UpdateSpeed(Vec2 dir)
{
	speedVec = dir;
}

void Shape::Move()
{
	for (int i = 0; i < points.size(); i++)
	{
		points[i] += speedVec;
	}
	SetCenter();
}


void Shape::CheckCollision( Stick stick)
{
	//if (DistancePointLine(stick.GetStartPoint(), stick.GetEndPoint(), this->GetCenter()) < this->GetRadius()
	//	&& !this->GetRebounded())
	//{
	//	collideSound.Play();
	//	Vec2 w = stick.GetStickVec().Normalize();
	//	Vec2 v = this->GetSpeed();
	//	this->SetSpeed(w * (v * w) * 2.f - v);
	//	this->SetRebounded(true);
	//}
	//this->Move();
}

Vec2 Shape::GetCenter()
{

	return center;
}

float Shape::GetRadius()
{
	return radius;
}

Vec2 Shape::GetSpeed()
{
	return speedVec;
}

void Shape::SetSpeed(Vec2 speed_in)
{
	speedVec = speed_in;
}

bool Shape::GetRebounded()
{
	return rebounded;
}

void Shape::SetRebounded(bool reb)
{
	rebounded = reb;
}

void Shape::SetPointsOfset(Vec2 ofset)
{
	for (auto& p : points)
	{
		p += ofset;
	}
}

void Shape::SetPointsScale(float scl)
{
	for (auto& p : points)
	{
		p *= scl;
	}
}

std::vector<Vec2> Shape::GetPoints()
{
	return points;
}

Color Shape::GetColor()
{
	return clr;
}








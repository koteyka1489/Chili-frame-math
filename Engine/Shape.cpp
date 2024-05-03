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

	endAddPoints = true;
	center = Point{ x, y };
	this->radius = radius;
}

Shape& Shape::operator=(const Shape& rhs)

{
	points = rhs.points;
	clr = rhs.clr;
	endAddPoints = rhs.endAddPoints;
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

void Shape::Update(MainWindow& wnd)
{
	if (!endAddPoints)
	{
		const auto e = wnd.mouse.Read();


		if (e.GetType() == Mouse::Event::Type::LPress)
		{

			if (!points.empty())
			{
				if (points[points.size() - 1].x != wnd.mouse.GetPosX() || points[points.size() - 1].y != wnd.mouse.GetPosY())
				{
					points.emplace_back(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
				}
			}
			else
			{
				points.emplace_back(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
			}
		}

		if (points.size() >= nVert)
		{
			endAddPoints = true;
		}
	}
	else
	{
		SetCenter();
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		endAddPoints = false;
		points.clear();
	}

}

void Shape::Draw(Graphics& gfx, Vec2 cameraOfsset, float scaleCameraMod)
{

	if (endAddPoints)
	{
		for (int i = 0; i < points.size() - 1; i++)
		{

			Vec2 vec{ points[i], points[i + 1]};
			vec *= scaleCameraMod;
			vec += cameraOfsset;
			gfx.DrawLine(vec);
		}

		Vec2 vecEnd(points[points.size() - 1], points[0]);
		vecEnd *= scaleCameraMod;
		vecEnd += cameraOfsset;
		gfx.DrawLine(vecEnd);
	}
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
		points[i] = points[i].AddVec(speedVec);
	}
	SetCenter();
}

void Shape::MoveCamera(Vec2 dir)
{
	for (int i = 0; i < points.size(); i++)
	{
		points[i] = points[i].AddVec(dir);
	}
	SetCenter();
}

void Shape::ScaleFromCenterShape(MainWindow& wnd, bool dir)
{

	if (dir)
	{

		for (int i = 0; i < points.size(); i++)
		{
			Vec2 nv(points[i], center);

			nv = nv * sizeScale;
			points[i] = points[i].AddVec(nv);
		}
	}
	else
	{
		for (int i = 0; i < points.size(); i++)
		{
			Vec2 nv(center, points[i]);

			nv = nv * sizeScale;
			points[i] = points[i].AddVec(nv);
		}
	}
	
}

void Shape::CheckCollision( Stick stick)
{
	if (DistancePointLine(stick.GetStartPoint(), stick.GetEndPoint(), this->GetCenter()) < this->GetRadius()
		&& !this->GetRebounded())
	{
		collideSound.Play();
		Vec2 w = stick.GetStickVec().Normalize();
		Vec2 v = this->GetSpeed();
		this->SetSpeed(w * (v * w) * 2.f - v);
		this->SetRebounded(true);
	}
	this->Move();
}

Point Shape::GetCenter()
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

void Shape::Rotate(float angle)
{
	for (int i = 0; i < points.size(); i++)
	{
		points[i].Rotate(angle, center);
	}
}





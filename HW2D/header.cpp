#include "header.h"

void point_t::print() const
{
	std::cout << "x: " << x << ", y: " << y << "\n";
}

bool point_t::valid() const
{
	return  x != NAN && y != NAN;
}

bool point_t::equal(const point_t& rhs) const
{
	if (valid() && rhs.valid())
	{
		return (abs(x - rhs.x) < flt_tolerance) && (abs(y - rhs.y) < flt_tolerance);
	}
	return false;
}

void line_t::print() const
{
	std::cout << "y = " << a << " * x + " << b << "\n";
}

bool line_t::valid() const
{
	return !isnan(a) && !isnan(b) && !isinf(a) && !isinf(b);
}

line_t::line_t(const point_t& p1, const point_t& p2)
{
	a = (p2.y - p1.y) / (p2.x - p1.x);
	b = -a * p1.x + p1.y;
}

float poligon_t::square() const
{
	if (points.size() < 3)
	{
		return 0.0f;
	}
	//Формула площади Гаусса
	float tmp_sum = 0.0f;
	for (auto index = 0; index < points.size() - 1; index++)
	{
		tmp_sum += points[index].x * points[index + 1].y;
		tmp_sum -= points[index + 1].x * points[index].y;
	}
	tmp_sum += points.front().y * points.back().x - points.front().x * points.back().y;
	tmp_sum = 0.5f * abs(tmp_sum );
	return tmp_sum;
}

bool poligon_t::exist(const point_t& check_point) const
{
	for (const auto& vec_point : points) 
	{ 
		if (check_point.equal(vec_point)) 
		{ 
			return true; 
		} 
	} 
	return false;
}

#pragma once

#include <iostream>
#include <vector>

// TODO Чем это определение отличается от определения через define?
// immediately: define проставит вместо имени значение (на этапе препроцесинга). const float создаст глобальную переменную.
 
#define flt_tolerance 1.0E-5f

//#define flt_tolerance 0.00001

//const float flt_tolerance = 1.0E-5f;

enum side_t {INTER_SIDE, LEFT_SIDE, RIGHT_SIDE};

struct point_t
{
	float x = NAN, y = NAN;
	void print() const;
	bool valid() const;
	bool equal(const point_t& rhs) const;
};

// y = a * x + b
struct line_t
{
	float a = 1.0f, b = 0.0f;
	void print() const;
	bool valid() const;
	line_t(const point_t& p1, const point_t& p2);

	//Получаем сторону в которой находится третья точка треугольника
	//side_t get_inner_side(const point_t& point) const;

	//Получаем точку пересечения двух прямых
	point_t intersection_point() const;
};


struct poligon_t
{
	//point_t* points = nullptr;
	std::vector<point_t> points;
	
	void print() const;
	bool valid() const;
	//poligon_t();
	//~poligon_t() { delete[] points; };



	float square() const;
	//TODO Как еще можно проверить существование элемента в vector? 
	bool exist(const point_t& check_point) const;
	void add(const point_t& point) { if (point.valid()) { points.push_back(point); } };
};
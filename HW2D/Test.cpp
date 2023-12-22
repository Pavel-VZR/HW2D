#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>

#include "header.h"

//BOOST_AUTO_TEST_CASE(myTestCase)
//{
//  BOOST_TEST(1 == 1);
//  BOOST_TEST(true);
//}


BOOST_AUTO_TEST_SUITE(point_t_test)

BOOST_AUTO_TEST_CASE(point_t_equals)
{
	point_t p1{ 1, 1 };
	point_t p2{ 1, 1 };

	BOOST_TEST(p1.equal(p2));
	BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(point_t_not_equals)
{
	point_t p1{ 1, 1 };
	point_t p2{ 1, 2 };

	BOOST_CHECK_EQUAL(p1.equal(p2), false);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(point_t_test)

BOOST_AUTO_TEST_CASE(line_t_constructor_simple)
{
	point_t p1{ 1, 1 };
	point_t p2{ 2, 2 };

	line_t line{ p1, p2 };

	BOOST_CHECK(line.valid());
	BOOST_CHECK(abs(line.a - 1.0f) < flt_tolerance);
	BOOST_CHECK(abs(line.b) < flt_tolerance);
}

BOOST_AUTO_TEST_CASE(line_t_valid)
{
	point_t p1{ 1, 1 };
	point_t p2{ 1, 2 };

	line_t line{ p1, p2 };

	BOOST_CHECK_EQUAL(line.valid(), false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(poligon_t_test)

BOOST_AUTO_TEST_CASE(poligon_t_square)
{
	poligon_t poligon;
	poligon.add(point_t{ 1,1 });
	poligon.add(point_t{ 2,2 });

	BOOST_CHECK_EQUAL(poligon.square(), 0.0f);

	poligon.add(point_t{ 3,1 });

	BOOST_CHECK_EQUAL(poligon.square(), 1.0f);

	poligon.add(point_t{ 2,0 });

	BOOST_CHECK_EQUAL(poligon.square(), 2.0f);
}

BOOST_AUTO_TEST_SUITE_END()
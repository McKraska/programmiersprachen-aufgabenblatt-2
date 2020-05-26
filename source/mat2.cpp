#include "mat2.hpp"

Mat2& Mat2::operator *=(Mat2 const& m) {

	Mat2 c = *this;

	c.e_00 = e_00 * m.e_00 + e_10 * m.e_01;
	c.e_10 = e_00 * m.e_10 + e_10 * m.e_11;
	c.e_01 = e_01 * m.e_00 + e_11 * m.e_01;
	c.e_11 = e_01 * m.e_10 + e_11 * m.e_11;

	this = c;
	
	return *this;

}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2) {

	Mat2 c = m1;

	c *= m2;

	return c;

}

Vec2 operator *(Mat2 const& m1, Vec2 const& v) {

	Vec2 c = v;

	c.x = m1.e_00 * v.x + m1.e_10 * v.y;
	c.y = m1.e_01 * v.x + m1.e_11 * v.y;

	return c;

}
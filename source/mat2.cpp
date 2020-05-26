#include "mat2.hpp"
#include <math.h>

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

float Mat2::det() const {

	return e_00* e_11 - e_10 * e_01;

}

Mat2 inverse(Mat2 const& m) {

	if (m.det() == 0) {
		return m; 
	} // Wir können Keine inverse Ausrechenen wenn der Derterminante 0 ist

	Mat2 c{ m.e_11 / m.det(), -m.e_10 / m.det(), -m.e_01 / m.det(), m.e_00 / m.det()};

	return c;

}

Mat2 transpose(Mat2 const& m) {

	return Mat2 { m.e_00, m.e_01, m.e_10, m.e_11};

}

Mat2 make_rotation_mat2(float phi) {

	Mat2 c{ cos(phi), -sin(phi), sin(phi), cos(phi)};

	return c;

}



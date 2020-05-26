#include "mat2.hpp"

Mat2& Mat2::operator *=(Mat2 const& m) {

	e_00 *= m.e_00;
	e_01 *= m.e_01;
	e_10 *= m.e_10;
	e_11 *= m.e_11;

	return *this;


}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2) {

}

Mat2 operator *(Mat2 const& m1, Vec2 const& v) {

}
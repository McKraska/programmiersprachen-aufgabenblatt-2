#include "vec2.hpp"

Vec2& Vec2::operator +=(Vec2 const& v){

	x += v.x;
	y += v.y;

	return *this;

}

Vec2& Vec2::operator -=(Vec2 const& v) {

	x -= v.x;
	y -= v.y;

	return *this;

}

Vec2& Vec2::operator *=(float s) {

	x *= s;
	y *= s;

	return *this;

}

Vec2& Vec2::operator /=(float s) {

	x /= s;
	y /= s;

	return *this;

}

Vec2 operator +(Vec2 const& u, Vec2 const& v) {

	Vec2 c = { 0.0f, 0.0f };

	c += u;
	c += v;

	return c;

}

Vec2 operator -(Vec2 const& u, Vec2 const& v) {

	Vec2 c = { 0.0f, 0.0f };

	c -= u;
	c -= v;

	return c;

}

Vec2 operator *(Vec2 const& v, float s) {

	Vec2 c = { 0.0f, 0.0f };

	c *= s;
	c *= s;

	return c;

}

Vec2 operator /(Vec2 const& v, float s) {

	Vec2 c = { 0.0f, 0.0f };

	c /= s;
	c /= s;

	return c;

}

Vec2 operator *(float s, Vec2 const& v) {

	return v*s;

}

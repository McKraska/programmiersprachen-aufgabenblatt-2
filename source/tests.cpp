#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

TEST_CASE("describe_checkvec", "[checkvec]") {

	Mat2 c{};
	Mat2 d{2.5f, 4.5f, -6.5f, -8.5f};

	Vec2 a;
	Vec2 b{ 5.1f, -9.3f };

	std::cout << a.x << " " << a.y << "\n";
	std::cout << b.x << " " << b.y << "\n";

	a.x += b.x;
	a.y += b.y;

	std::cout << a.x << " " << a.y << "\n";
	std::cout << b.x << " " << b.y << "\n";

	REQUIRE(a.x == b.x);
	REQUIRE(a.y == b.y);

	b.x *= 2;
	b.y *= 2;

	std::cout << a.x << " " << a.y << "\n";
	std::cout << b.x << " " << b.y << "\n";

	REQUIRE(b.x == 2 * a.x);
	REQUIRE(b.y == 2 * a.y);

	b.x /= 2;
	b.y /= 2; 

	std::cout << a.x << " " << a.y << "\n";
	std::cout << b.x << " " << b.y << "\n";

	REQUIRE(b.x == a.x);
	REQUIRE(b.y == a.y);

	a.x -= b.x;
	a.y -= b.y;

	std::cout << a.x << " " << a.y << "\n";
	std::cout << b.x << " " << b.y << "\n";

	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	// a und b sind jetzt wieder in deren Ausganswerte von 0.0 , 0.0 und 5.1 , -9.3.
	// Test für Randfälle

	b.x / a.x;
	b.y / a.y;

	std::cout << b.x << " " << b.y << "\n";

	REQUIRE(b.x == 5.1f);
	REQUIRE(b.y == -9.3f);

	a.x -= b.x;
	a.y -= b.y;

	std::cout << a.x << " " << a.y << "\n";

	REQUIRE(a.x == -5.1f);
	REQUIRE(a.y == 9.3f);

	a.x= 0.0f;
	b.x= 5.1f;
	a.y = 0.0f;
	b.y = -9.3f;

	std::cout << a.x << " " << a.y << "\n";
	std::cout << b.x << " " << b.y << "\n";

	a.x *= a.y;
	b.x *= b.y;

	std::cout << a.x << " " << a.y << "\n";
	std::cout << b.x << " " << b.y << "\n";

	REQUIRE(a.x == 0.0f);
	REQUIRE(b.x == -47.43f);

	a.x = 0.0f;
	a.y = 0.0f;
	b.x = 5.1f;
	b.y = -9.3f;

	// Matrix tests 2.5

	std::cout << c.e_00 << " " << c.e_10 << " " << c.e_01 << " " << c.e_11 << "\n";
	std::cout << d.e_00 << " " << d.e_10 << " " << d.e_01 << " " << d.e_11 << "\n";

	REQUIRE(c.e_00 == 1.0f);
	REQUIRE(c.e_10 == 0.0f);
	REQUIRE(c.e_01 == 0.0f);
	REQUIRE(c.e_11 == 1.0f);
	REQUIRE(d.e_00 == 2.5f);
	REQUIRE(d.e_10 == 4.5f);
	REQUIRE(d.e_01 == -6.5f);
	REQUIRE(d.e_11 == -8.5f);

	c.e_00 *= d.e_00;

	std::cout << c.e_00 << "\n";

	REQUIRE(c.e_00 == d.e_00);

	c.e_00 *= c.e_01;

	std::cout << c.e_00 << "\n";

	REQUIRE(c.e_00 == c.e_01); // Multiplication mit übergabe auf 0

	c.e_00 = 1.0f;

	d.e_00 *= d.e_10;

	std::cout << d.e_00 << "\n";

	REQUIRE(d.e_00 == 11.25f);

	d.e_00 *= 10.0f;

	std::cout << d.e_00 << "\n";

	REQUIRE(d.e_00 == 112.50f);

	d.e_00 *= b.x;

	std::cout << d.e_00 << "\n";

	REQUIRE(d.e_00 == 573.75f);

	d.e_00 = 2.5f;

	d.e_00 *= d.e_11;

	std::cout << d.e_00 << "\n";

	REQUIRE(d.e_00 == -21.25);

 }

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
  
}

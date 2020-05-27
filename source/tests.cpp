#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

TEST_CASE("describe_checkvec", "[checkvec]") {

	Vec2 a{};
	Vec2 b{ 5.1f, -9.3f };

	a += b;

	std::cout << a.x << a.y << "\n";

	REQUIRE(a.x == b.x);
	REQUIRE(a.y == b.y);

	a -= b;

	std::cout << a.x << a.y << "\n";

	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);

	b *= 10;

	std::cout << b.x << b.y << "\n";

	REQUIRE(b.x == 51.0f);
	REQUIRE(b.y == -93.0f);

	b /= 10;

	std::cout << b.x << b.y << "\n";

	REQUIRE(b.x == 51.0f/10);
	REQUIRE(b.y == -93.0f/10);

	Vec2 c{ a + b };

	std::cout << c.x << c.y << "\n";

	REQUIRE(c.x == b.x);
	REQUIRE(c.y == b.y);

	c = a - b ;

	std::cout << c.x << c.y << "\n";

	REQUIRE(c.x == -b.x);
	REQUIRE(c.y == -b.y);

	c = b / 0.0f;

	std::cout << c.x << c.y << "\n";

	c = b / 2 , 5;

	std::cout << c.x << c.y << "\n";

	// Vector tests Fertig

	Mat2 d{ -1.0f, -2.0f, 3.0f, 4.0f };
	Mat2 e{ 10.0f, 20.0f, -30.0f, -40.0f };

	Mat2 f{ d * e };

	std::cout << f.e_00 << f.e_10 << f.e_01 << f.e_11 << "\n";

 }

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
  
}

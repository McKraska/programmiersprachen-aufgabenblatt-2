#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("describe_checkvec", "[checkvec]") {

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

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
  
}

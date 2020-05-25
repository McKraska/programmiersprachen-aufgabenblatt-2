#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"


Vec2 a;
Vec2 b{ 5.1f, -9.3f };
Vec2 c{};

Vec2 checkvec(Vec2 c) {

	Vec2 t1{ 1.0f, -1.0 };
	Vec2 t2{ t1 + c };
	
	return t2;

}

TEST_CASE("describe_checkvec", "[checksum]") {

	REQUIRE(checkvec(5.0f, -10.0f) == 6.0f, -11.0f);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include <vector>


TEST_CASE("Example test", "[example_tag]")
{
	REQUIRE(1 == 1);
	REQUIRE(2 == 2);
}

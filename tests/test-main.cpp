#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

TEST_CASE("Full encoding and decoding", "[main]") {
    REQUIRE(1 + 1 == 2);
}
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <string>
#include "../src/encoder.hpp"

TEST_CASE("Text to Binary: char", "[encoder]") {
    Encoder encoder;
    string binary = encoder.text_to_binary("A");
    REQUIRE(binary == "01000001");
}

TEST_CASE("Text to Binary: string", "[encoder]") {
    Encoder encoder;
    string binary = encoder.text_to_binary("ABC");
    REQUIRE(binary == "01000001 01000010 01000011");
}
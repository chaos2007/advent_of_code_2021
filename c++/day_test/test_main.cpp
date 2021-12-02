#define CATCH_CONFIG_MAIN
#include "../common/catch.hpp"

int test_add(int a, int b) {
    return a + b;
}

TEST_CASE("Test Add Function works", "[basic]") {
    REQUIRE( test_add(1, 2) == 3 );
    REQUIRE( test_add(2, 2) == 4 );
}



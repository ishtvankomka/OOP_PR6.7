#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Predicate.h"
TEST_CASE( "Arguments initialized") {
    int a2[5] = { 1, -2, 0, 4, -5 };
    int c[5] = { 0, 0, 0, 0, 0 };
    Predicate<int> *zero = new Negative<int>();
    int n = erase_copy_if(&a2[0], &a2[5], &c[0], *zero);
    
    REQUIRE( c[0] == -2);
    REQUIRE( c[1] == -5);
}

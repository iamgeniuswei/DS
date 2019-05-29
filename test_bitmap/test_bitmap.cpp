#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../bitmap/bitmap.h"
#include <iostream>
TEST_CASE("1. test set(int i)")
{

    Bitmap *bitmap = new Bitmap();
    bitmap->set(10);
    REQUIRE(bitmap->test(10) == true);
    delete bitmap;
}

TEST_CASE("2. test unset(int i)")
{
    Bitmap *bitmap = new Bitmap();
    bitmap->unset(10);
    REQUIRE(bitmap->test(10) == false);
    delete bitmap;
}

TEST_CASE("3. test test(int i)")
{

}

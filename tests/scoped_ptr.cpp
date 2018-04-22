#include <catch.hpp>
#include <sstream>
#include "scoped_ptr"

TEST_CASE("Create ptr")
{
    scoped_ptr <int> My_ptr;
    REQUIRE(My_ptr == nullptr);
}

TEST_CASE("Test ptr(n), op *, op get()")
{
    scoped_ptr <int> My_ptr1(new int(1));
    int *ptr_1 = My_ptr1.get();
    scoped_ptr <int> My_ptr2(new int(2));
    int ptr_2 = *My_ptr2;
    REQUIRE(*ptr_1 == 1);
    REQUIRE(ptr_2 == 2);
}

TEST_CASE("Test swap")
{
    scoped_ptr <int> My_ptr1(new int(3));
    scoped_ptr <int> My_ptr2(new int(6));
    My_ptr1.swap(My_ptr2);
    int *ptr_1 = My_ptr1.get();
    int ptr_2 = *My_ptr2;
    REQUIRE(*ptr_1 == 6);
    REQUIRE(ptr_2 == 3);
}

TEST_CASE("Test reset")
{
    scoped_ptr <int> My_ptr1(new int(3));
    My_ptr1.reset(new int(6));
    int *ptr = My_ptr1.get();
    REQUIRE(*ptr == 6);
}

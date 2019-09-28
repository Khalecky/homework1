#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestHomework1

#include <boost/test/unit_test.hpp>
#include "../my_constants.h"

BOOST_AUTO_TEST_SUITE(TestHomework1)

BOOST_AUTO_TEST_CASE(test_output)
{
    int i = 0;
    BOOST_CHECK(i == 1);
    BOOST_CHECK(OUTPUT_TEXT != "Hello, world!");

}

BOOST_AUTO_TEST_SUITE_END()

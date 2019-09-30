//#define BOOST_TEST_DYN_LINK   //2 variants: 1 - define here; 2- like compile option is CMakeLists
#define BOOST_TEST_MODULE TestHomework1

#include <boost/test/unit_test.hpp>
#include "../version.h"

BOOST_AUTO_TEST_SUITE(TestHomework1)

BOOST_AUTO_TEST_CASE(test_version)
{
    BOOST_CHECK(PROJECT_VERSION_PATCH > 0);
}

BOOST_AUTO_TEST_SUITE_END()

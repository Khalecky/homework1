cmake_minimum_required(VERSION 3.2)

project(homework1 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

message("**** START CREATE MAKEFILE FOR ${PROJECT_NAME}: version=${PROJECT_VERSION}; build_number=${PROJECT_VERSION_PATCH} ****")
message("************************************************************************")
#message("project directory is " ${PROJECT_SOURCE_DIR})

#find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)
add_executable(homework1_app main.cpp)
add_executable(homework1_tests tests/test_module.cpp)

set_target_properties(homework1_app homework1_tests PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

#options for binary test-file only
set_target_properties(homework1_tests PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    #INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}   #TODO variable does't exists
)

target_link_libraries(homework1_tests ${Boost_LIBRARIES})


install(TARGETS homework1_app RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT "halecky@mail.ru")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(test1 homework1_tests)

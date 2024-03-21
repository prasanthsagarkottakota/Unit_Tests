cmake_minimum_required(VERSION 3.22)
project("Unit_Testing_C++")
find_package(GTest REQUIRED)

# Include directories
include_directories(src/headers)

# Add source files
set(SOURCES
    src/product.cpp
    src/customer.cpp
    src/order.cpp
    src/ecommerce_platform.cpp
    )

add_executable(a.out 
               test_project.cpp 
               src/ecommerce_platform.cpp 
               src/product.cpp 
               src/customer.cpp 
               src/order.cpp)
#add_executable(a.out main.cpp)
target_link_libraries(a.out ${GTEST_LIBRARIES})

enable_testing()
add_test(add a.out)


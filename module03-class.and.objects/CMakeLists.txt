cmake_minimum_required(VERSION 3.23)
project(module03_class_and_objects)

set(CMAKE_CXX_STANDARD 20)

add_executable(module03_class_and_objects main.cpp account.cpp account.h customer.cpp customer.h bank.cpp bank.h)
add_executable(test_banking test_banking.cpp account.cpp account.h customer.cpp customer.h bank.cpp bank.h)
add_executable(exercise7 exercise07.cpp account.cpp account.h customer.cpp customer.h bank.cpp bank.h)

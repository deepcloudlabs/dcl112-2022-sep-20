cmake_minimum_required(VERSION 3.23)
project(module03_class_and_objects)

set(CMAKE_CXX_STANDARD 20)

add_executable(module03_class_and_objects main.cpp account.cpp account.h customer.cpp customer.h bank.cpp bank.h)
add_executable(test_banking test_banking.cpp savings_account.cpp savings_account.h checking_account.cpp checking_account.cpp account.cpp account.h customer.cpp customer.h bank.cpp bank.h)
add_executable(exercise7 exercise07.cpp account.cpp account.h customer.cpp customer.h bank.cpp bank.h)
add_executable(study_inheritance study_inheritance.cpp account.cpp account.h customer.cpp customer.h bank.cpp bank.h checking_account.cpp checking_account.h)
add_executable(study_deleting_copy_constructor_and_assignment_operator study_deleting_copy_constructor_and_assignment_operator.cpp)
add_executable(study-destructor-in-inheritance study-destructor-in-inheritance.cpp)
add_executable(study-public-private-inheritance study-public-private-inheritance.cpp)
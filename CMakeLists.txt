cmake_minimum_required(VERSION 3.17)
project(aeda2020_portagens)

set(CMAKE_CXX_STANDARD 14)

add_executable(aeda2020_portagens main.cpp Classes/Toll.cpp Classes/Toll.h Classes/Vehicle.cpp Classes/Vehicle.h Classes/Employees.cpp Classes/Employees.h Classes/Employee.cpp Classes/Employee.h Classes/SystemNetwork.cpp Classes/SystemNetwork.h Classes/Highway.cpp Classes/Highway.h Classes/Highways.cpp Classes/Highways.h Classes/Lane.cpp Classes/Lane.h Classes/VehiclesClasses.cpp Classes/VehiclesClasses.h Classes/Movement.cpp Classes/Movement.h Classes/Movements.cpp Classes/Movements.h)
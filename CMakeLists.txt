cmake_minimum_required(VERSION 3.17)
project(aeda2020_portagens)

set(CMAKE_CXX_STANDARD 14)

add_executable(aeda2020_portagens main.cpp Classes/TollsNetwork.cpp Classes/TollsNetwork.h Classes/Toll.cpp Classes/Toll.h Classes/Type.cpp Classes/Type.h Classes/Vehicle.cpp Classes/Vehicle.h Classes/Employees.cpp Classes/Employees.h Classes/Lanes.cpp Classes/Lanes.h)
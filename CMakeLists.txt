cmake_minimum_required(VERSION 3.10)
project(turn_p2p_client)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Boost REQUIRED COMPONENTS system)
find_package(TURNClient REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${TURNCLIENT_INCLUDE_DIR})

add_executable(turn_p2p_client
    main.cpp
    turn_client.cpp
)

target_link_libraries(turn_p2p_client
    ${Boost_LIBRARIES}
    ${TURNCLIENT_LIBRARY}
)

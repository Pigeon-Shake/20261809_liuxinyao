cmake_minimum_required(VERSION 3.10)
project(TicketHomework CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(ticket
    src/main.cpp
    src/Ticket.cpp
)

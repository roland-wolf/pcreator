cmake_minimum_required(VERSION 3.5)

project(pcreator)

find_package(Qt5Core)

set(SRCS main.cpp
    repo.cpp
    )

set(HDRS )

qt5_wrap_cpp(MOCS ${HDRS} )

add_executable(pcreator ${SRCS} ${MOCS} )
target_link_libraries(pcreator Qt5::Core )

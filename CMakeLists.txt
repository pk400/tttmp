project(tttmp)

add_executable(tttmp src/main.cpp src/tttmp.cpp src/grid.cpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(tttmp ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

install(TARGETS tttmp DESTINATION bin)

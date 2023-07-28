cmake_minimum_required(VERSION 3.4.0)

project(cpoly)

add_executable(cpoly_example example/Context.c example/glContext.c
                             example/vkContext.c)

target_include_directories(cpoly_example PUBLIC ${CMAKE_SOURCE_DIR}
                                                ${CMAKE_SOURCE_DIR}/example)

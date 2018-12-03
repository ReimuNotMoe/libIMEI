cmake_minimum_required(VERSION 2.8)
project(libIMEI)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        libIMEI.c
        libIMEI.h)

add_library(IMEI ${SOURCE_FILES})
add_library(IMEI_Static STATIC ${SOURCE_FILES})
set_target_properties(IMEI_Static PROPERTIES OUTPUT_NAME IMEI)

add_executable(imei_verify imei_verify.c)
target_link_libraries(imei_verify IMEI)
add_executable(imei_generate imei_generate.c)
target_link_libraries(imei_generate IMEI)

install(FILES libIMEI.h DESTINATION include/)
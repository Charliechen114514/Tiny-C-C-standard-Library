cmake_minimum_required(VERSION 2.8)
project(CCSTDC_String_RUN_DEMO)
 
set(SOURCES
    ./source/CCSTDC_String.c
    testOutDemo.c
)
 
set(HEADERS
    ../include/CCSTDC_String.h
    ../include/CCSTDC_Utils.h
)
 
add_executable(Main
    ${SOURCES}
    ${HEADERS}
)


file(GLOB SOURCES *.cpp )

add_executable(MyBase ${SOURCES})

target_include_directories(MyBase PRIVATE ./include)

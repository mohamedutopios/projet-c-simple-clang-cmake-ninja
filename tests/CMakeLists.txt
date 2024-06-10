cmake_minimum_required(VERSION 3.15)
project(Tests)

include_directories(${PROJECT_SOURCE_DIR}/../include)

add_executable(run_tests 
    test_button.c 
    ../src/button.c 
    ../src/gpio.c 
    ../src/led_control.c
)

enable_testing()
add_test(NAME ButtonTests COMMAND run_tests)

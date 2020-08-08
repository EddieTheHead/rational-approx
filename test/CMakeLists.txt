add_executable(test_rational_approx_app test_rational_approx.c)
 

include_directories( ../src/)

target_link_libraries(test_rational_approx_app unity)
 
add_test(test_main test_rational_approx_app)
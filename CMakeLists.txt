project("Rational_Approx" C) 
cmake_minimum_required(VERSION 3.0)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(TARGET_GROUP test)


#(TARGET_GROUP production CACHE STRING "What Should I Build?")


add_subdirectory(src) 

if(TARGET_GROUP STREQUAL release)
# If we had any files that ONLY were compiled into our release, for example startup code,
  # it's really handy to put it here. 
elseif(TARGET_GROUP STREQUAL test)
# Our tests need to let CTest know we're running tests 
  include(CTest)

# It also needs to understand we have code in source and test directories 
add_subdirectory(Unity) 
  add_subdirectory(test) 
else() 
  message(FATAL_ERROR "I don't know the TARGET_GROUP you gave me!")
endif()
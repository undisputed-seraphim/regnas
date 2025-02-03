
file(GLOB_RECURSE regnas_src "${CMAKE_CURRENT_SOURCE_DIR}/regnas/*")
add_executable(regnas ${regnas_src})
target_link_libraries(regnas PRIVATE quill::quill Boost::boost Boost::system)
target_include_directories(regnas SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})

macro(add_simple_test _name)
    # invoke built-in add_executable
    add_executable(${_name}_test ${_name}_test.cc ${_name}.cc)
    if (TARGET ${_name}_test)
        target_link_libraries(${_name}_test ${DEPS})
    endif ()
endmacro()

macro(add_leetcode_test _num _name)
    # invoke built-in add_executable
    add_executable(${_num}_${_name}_test ${_num}_${_name}/${_name}_test.cc ${_num}_${_name}/${_name}.cc)
    if (TARGET ${_num}_${_name}_test)
        target_link_libraries(${_num}_${_name}_test ${DEPS})
    endif ()
endmacro()

macro(add_test_target _name)
    # invoke built-in add_executable
    add_executable(${_name} ${_name}.cpp)
    if (TARGET ${_name})
        target_link_libraries(${_name} ${DEPS})
    endif ()
endmacro()

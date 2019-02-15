
macro(add_simple_test _name)
    # invoke built-in add_executable
    add_executable(${_name}_test ${_name}_test.cc ${_name}.cc)
    if (TARGET ${_name}_test)
        target_link_libraries(${_name}_test ${DEPS})
    endif ()
endmacro()

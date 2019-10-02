
macro(add_simple_test _name)
    # invoke built-in add_executable
    add_executable(${_name}_test ${_name}_test.cc ${_name}.cc)
    if (TARGET ${_name}_test)
        target_link_libraries(${_name}_test ${DEPS})
    endif ()
endmacro()

macro(add_test_target _name)
    # invoke built-in add_executable
    add_executable(${_name} ${_name}.cpp)
    if (TARGET ${_name})
        target_link_libraries(${_name} ${DEPS})
    endif ()
endmacro()

macro(add_solution_test _dir)
    # invoke built-in add_executable
    add_executable(${_dir}_solution_test ${_dir}/solution_test.cc ${_dir}/solution.cc ${_dir}/solution.h)
    if (TARGET ${_dir}_solution_test)
        target_link_libraries(${_dir}_solution_test ${DEPS})
    endif ()
endmacro()


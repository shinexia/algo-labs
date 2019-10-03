macro(add_test_cc _name)
  # invoke built-in add_executable
  add_executable(${_name} ${ARGN})
  target_link_libraries(${_name} ${TEST_DEPS})
  # add_test(NAME ${_name} COMMAND ${_name})
endmacro()

macro(add_simple_test _name)
  # invoke built-in add_executable
  add_executable(${_name}_test ${_name}_test.cc ${_name}.cc ${_name}.h)
  target_link_libraries(${_name}_test ${TEST_DEPS})
  # add_test(NAME ${_name}_test COMMAND ${_name}_test)
endmacro()

macro(add_solution_test _dir)
  # invoke built-in add_executable
  add_executable(${_dir}_solution_test ${_dir}/solution_test.cc
                                       ${_dir}/solution.cc ${_dir}/solution.h)
  target_link_libraries(${_dir}_solution_test ${TEST_DEPS})
  # add_test(NAME ${_dir}_solution_test COMMAND ${_dir}_solution_test)
endmacro()

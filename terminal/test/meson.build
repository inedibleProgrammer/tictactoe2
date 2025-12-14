gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

test_src = files('test_terminal.cpp')


dependencies = [
  gtest_dep,
  gmock_dep,
  terminal_dep,
]

exe = executable(
  'test_terminal',
  test_src,
  dependencies : dependencies,
  install : true,
)

test('test_terminal', exe)

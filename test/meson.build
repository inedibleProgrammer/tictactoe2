
gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')



test_src = files('test_tictactoe.cpp')


dependencies = [
  gtest_dep,
  gmock_dep,
  ttt_dep,
]

exe = executable(
  'test_ttt',
  test_src,
  dependencies : dependencies,
  install : true,
  # link_with : ttt_lib,
)

test('test_ttt', exe)

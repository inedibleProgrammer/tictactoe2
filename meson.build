project(
  'tictactoe2',
  'cpp',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

app_src = files('tictactoe2.cc')

test_src = files('test_ttt.cc')


dependencies = [
  gtest_dep,
  gmock_dep
]

exe = executable(
  'test_ttt',
  test_src,
  dependencies : dependencies,
  install : true,
)

test('test_ttt', exe)

project(
  'tictactoe2',
  'cpp',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

top_build_dir = meson.current_build_dir()
top_source_dir = meson.current_source_dir()

gtest_proj = subproject('gtest')


subdir('ttt')
subdir('test')
# subdir('cli')



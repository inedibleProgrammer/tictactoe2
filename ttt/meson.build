ttt_src = files('tictactoe.cpp')

ttt_lib = static_library(
  'ttt_lib',
  ttt_src,
  # include_directories : include_directories('.')
)


ttt_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with: ttt_lib
)


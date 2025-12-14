terminal_src = files('linux_terminal.cpp')


terminal_lib = static_library(
  'terminal_lib',
  terminal_src,
)

terminal_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with: terminal_lib
)

subdir('test')
subdir('example')

example_src = files('main.cpp')


exe = executable(
  'example',
  example_src,
  dependencies : terminal_dep,
  install : true,
  link_args : ['-Wl,-Map=example_map']
)


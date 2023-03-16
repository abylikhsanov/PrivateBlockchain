project('PrivateBlockchain', 'cpp', default_options : ['cpp_std=c++17'],
  version : '0.1',
  default_options : ['warning_level=3'])


block_dependencies = [dependency('openssl'), dependency('pthread-stubs')]

include = include_directories('include')

blocklib = library('block', sources : ['src/block.cpp'], include_directories : include,
  dependencies : block_dependencies, override_options : ['cpp_std=c++17']
  )

exec = executable('main', sources : ['src/main.cpp'], link_with : [blocklib], include_directories : include,
  dependencies : [block_dependencies], override_options : ['cpp_std=c++17']
)

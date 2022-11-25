project('lua callbacks', 'c')

source = ['src/main.c']
lua = dependency('lua')

executable('c_code', sources: source, dependencies: lua)

lua_code = 'src/test.lua'
custom_target('lua script',
  input: 'src/test.lua',
  output: 'test.lua',
  command : ['cp', '@INPUT@', '@OUTPUT@'],
  install: false,
  build_by_default: true)

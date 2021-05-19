subdir('App')
subdir('Frame')

wx = dependency('wxwidgets', required : true)

executable(
  'calculator', ['main.cpp'],
  include_directories: includes,
  link_with: [Frame_lib,App_lib],
  dependencies:[wx]
)
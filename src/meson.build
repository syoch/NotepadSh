subdir('App')
subdir('Frame')

executable(
  'calculator', ['main.cpp'],
  include_directories: includes,
  link_with: [
    Frame_lib,
    App_lib
  ],
  dependencies:[
    dependency('wxwidgets', required : true)
  ]
)
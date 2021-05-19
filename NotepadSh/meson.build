includes+=include_directories('./include')


subdir('Frame')

executable(
  'NotepadSh', [
    'main.cpp',
    'MyApp.cpp'
  ],
  dependencies:[
    dependency('wxwidgets', required : true),
    Frame
  ]
)
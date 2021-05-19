includes+=include_directories('./include')


subdir('Application')

executable(
  'NotepadSh', [
    'main.cpp'
  ],
  dependencies:[
    dependency('wxwidgets', required : true),
    App
  ]
)
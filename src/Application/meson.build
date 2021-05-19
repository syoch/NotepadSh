App=declare_dependency(
  link_with : [
    library(
      'App', ['MyApp.cpp','MyFrame.cpp'],
      include_directories: [include_directories('.'),includes],
      dependencies:[dependency('wxwidgets', required : true)]
    )
  ],
  include_directories : ['.']
)
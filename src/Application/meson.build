includes+=include_directories('.')

App_lib=library(
  'App', ['MyApp.cpp','MyFrame.cpp'],
  include_directories: includes,
  dependencies:[wx]
)

App=declare_dependency(
  link_with : App_lib,
  include_directories : includes
)
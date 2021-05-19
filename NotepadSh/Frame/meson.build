includes+=include_directories('.')

Frame_lib=library(
  'Frame', ['MyFrame.cpp'],
  include_directories: includes,
  dependencies:[wx]
)

Frame=declare_dependency(
  link_with : Frame_lib,
  include_directories : includes
)
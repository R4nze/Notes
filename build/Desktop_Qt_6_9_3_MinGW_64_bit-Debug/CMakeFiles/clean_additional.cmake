# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appNotes_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appNotes_autogen.dir\\ParseCache.txt"
  "appNotes_autogen"
  )
endif()

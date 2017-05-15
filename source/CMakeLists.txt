# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  rectangle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  vec2.cpp  
  tests.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  glew.c)
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})

# Build clock
add_executable(clock
  window.cpp
  glew.c
  clock.cpp
  vec2.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build aufgabe1
add_executable(aufgabe1
  aufgabe1.cpp
  )

# Build aufgabe2bis4
add_executable(aufgabe2bis4
  aufgabe2bis4.cpp
  )

# Build aufgabe5
add_executable(aufgabe5
  aufgabe5.cpp
  )


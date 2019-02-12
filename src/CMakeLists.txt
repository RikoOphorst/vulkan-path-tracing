# Source Files
file(GLOB SrcFiles "*.h" "*.cc")
add_msvc_precompiled_header("pch.pch" "pch.cpp" SrcFiles)
source_group("src" FILES ${SrcFiles})

add_executable(vkpt 
  ${SrcFiles}
)

set_property(TARGET vkpt PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

target_link_libraries(vkpt PRIVATE 
  assimp
  glfw
  stb
  optix
  vulkan
  glm
)

add_custom_command(
  TARGET vkpt POST_BUILD 
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ASSIMP_DLLS}
  $<TARGET_FILE_DIR:vkpt>
)

add_custom_command(
  TARGET vkpt POST_BUILD 
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${OPTIX_DLLS}
  $<TARGET_FILE_DIR:vkpt>
)
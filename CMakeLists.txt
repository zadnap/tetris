cmake_minimum_required(VERSION 3.31.5)
project(tetris VERSION 1.1.0 LANGUAGES C CXX)

set(CPACK_PACKAGE_NAME "Tetris")
set(CPACK_PACKAGE_VENDOR "Zadnap Inc")
set(CPACK_PACKAGE_CONTACT "nguyenbahoangminh06@gmail.com")

set(CPACK_GENERATOR "NSIS")
set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_NAME}")
set(CPACK_NSIS_PACKAGE_NAME "${CPACK_PACKAGE_NAME} Installer")
set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/assets/icon/icon.ico")
set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/assets/icon/icon.ico") 
set(CPACK_NSIS_INSTALLED_ICON_NAME "${CPACK_PACKAGE_NAME}.exe")
set(CPACK_NSIS_CREATE_ICONS_EXTRA "
  CreateShortCut '$SMPROGRAMS\\${CPACK_PACKAGE_NAME}\\${CPACK_PACKAGE_NAME}.lnk' '$INSTDIR\\${CPACK_PACKAGE_NAME}.exe'
  CreateShortCut '$DESKTOP\\${CPACK_PACKAGE_NAME}.lnk' '$INSTDIR\\${CPACK_PACKAGE_NAME}.exe'
")

include(CPack)
enable_testing()
include(CTest)

include_directories(include)

if(MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc -static")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")
endif()

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
file(GLOB SOURCES "src/*.cpp")
set(ASSET_FILE "assets/assets.rc")
add_executable(Tetris WIN32 ${SOURCES} ${ASSET_FILE})
target_link_libraries(Tetris PRIVATE raylib glfw winmm)

add_subdirectory(tests)

install(TARGETS Tetris DESTINATION .)
install(DIRECTORY assets/audio/ DESTINATION assets/audio)
install(DIRECTORY assets/icon/ DESTINATION assets/icon)
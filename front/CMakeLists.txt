cmake_minimum_required(VERSION 3.5)

project(front VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Charts WebSockets Multimedia MultimediaWidgets REQUIRED)


target_link_libraries(front PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::WebSockets Qt${QT_VERSION_MAJOR}::Charts Qt${QT_VERSION_MAJOR}::Multimedia Qt${QT_VERSION_MAJOR}::MultimediaWidgets)

set_target_properties(front PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
      
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(front)
endif()

aux_source_directory(view VIEW_SRC)
aux_source_directory(model MODEL_SRC)
aux_source_directory(controller CONTROLLER_SRC)

target_sources(${PROJECT_NAME}
               PRIVATE
               ${SRC_DIR}
               ${VIEW_SRC}
               ${MODEL_SRC}
               ${CONTROLLER_SRC})

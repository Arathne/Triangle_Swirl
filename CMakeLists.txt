cmake_minimum_required( VERSION 3.16.2 )

project( sfml_examples
        VERSION 1.0
		DESCRIPTION "draws a rainbow swirl"
		LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( OpenGL REQUIRED )
find_package( SFML 2.5 COMPONENTS graphics system REQUIRED )

add_executable( rainbow main.cpp )
target_link_libraries( rainbow sfml-graphics OpenGL::GL )

CMAKE_MINIMUM_REQUIRED( VERSION 3.12 )
PROJECT( TSPBrute )

INCLUDE( ExternalProject )

SET( CMAKE_CXX_STANDARD 17 )
SET( SPDLOG_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/spdlog )

CONFIGURE_FILE( config/CMakeVariables.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/include/CMakeVariables.hpp )

EXTERNALPROJECT_ADD( SPDLOG
					 GIT_REPOSITORY https://github.com/gabime/spdlog
					 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${SPDLOG_INSTALL_LOCATION}
					 DOWNLOAD_NO_PROGRESS FALSE
					 GIT_PROGRESS TRUE
					 GIT_SHALLOW TRUE
					 UPDATE_DISCONNECTED TRUE
					 )

INCLUDE_DIRECTORIES( ${SPDLOG_INSTALL_LOCATION}/include )
LINK_DIRECTORIES( ${SPDLOG_INSTALL_LOCATION}/lib )

INCLUDE_DIRECTORIES( include )

ADD_EXECUTABLE( TSPBrute
				main.cpp
				include/CMakeVariables.hpp
				src/Map.cpp
				include/Map.hpp
				include/Algorithm.hpp
				src/StandardBruteForce.cpp
				include/StandardBruteForce.hpp
				)

ADD_DEPENDENCIES( TSPBrute SPDLOG )
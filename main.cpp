#include <iostream>

#include <spdlog/spdlog.h>
#include <CMakeVariables.hpp>

int main()
{
	auto sink   = std::make_shared<spdlog::sinks::simple_file_sink_mt>( CMAKE_CURRENT_SOURCE_DIR + "/logs/run.log" );
	auto logger = std::make_shared<spdlog::logger>( "main", sink );
	spdlog::register_logger( logger );

	spdlog::get( "main" )->info( "Initialisation done." );

	std::cout << "Hello, World!" << std::endl;
	return EXIT_SUCCESS;
}
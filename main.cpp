#include <iostream>

#include <spdlog/spdlog.h>
#include <CMakeVariables.hpp>
#include <Map.hpp>
#include <Algorithm.hpp>
#include <StandardBruteForce.hpp>

int main()
{
	auto sink   = std::make_shared<spdlog::sinks::simple_file_sink_mt>( CMAKE_CURRENT_SOURCE_DIR + "/logs/run.log" );
	auto logger = std::make_shared<spdlog::logger>( "main", sink );
	spdlog::register_logger( logger );

	spdlog::get( "main" )->set_level( spdlog::level::debug );
	spdlog::get( "main" )->info( "Initialisation done." );

	Map map( "/own9.city" );

	std::unique_ptr<Algorithm> alg = std::make_unique<StandardBruteForce>( map );

	alg->start();

	return EXIT_SUCCESS;
}
#include <iostream>

#include <spdlog/spdlog.h>
#include <CMakeVariables.hpp>
#include <Map.hpp>
#include <Algorithm.hpp>
#include <StandardBruteForce.hpp>
#include <OptimalMTBruteForce.hpp>
#include <BranchAndBoundMTBruteForce.hpp>

int main()
{
	auto sink   = std::make_shared<spdlog::sinks::simple_file_sink_mt>( CMAKE_CURRENT_SOURCE_DIR + "/logs/run.log" );
	auto logger = std::make_shared<spdlog::logger>( "main", sink );
	spdlog::register_logger( logger );

	spdlog::get( "main" )->set_level( spdlog::level::info );
	spdlog::get( "main" )->flush_on( spdlog::level::info );
	spdlog::get( "main" )->info( "Initialisation done." );

	Map map( "/burma14.city" );

	std::unique_ptr<Algorithm> sbf   = std::make_unique<StandardBruteForce>( map );
	std::unique_ptr<Algorithm> omtbf = std::make_unique<OptimalMTBruteForce>( map );
	std::unique_ptr<Algorithm> babmtbf = std::make_unique<BranchAndBoundMTBruteForce>( map );

//	sbf->start();
	omtbf->start();
	babmtbf->start();

	spdlog::get( "main" )->info( "Run Finished!" );

	return EXIT_SUCCESS;
}

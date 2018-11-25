//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "OptimalMTBruteForce.hpp"

#include <StandardBruteForce.hpp>
#include <spdlog/spdlog.h>
#include <OptimalMTBruteForce.hpp>


void OptimalMTBruteForce::start()
{
	spdlog::get( "main" )->info( __func__ );

	unsigned currentCity;

	for( auto i = 0u; i < currentCities_.size(); i++ )
	{
		spdlog::get( "main" )->debug( "Starting the {} branch!", i + 1 );

		currentCity = currentCities_.front();
		currentCities_.pop_front();

		threadList_.emplace_back( &OptimalMTBruteForce::run, this, currentCity, currentCities_ );
//		calculateNext( 0, currentCity, currentCity, currentCities_ );
		currentCities_.push_back( currentCity );
	}
	for( auto& thread:threadList_ ) { thread.join(); }
}

OptimalMTBruteForce::OptimalMTBruteForce( Map const& map )
		: map_( map )
		  , valueMap_( map.get() )
		  , currentBest_( INT32_MAX )
{
	spdlog::get( "main" )->info( "Loaded : {}, with {} cities", map.getName(), map.getDimension() );
	for( auto i = 0u; i < valueMap_.size(); i++ ) { currentCities_.push_back( i ); }
}

void OptimalMTBruteForce::calculateNext( unsigned value, unsigned idx, unsigned startIdx, std::list<unsigned>& cities )
{
	if( cities.empty() )
	{
		spdlog::get( "main" )->debug( "Found branch end!" );
		spdlog::get( "main" )->debug( "Value: {}, while best is: {}", value, currentBest_ );
		auto distance = valueMap_[ idx ][ startIdx ];
		value += distance;
		testCurrentBest( value );
	}
	unsigned  currentCity;
	for( auto i = 0u; i < cities.size(); i++ )
	{
		auto distance = valueMap_[ idx ][ cities.front() ];
		if( distance == 0 ) continue;

		currentCity = cities.front();
		cities.pop_front();
		value += distance;
		calculateNext( value, currentCity, startIdx, cities );
		cities.push_back( currentCity );
	}
}

void OptimalMTBruteForce::testCurrentBest( unsigned value )
{
	static std::mutex           mutex;
	std::lock_guard<std::mutex> lockGuard( mutex );

	if( value > currentBest_ ) return;
	spdlog::get( "main" )->info( "Swapping the best value! value({}) < currentBest_({})", value, currentBest_ );
	currentBest_ = value;
}

void OptimalMTBruteForce::run( unsigned idx, std::list<unsigned> cities )
{
	spdlog::get( "main" )->error( "Amount of elements: {}", cities.size() );
	calculateNext( 0, idx, idx, cities );
}

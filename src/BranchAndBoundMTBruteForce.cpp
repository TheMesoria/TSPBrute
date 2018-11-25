//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "BranchAndBoundMTBruteForce.hpp"


#include <spdlog/spdlog.h>
#include <BranchAndBoundMTBruteForce.hpp>


void BranchAndBoundMTBruteForce::start()
{
	spdlog::get( "main" )->info( __func__ );

	unsigned currentCity;

	for( auto i = 0u; i < currentCities_.size(); i++ )
	{
		spdlog::get( "main" )->debug( "Starting the {} branch!", i + 1 );

		currentCity = currentCities_.front();
		currentCities_.pop_front();

		threadList_.emplace_back( &BranchAndBoundMTBruteForce::run, this, currentCity, currentCities_ );
		currentCities_.push_back( currentCity );
	}
	for( auto& thread:threadList_ ) { thread.join(); }
}

BranchAndBoundMTBruteForce::BranchAndBoundMTBruteForce( Map const& map )
		: map_( map )
		  , valueMap_( map.get() )
		  , currentBest_( INT32_MAX )
{
	spdlog::get( "main" )->info( "Loaded : {}, with {} cities", map.getName(), map.getDimension() );
	for( auto i = 0u; i < valueMap_.size(); i++ ) { currentCities_.push_back( i ); }
}

void BranchAndBoundMTBruteForce::calculateNext(
		unsigned value
		, unsigned idx
		, unsigned startIdx
		, std::list<unsigned>& cities )
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
		if(testCurrentValue(value))
		{
			cities.push_back( currentCity );
			continue;
		}
		calculateNext( value, currentCity, startIdx, cities );
		cities.push_back( currentCity );
	}
}

void BranchAndBoundMTBruteForce::testCurrentBest( unsigned value )
{
	std::lock_guard<std::mutex> lockGuard( lengthMutex_ );

	if( value > currentBest_ ) return;
	spdlog::get( "main" )->info( "Swapping the best value! value({}) < currentBest_({})", value, currentBest_ );
	currentBest_ = value;
}

void BranchAndBoundMTBruteForce::run( unsigned idx, std::list<unsigned> cities )
{
	calculateNext( 0, idx, idx, cities );
}

bool BranchAndBoundMTBruteForce::testCurrentValue( unsigned value )
{
	std::lock_guard<std::mutex> lockGuard( lengthMutex_ );
	return currentBest_ < value;
}

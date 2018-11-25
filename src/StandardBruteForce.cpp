//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include <StandardBruteForce.hpp>
#include <spdlog/spdlog.h>

#include "StandardBruteForce.hpp"

void StandardBruteForce::start()
{
	spdlog::get( "main" )->info( __func__ );
	unsigned currentCity;

	for( auto i = 0u; i < currentCities_.size(); i++ )
	{
		spdlog::get( "main" )->debug( "Starting the {} branch!", i + 1 );

		currentCity = currentCities_.front();
		currentCities_.pop_front();
		calculateNext( 0, currentCity, currentCity );
		currentCities_.push_back( currentCity );
	}
}

StandardBruteForce::StandardBruteForce( Map const& map )
		: map_( map )
		  , valueMap_( map.get() )
		  , currentBest_( INT32_MAX )
{
	spdlog::get( "main" )->info( "Loaded : {}, with {} cities", map.getName(), map.getDimension() );
	for( auto i = 0u; i < valueMap_.size(); i++ ) { currentCities_.push_back( i ); }
}

void StandardBruteForce::calculateNext( unsigned value, unsigned idx, unsigned startIdx )
{
	if( currentCities_.empty() )
	{
		spdlog::get( "main" )->debug( "Found branch end!" );
		spdlog::get( "main" )->debug( "Value: {}, while best is: {}", value, currentBest_ );
		auto distance = valueMap_[ idx ][ startIdx ];
		value+=distance;
		if( value < currentBest_ ) swapCurrentBest( value );
	}
	unsigned  currentCity;
	for( auto i = 0u; i < currentCities_.size(); i++ )
	{
		auto distance = valueMap_[ idx ][ currentCities_.front() ];
		if( distance == 0 ) continue;

		currentCity = currentCities_.front();
		currentCities_.pop_front();
		value += distance;
		calculateNext( value, currentCity, startIdx );
		currentCities_.push_back( currentCity );
	}
}

void StandardBruteForce::swapCurrentBest( unsigned value )
{
	spdlog::get( "main" )->info( "Swapping the best value! value({}) < currentBest_({})", value, currentBest_ );
	currentBest_ = value;
}

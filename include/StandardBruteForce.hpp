//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <spdlog/spdlog.h>
#include "Algorithm.hpp"
#include "Map.hpp"

class StandardBruteForce
		: public Algorithm
{
	const Map     & map_;
	const ValueMap& valueMap_;
	std::list<unsigned> currentCities_;

	unsigned currentBest_;
public:
	explicit StandardBruteForce( Map const& map );

	~StandardBruteForce() override { spdlog::get( "main" )->info( "Best: {}.", currentBest_ ); };

	void start() override;
	void calculateNext( unsigned value, unsigned idx, unsigned startIdx );
	void swapCurrentBest( unsigned value );
};


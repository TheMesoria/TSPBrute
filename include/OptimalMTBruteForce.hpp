//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <thread>
#include <spdlog/spdlog.h>
#include "Algorithm.hpp"
#include "Map.hpp"

class OptimalMTBruteForce
		: public Algorithm
{
	const Map     & map_;
	const ValueMap& valueMap_;

	std::list<unsigned>    currentCities_;
	std::list<std::thread> threadList_;

	std::mutex cityListMutex_;
	unsigned currentBest_;
public:
	explicit OptimalMTBruteForce( Map const& map );

	~OptimalMTBruteForce() override { spdlog::get( "main" )->info( "Best: {}.", currentBest_ ); };;

	void start() override;
private:
	void run( unsigned idx, std::list<unsigned> cities );
	void calculateNext( unsigned value, unsigned idx, unsigned startIdx, std::list<unsigned>& cities );
	void testCurrentBest( unsigned value );
};


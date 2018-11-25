//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include <thread>
#include <mutex>
#include <spdlog/spdlog.h>
#include "Map.hpp"
#include "Algorithm.hpp"

class BranchAndBoundMTBruteForce
		: public Algorithm
{
	const Map     & map_;
	const ValueMap& valueMap_;

	std::list<unsigned>    currentCities_;
	std::list<std::thread> threadList_;

	std::mutex lengthMutex_;

	unsigned currentBest_;
public:
	explicit BranchAndBoundMTBruteForce( Map const& map );

	~BranchAndBoundMTBruteForce() override { spdlog::get( "main" )->info( "Best: {}.", currentBest_ ); };;

	void start() override;
private:
	void run( unsigned idx, std::list<unsigned> cities );
	void calculateNext( unsigned value, unsigned idx, unsigned startIdx, std::list<unsigned>& cities );
	void testCurrentBest( unsigned value );
	bool testCurrentValue( unsigned value );
};


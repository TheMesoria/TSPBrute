//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


#include "Algorithm.hpp"
#include "Map.hpp"

class StandardBruteForce
		: public Algorithm
{
	const Map     & map_;
	const ValueMap& valueMap_;
	std::list<unsigned> currentCities_;
	std::list<unsigned> visitedCities_;

	unsigned            currentBest_;
	std::list<unsigned> currentBestCities_;
public:
	explicit StandardBruteForce( Map const& map );
	~StandardBruteForce() override = default;

	void start() override;
	void calculateNext( unsigned value, unsigned idx );
	void swapCurrentBest( unsigned value);
};


//
// Created by Wojciech Ormaniec on 24.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once

#include <string>
#include <vector>
#include <list>

using ValueMap=std::vector<std::vector<int>>;

class Map
{
	std::string name_;
	std::string comment_;
	std::string type_;
	std::string edgeWeightType_;

	int dimension_;

	std::vector<std::vector<int>> map_;

public:
	explicit Map( std::string const& fileName );

	const ValueMap& get() const;

	std::string const& getName() const;
	std::string const& getType() const;
	std::string const& getEdgeWeightType() const;
	int getDimension() const;

private:
	void readContent( std::fstream& file );
	bool readContentLine( std::string const& fileLine );
	void readCityNodes( std::fstream& file );
	void loadCityNodes( std::list<std::pair<float, float>> const& cityCoords );
};


//
// Created by Wojciech Ormaniec on 24.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#include "Map.hpp"

#include <fstream>
#include <CMakeVariables.hpp>
#include <Map.hpp>
#include <sstream>
#include <iostream>
#include <spdlog/spdlog.h>


Map::Map( std::string const& fileName )
		:
		comment_( "" )
{
	std::fstream file( CMAKE_CITY_LIST_FOLDER + fileName, std::ios::in );
	if( file.good() )
	{
		readContent( file );
	}
	file.close();
}

const ValueMap& Map::get() const
{
	return map_;
}

void Map::readContent( std::fstream& file )
{
	std::string line;
	while( std::getline( file, line ) )
	{
		if( readContentLine( line ) )
		{
			readCityNodes( file );
		}
	}
}

bool Map::readContentLine( std::string const& fileLine )
{
	std::stringstream ss( fileLine );
	std::string       name, value;

	ss >> name;

	if( name == "NODE_COORD_SECTION" ) { return true; }

	value = ss.str();
	value.erase( 0, name.size() + 3 );
	ss = std::stringstream( value );

	if( name == "NAME" ) { name_ = value; }
	if( name == "COMMENT" ) { comment_ += value; }
	if( name == "TYPE" ) { type_ = value; }
	if( name == "DIMENSION" ) { ss >> dimension_; }
	if( name == "EDGE_WEIGHT_TYPE" ) { edgeWeightType_ = value; }

	return false;
}

void Map::readCityNodes( std::fstream& file )
{
	std::string input;

	spdlog::get( "main" )->info( "Loading new map -> {}", name_ );
	spdlog::get( "main" )->debug( "Loading new map..." );
	spdlog::get( "main" )->debug( "Name : {}\nComment : {}\nType : {}\nEdge : {}\nDimension : {}"
								  , name_
								  , comment_
								  , type_
								  , edgeWeightType_
								  , dimension_ );

	std::list<std::pair<float, float>> cityCoordList;
	while( std::getline( file, input ) && input != "EOF" )
	{
		std::stringstream ss( input );

		float id, x, y;

		ss >> id >> x >> y;
		spdlog::get( "main" )->debug( "City : {}, [{},{}]", id, x, y );

		cityCoordList.emplace_back( x, y );
	}
	loadCityNodes( cityCoordList );
}

void Map::loadCityNodes( std::list<std::pair<float, float>> const& cityCoords )
{
	spdlog::get( "main" )->info( __func__ );
	for( auto const& coord_1 : cityCoords )
	{
		std::vector<int> distanceVector;
		auto[x1, y1] = coord_1;

		for( auto const& coord_2 : cityCoords )
		{
			auto[x2, y2] = coord_2;
			auto x = x1 - x2, y = y1 - y2;

			distanceVector.emplace_back( round( sqrt( pow( x, 2 ) + pow( y, 2 ) ) ) );
		}

		std::string print = "[ ";
		for( auto const& elem : distanceVector )
		{
			print += std::to_string( elem ) + ", ";
		}
		print.pop_back();
		print.pop_back();
		print += " ]";

		spdlog::get( "main" )->debug( print );
		map_.push_back( distanceVector );
	}
}

std::string const& Map::getName() const
{
	return name_;
}

std::string const& Map::getType() const
{
	return type_;
}

std::string const& Map::getEdgeWeightType() const
{
	return edgeWeightType_;
}

int Map::getDimension() const
{
	return dimension_;
}

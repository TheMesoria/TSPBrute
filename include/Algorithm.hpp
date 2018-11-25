//
// Created by Wojciech Ormaniec on 25.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//
#pragma once


class Algorithm
{
public:
	virtual ~Algorithm() = default;

	virtual void start() = 0;
};


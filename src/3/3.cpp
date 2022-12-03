#include <iostream>

#include <unordered_set>
#include <iterator>
#include <algorithm>

#include "lib.hpp"

auto find_shared( std::istringstream& input )
{
	std::vector< char > shared;

	std::string line, left, right;
	int length;
	while( std::getline( input, line ) )
	{
		length = line.size();
		left = line.substr(0, length / 2);
		right = line.substr(length / 2, length / 2);

		std::unordered_set< char > s1{ left.begin(), left.end() }, s2{ right.begin(), right.end() };
		for( auto& c : s1 )
		{
			if( s2.count( c ) )
			{
				shared.push_back( c );
				break;
			}
		}
	}

	return shared;
}

auto find_badges( std::istringstream& input )
{
	std::vector< char > badges;

	std::string line1, line2, line3;
	while( std::getline( input, line1 ) )
	{
		std::getline( input, line2 );
		std::getline( input, line3 );

		std::unordered_set< char >
			s1{ line1.begin(), line1.end() }, 
			s2{ line2.begin(), line2.end() },
			s3{ line3.begin(), line3.end() };

		for( auto& c : s1 )
		{
			if( s2.count( c ) && s3.count( c ) )
			{
				badges.push_back( c );
				break;
			}
		}
	}

	return badges;
}

unsigned long long partOne( std::istringstream&& input )
{
	std::vector< char > shared = find_shared( input );

	int sum = 0;
	for( auto& c : shared )
	{
		if( isupper( c ) )
			sum += c - 'A' + 27;
		else
			sum += c - 'a' + 1;
	}

    return sum;
}

unsigned long long partTwo( std::istringstream&& input )
{
	std::vector< char > badges = find_badges( input );

	int sum = 0;
	for( auto& c : badges )
	{
		if( isupper( c ) )
			sum += c - 'A' + 27;
		else
			sum += c - 'a' + 1;
	}

    return sum;
}

#include <iostream>

#include <string>
#include <vector>
#include <numeric>

#include "lib.hpp"

auto parse( const std::string& input )
{
	std::vector< std::vector< int > > chunks;

	for( std::size_t pos = input.find("\n\n"), start = 0; pos != std::string::npos; start = pos + 2, pos = input.find("\n\n", pos + 2) )
		chunks.push_back(getNumbers< int >( input.substr(start, pos - start), '\n' ) );

    return chunks;
}

unsigned long long partOne( const std::string& input )
{
	std::vector< std::vector< int > > chunks = parse( input );

	int max = 0;
	for(auto& chunk : chunks)
	{
		int num = std::accumulate(chunk.begin(), chunk.end(), 0);
		if(num > max)
			max = num;
	}

    return max;
}

unsigned long long partTwo( const std::string& input )
{
	std::vector< std::vector< int > > chunks = parse( input );
	std::vector< int > calories;

	int max = 0;
	for(auto& chunk : chunks)
		calories.push_back(std::accumulate(chunk.begin(), chunk.end(), 0));

	std::sort(calories.begin(), calories.end(), std::greater{});

    return calories[0] + calories[1] + calories[2];
}

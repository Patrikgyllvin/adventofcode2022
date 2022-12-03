#include <iostream>

#include <numeric>

#include "lib.hpp"

auto parse( std::istringstream& input )
{
	std::vector< std::vector< int > > chunks;
	std::string inputStr = input.str();

	for( std::size_t pos = inputStr.find("\n\n"), start = 0;
			pos != std::string::npos; start = pos + 2, pos = inputStr.find("\n\n", pos + 2) )
		chunks.push_back(getNumbers< int >( inputStr.substr(start, pos - start), '\n' ) );

    return chunks;
}

unsigned long long partOne( std::istringstream&& input )
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

unsigned long long partTwo( std::istringstream&& input )
{
	std::vector< std::vector< int > > chunks = parse( input );
	std::vector< int > calories;

	for(auto& chunk : chunks)
		calories.push_back(std::accumulate(chunk.begin(), chunk.end(), 0));

	std::sort(calories.begin(), calories.end(), std::greater{});

    return calories[0] + calories[1] + calories[2];
}

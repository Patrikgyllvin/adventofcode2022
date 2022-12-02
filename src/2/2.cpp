#include <iostream>
#include <sstream>

#include "lib.hpp"

int scoreGrid[3][3] =
{
	{ 4, 8, 3 },
	{ 1, 5, 9 },
	{ 7, 2, 6 }
};

int moveGrid[3][3] =
{
	{ 2, 0, 1 },
	{ 0, 1, 2 },
	{ 1, 2, 0 }
};


unsigned long long partOne( const std::string& input )
{
	std::istringstream stream{ input };
	std::string line;

	int score = 0;
	while(std::getline(stream, line, '\n'))
		score += scoreGrid[line[0] - 'A'][line[2] - 'X'];

    return score;
}

unsigned long long partTwo( const std::string& input )
{
	std::istringstream stream{ input };
	std::string line;

	int score = 0;
	while(std::getline(stream, line, '\n'))
		score += scoreGrid[line[0] - 'A'][moveGrid[line[0] - 'A'][line[2] - 'X']];

    return score;
}

#include <iostream>

#include "lib.hpp"

auto parse( std::istringstream& input )
{
    return getNumbers< int >( input.str(), ',' );
}

unsigned long long partOne( std::istringstream&& input )
{
    parse( input );

    return 0;
}

unsigned long long partTwo( std::istringstream&& input )
{
    parse( input );

    return 0;
}


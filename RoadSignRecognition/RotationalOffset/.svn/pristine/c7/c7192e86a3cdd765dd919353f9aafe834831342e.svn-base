// Only for testing

#include "RotationalOffset.h"

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void help();

int main( int argc, char** argv )
{
    if ( argc != 2 )
    {
        help();
        return -1;
    }


    // loading the file
    ifstream fin( argv[1] );

    if ( !fin )
    {
        cerr << "File does not exist!\n";
        return -1;
    }


    // reading the countor from the input file
    float item, cost;

    IRO::Contour contour;

    while ( !fin.eof() )
    {
        fin >> item >>  cost;
        contour.push_back( make_pair( item, cost ) );
    }


    // calculate the Rotational Offset
    cRotationalOffset RO;
    vector<float>  Offset = RO.GetMinRadius( contour );


    // Show offset
    vector<float>::iterator it;

    cout << "Offset: ";
    for ( it = Offset.begin(); it != Offset.end(); it++ )
    {
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}


/**
 * help
 */
void help()
{
    std::cout << "Usage: ./RotationalOffset <file>\n";
}


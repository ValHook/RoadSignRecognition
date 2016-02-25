#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "PostProcessing.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace cv;

void help();

int main( int argc, char** argv )
{
    if ( argc != 2 )
    {
        help();
        return -1;
    }

    Mat img = imread( argv[1], 0 );
    PostProcessing p( img );
    p.DisplayImage( "InputImage", img );

    Mat fimg = p.FilterImage();
    p.DisplayImage( "FilteredImage", fimg );

    long int aspectAria = 1500;
    double lowRatio = 0.25;
    double highRatio = 1.3;
    vector<vector<Point> > copyCont;
    Mat eimg = p.Elimination( fimg, copyCont, aspectAria, lowRatio, highRatio );
    p.DisplayImage( "Elimination", eimg );

    vector<vector<Point> >hull( copyCont.size() );
    Mat himg = p.Convex( eimg, hull, copyCont );
    p.DisplayImage( "ConvexHull", himg );

    //Get contour
    vector<IRO::Contour> extractedCont;
    float dist_threshold = 70;
    Mat cimg = p.ThresholdedContour( hull, copyCont, extractedCont, dist_threshold );
    p.DisplayImage( "ContourExtracted", cimg );

    waitKey( 0 );
}


/**
 * help
 */
void help()
{
    std::cout << "Usage: ./post_processing <img>\n";
}

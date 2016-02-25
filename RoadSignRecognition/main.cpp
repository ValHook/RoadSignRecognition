//
//  Road Sign Recognition
//  Valentin Mercier
//
//  Created by Val on 14/12/2014.
//

#include <cv.h>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <tesseract/baseapi.h>

#include <time.h>
#include <string>
#include <iostream>
#include <cmath>
#include <regex>

#define LOGGER 1
#define SHOW_TMP_IMAGES 1
#include "ihls.h"
#include "nhs.h"
#include "PostProcessing.h"


using namespace std;
using namespace cv;
using namespace tesseract;


/* LOGGER FUNCTIONS */
void log_time(clock_t *t)
{
    if (LOGGER) {
        cout << " " << (float_t)(clock() - *t)/(float_t)CLOCKS_PER_SEC << " seconds" << endl;
        *t = clock();
    }
}
void log_step(string str)
{
    if (LOGGER)
        cout << str;
}



/* MAIN CONTROLLER */
int main(int argc, const char *argv[])
{
    /* Check arguments */
    if( argc != 2 ) {
        cerr << "Usage: ./rsr <img>\n";
        return -1;
    }
    
    /* Initiate timer */
    clock_t t = clock(), full_t = t;
    
    /* Open Image */
    log_step("Opening Image ...");
    Mat image = imread(argv[1]);
    if( image.channels() != 3 ) {
        cerr << "Cannot open image " << argv[1] << "\n";
        return -1;
    }
    log_time(&t);

    
    
    /* Perform IHLS & NHS filters */
    log_step("Converting to IHLS then NHS ...");
    Mat ihls_image = convert_rgb_to_ihls(image);
    Mat nhs_image = convert_ihls_to_nhs(ihls_image);
    log_time(&t);
    
    
    /* Post processing & build sign masks */
    log_step("Post processing & building sign masks ...");
    Mat eimg = post_process(nhs_image);
    log_time(&t);
    
    /* Extract signs data from masks */
    log_step("Extracting signs content ...");
    Mat content = extract_signs_content(image, eimg, 0x40);
    log_time(&t);
    
    
    
    /* Perform OCR with tesseract */
    log_step("Performing OCR ...");
    TessBaseAPI tess;
    tess.Init(NULL, "eng", OEM_DEFAULT);
    tess.SetPageSegMode(PSM_SINGLE_BLOCK);
    tess.SetImage((uchar*)content.data, content.size().width, content.size().height, content.channels(), (int) content.step1());
    tess.Recognize(0);
    string out = tess.GetUTF8Text();
    log_time(&t);
    
    
    /* Show results */
    bool res = FALSE;
    smatch m;
    regex e("30|50|70|90|110|130|100");
    while (regex_search (out,m,e)) {
        if (!res) {
            res = TRUE;
            log_step("Results : ");
        }
        cout << m[0] << " ";
        out = m.suffix().str();
    }
    if (!res)
        log_step("No results found.");
    
    
    /* End */
    log_step("\nDone...");
    log_time(&full_t);
    if (SHOW_TMP_IMAGES) {
        namedWindow("IHLS", CV_WINDOW_AUTOSIZE);
        imshow("IHLS", ihls_image);
        namedWindow("NHS", CV_WINDOW_AUTOSIZE);
        imshow("NHS", nhs_image);
        namedWindow("Post processing", CV_WINDOW_AUTOSIZE);
        imshow("Post processing", eimg);
        namedWindow("Content", CV_WINDOW_AUTOSIZE);
        imshow("Content", content);
        waitKey(0);
    }
    
    return EXIT_SUCCESS;
}


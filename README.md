# Road Sign Recognition
Road sign recognition is a project which aims at **recognizing road signs** usign the highly renown image libray OpenCV and the OCR library Tesseract.
This project is meant to be used in **embedded systems in cars** to detect and alert the driver about **changes of the maximum speed** allowed.

It was developped in **C++** using the **pre-compiled dynamic libraries** of Open CV and Tesseract for **OS X** but can be easily ported for other platforms.
*You just need to change the dynamic libraries*

## Algorithm
The main algorithm behind this project was designed to **take as input any road picture** featuring a sign like this one for example:

![Road Sign on a highway](http://s23.postimg.org/sw8gye24r/input.jpg)

**Extract the sign and its number** through different filters using OpenCV

![Sign extraction steps](http://s9.postimg.org/90c6ygqlb/Capture_d_cran_2016_02_25_19_20_13.png)

and finally **perform OCR** on the filtered image to output a **string containing the recognized number** if a sign was recognized. It will be empty otherwise.

## Usage:
`./rsr PATH_TO_IMAGE_FILE`

## Example output:
    Opening Image ... 0.003731 seconds
    Converting to IHLS then NHS ... 0.014692 seconds
    Post processing & building sign masks ... 0.00738 seconds
    Extracting signs content ... 0.006715 seconds
    Performing OCR ... 0.047116 seconds
    Results : 90 
    Done... 0.07991 second`
    
## License
The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
#include <iostream>
#include <sstream>
#include <fstream>
#include "VolImage.h"

using namespace std;

int main(int argc, char* argv[])
{
    int i, j;
    string output_file_name, imageBase;
    PLLKIA010::VolImage app, *ptrV;
    if((ptrV = new PLLKIA010::VolImage) == NULL)
    {
        cerr << "Object creation failed! Exiting...";
        exit(1);
    }
    ptrV = new PLLKIA010::VolImage;

    if(argc == 6)
    {
        imageBase = string(argv[1]);
        output_file_name = string(argv[5]);
        string s = string(argv[3]) + " " + string(argv[4]);
        istringstream iss(s);
        iss >> i >> j;
    }
    else if(argc == 5)
    {
        imageBase = string(argv[1]);
        output_file_name = string(argv[4]);
        string i = string(argv[3]);
        istringstream iss(i);
        iss >> i;
    }
    else{
        imageBase = string(argv[1]);
        app.readImages(imageBase);
        cout << "Number of images: \n" << app.volImageNum() << endl;
        cout << "Number of bytes required: \n" << app.volImageSize() << endl;
    }
    
    
    return 0;
}
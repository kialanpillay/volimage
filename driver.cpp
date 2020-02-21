#include <iostream>
#include <sstream>
#include <fstream>
#include "vol_image.h"

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
    
    if(argc == 6)
    {
        imageBase = string(argv[1]);
        output_file_name = string(argv[5]);
        string s = string(argv[3]) + " " + string(argv[4]);
        istringstream iss(s);
        iss >> i >> j;
        app.readImages(imageBase);
        app.diffmap(i, j, output_file_name);
        cout << "Difference map computed!" << endl;
    }
    else if(argc == 5 && string(argv[2])=="-x")
    {
        imageBase = string(argv[1]);
        output_file_name = string(argv[4]);
        string s = string(argv[3]);
        istringstream iss(s);
        iss >> i;
        app.readImages(imageBase);
        app.extract(i, output_file_name);
        cout << "Slice extracted!" << endl;
    }
    else if(argc == 5 && string(argv[2])=="-g")
    {
        imageBase = string(argv[1]);
        output_file_name = string(argv[4]);
        string s = string(argv[3]);
        istringstream iss(s);
        iss >> i;
        app.readImages(imageBase);
        app.depthExtract(i, output_file_name);
        cout << "Row extracted along all slices!" << endl;
    }
    else if(argc == 2){
        imageBase = string(argv[1]);
        imageBase = "MRI";
        app.readImages(imageBase);
        cout << "Number of images: " << app.volImageNum() << endl;
        cout << "Number of bytes required: " << app.volImageSize() << endl;
        
    }
    else{
        cout << "Incorrect number of arguments!" << endl;
    }
    delete ptrV;
    return 0;
}

#include <iostream>
#include <sstream>
#include "VolImage.h"

using namespace std;

int main(int argc, char* argv[])
{
    int i, j;
    string output_file_name;
    PLLKIA010::VolImage*ptrV;
    ptrV = new PLLKIA010::VolImage;

    if(argc == 6)
    {
        output_file_name = argv[5];
        string s = string(argv[3]) + " " + string(argv[4]);
        istringstream iss(s);
        iss >> i >> j;
    }
    else if(argc == 5)
    {
        output_file_name = argv[4];
        string i = string(argv[3]);
        istringstream iss(i);
        iss >> i;
    }
    else{
        cout << "Number of images: \n" << endl;
        cout << "Number of bytes required: \n" << endl;
    }
    
    
    return 0;
}
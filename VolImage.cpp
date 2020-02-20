#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "volimage.h"

using namespace std;


PLLKIA010::VolImage::VolImage(): width(0), height(0), slices(0){}

PLLKIA010::VolImage::~VolImage()
{
    if(!slices.empty())
    {
        for (int i = 0; i < slices.size(); i++)
        {
            for (int j = 0; j < height; j++)
            {
                delete [] slices[i][j];
            }
            delete [] slices[i];
        };

        slices.clear();
    };
}

bool PLLKIA010::VolImage::readImages(std::string baseName)
{
    ifstream file("./brain_mri_raws/" + baseName + ".data"); 

    string str;
    int number_images;
    

    while (getline(file, str))
    {
        istringstream iss(str);
        iss >> width >> height >> number_images;
    }
    slices.resize(number_images);
    
        for(int i = 0; i < number_images; i++)
        {
            ifstream raw("./brain_mri_raws/" + baseName + to_string(i) + ".raw", ios::in|ios::binary);
            unsigned char** imageArray = new unsigned char*[height];
            if (raw.is_open())
            { 

                for(int j = 0; j < height; j ++){
                    imageArray[j] = new unsigned char[width];
                    raw.seekg (j*width);
                    raw.read ((char*)imageArray[j], width);
                }
                
                raw.close();
                
            }
                slices[i] = imageArray;
        }  

    return true;
}

void PLLKIA010::VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)
{

}
            
void PLLKIA010::VolImage::extract(int sliceId, std::string output_prefix)
{

}
int PLLKIA010::VolImage::volImageSize(void)
{
    int size = 0;

    for (int i = 0; i < height; i++)
        {
            for (int j = 0; i < width; i++)
            {
                size += sizeof(slices[i][j]);
            }
            size += sizeof(slices[i]);
        };
    
    return size;
}

int PLLKIA010::VolImage::volImageNum(void)
{
    return slices.size();
}
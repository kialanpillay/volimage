#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "VolImage.h"

using namespace std;
using namespace PLLKIA010;

VolImage::VolImage()
{
    width = 0;
    height = 0;
    slices = {};
}

VolImage::~VolImage()
{
    if(!slices.empty())
    {
        for (int i = 0; i < slices.size(); i++)
        {
            for (int j = 0; i < height; i++)
            {
                delete [] slices[i][j];
            }
            delete [] slices[i];
        };

        slices.clear();
    };
}

bool VolImage::readImages(std::string baseName)
{
    ifstream file(baseName + ".data"); 
    if(file)
    {
        string str;
        int number_images;
        slices.reserve(number_images);

        while (getline(file, str))
        {
            istringstream iss(str);
            iss >> width >> height >> number_images;
        }

        for(int i = 0; i < number_images; i++)
        {
            ifstream raw(baseName + to_string(i) + ".raw");
            unsigned char **imageBuffer = new unsigned char*[height];
            for(int j = 0; j < height; j ++){

                
                while (getline(file, str))
                {
                    unsigned char *tempBuffer = new unsigned char[width];
                    istringstream iss(str);
                    for(int k = 0l; k < width; k++){
                        iss >> tempBuffer;
                    }
                    *imageBuffer[0] = *tempBuffer;
                    delete [] tempBuffer;
                }
                
            }
            slices.push_back(imageBuffer);
            
        }


        return true;
    }
    else
    {
        return false;
    }
    

}

void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix)
{

}
            
void VolImage::extract(int sliceId, std::string output_prefix)
{

}
int VolImage::volImageSize(void)
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

int VolImage::volImageSize(void)
{
    return slices.size();
}
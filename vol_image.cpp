#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "vol_image.h"

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
    ofstream file(output_prefix + ".raw",ios::binary); 
    for (int r = 0; r < height; r++){
        {
            unsigned char* rowArray = new unsigned char[width];
            for (int c = 0; c < width; c++)
            {
                rowArray[c] = (unsigned char)(abs((float)slices[sliceI][r][c] - (float)slices[sliceJ][r][c])/2);
            }
            file.write((char*)rowArray,width);
            delete [] rowArray;
        }
    }
    file.close();
}
            
void PLLKIA010::VolImage::extract(int sliceId, std::string output_prefix)
{
    ofstream file(output_prefix + ".raw",ios::binary); 
    for (int r = 0; r < height; r++){
        {
            unsigned char* rowArray = new unsigned char[width];
            for (int c = 0; c < width; c++)
            {
                rowArray[c] = slices[sliceId][r][c];
            }
            file.write((char*)rowArray,width);
            delete [] rowArray;
        }
    }
    file.close();
}
int PLLKIA010::VolImage::volImageSize(void)
{
    int size = 0;

    for (int i = 0; i < slices.size(); i++)
        {
            for (int j = 0; j < height; i++)
            {
                for (int k = 0; k < width; k++)
                {
                    size += sizeof(slices[i][j][k]);
                }
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
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
            for (int j = 0; i < slices.size(); i++)
            {
                delete [] slices[i][j];
            }
            delete [] slices[i];
        };

        slices.clear();
    };
}
#ifndef VOLIMAGE_H
#define VOLIMAGE_H
#include <vector>

namespace PLLKIA010
{
    class VolImage
    {
        private: 
            int width, height; // width and height of image stack
            std::vector<unsigned char**> slices; // data for each slice, in order
        
        public: 
            VolImage(); // default constructor
            ~VolImage(); // destructor
            bool readImages(std::string baseName);
            void diffmap(int sliceI, int sliceJ, std::string output_prefix);
            void extract(int sliceId, std::string output_prefix);
            int volImageSize(void); 
            int volImageNum(void);
    };
}

#endif
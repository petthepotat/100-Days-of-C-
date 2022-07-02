/*
    Day 8
    - Image to console!
    - using ascii characters
*/

#define STB_IMAGE_IMPLEMENTATION
#include <include/stb_image.h>
#include <iostream>

const char *ASCII = " .(*|#";

char get_ascii(int n)
{
    if (n > 200)
        return ASCII[0];
    if (n > 150)
        return ASCII[1];
    if (n > 100)
        return ASCII[2];
    if (n > 50)
        return ASCII[3];
    return ASCII[4];
}

int main()
{
    int width, height, channels;
    unsigned char *image_data = stbi_load("assets/techno.png", &width, &height, &channels, 0);

    std::cout << "Image dimensions: " << width << " " << height << std::endl;

    // read the image and output data
    unsigned char r, g, b;
    int counter = -1, avg;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            r = image_data[counter++];
            g = image_data[counter++];
            b = image_data[counter++];

            // average
            avg = (r + g + b) / 3;
            std::cout << get_ascii(avg);
        }
        std::cout << std::endl;
    }

    stbi_image_free(image_data);

    return 0;
}

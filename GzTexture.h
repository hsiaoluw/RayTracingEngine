#ifndef TEXTURE_H
#define TEXTURE_H
//
// GzTexture.h     Represents the texture of a material
// 
#include "GzColor.h"

class GzTexture
{
public:
    GzColor (GzTexture::*tex_fun)(float, float);  // texture mapping function pointer
    const char* tex_file;             // file name for texture image
    int xs, ys;
    int open = 0;
    GzColor *image = nullptr;

    GzTexture();
    GzTexture(GzColor(GzTexture::*func)(float, float));
    GzTexture(const char* &_texfile, GzColor(GzTexture::*func)(float, float));

    // load image texture file
    void loadFile(const char* &file);
    // texture ready for texturing?
    bool hasTexture();
    // texture mapping function
    GzColor tex_map(float u, float v);
    // image texture mapping
    GzColor image_tex_func(float u, float v);
    // checkerbox procedural texture mapping
    GzColor checker_ptex_func(float u, float v);
};

#endif
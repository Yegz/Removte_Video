#ifndef _YUYV_TO_RGB24_H_
#define _YUYV_TO_RGB24_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_yuv_to_rgb_pixel(int y, int u, int v);
int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);

#endif
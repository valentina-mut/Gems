#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>


const int WIDTHWINDOW = 600;
const int HEIGHTWINDOW = 600;
const int GRIDWIDTH = 20;
const float SQUAREWIDTH = WIDTHWINDOW / GRIDWIDTH; 
const int GRIDHEIGHT = 20;
const float SQUAREHEIGHT = HEIGHTWINDOW / GRIDHEIGHT; 

const int lenColorValues = 12;
const float colorValues [lenColorValues ][3] = {
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f},
    {1.0f, 1.0f, 0.0f},
    {1.0f, 0.0f, 1.0f},
    {0.0f, 1.0f, 1.0f},
    {0.5f, 0.5f, 0.5f},
    {0.5f, 0.0f, 0.0f},
    {0.0f, 0.5f, 0.0f},
    {0.0f, 0.0f, 0.5f},
    {0.5f, 0.5f, 0.0f},
    {0.0f, 0.5f, 0.5f},
    // {0.5f, 0.0f, 0.5f},
    // {0.5f, 0.5f, 0.5f},
    // {0.25f, 0.25f, 0.25f},
    // {0.75f, 0.75f, 0.75f},
    // {0.25f, 0.5f, 0.25f} 
};
/**
 * \file HaroldHeadTop.cpp
 *
 * \author Amtullah Naalwala
 *
 * Draws features for Harold head top
 */

#include "pch.h"
#include "HaroldHeadTop.h"

/**
 * Constructor
 * \param name drawable name
 * \param filename filename for the image
 */
CHaroldHeadTop::CHaroldHeadTop(const std::wstring& name, const std::wstring& filename) : CHeadTop(name,filename)
{
}

/**
 * Destructor
 */
CHaroldHeadTop::~CHaroldHeadTop()
{
}

/**
 * Draw the headtop
 * \param graphics the graphics object we're drawing on
 */
void CHaroldHeadTop::Draw(Gdiplus::Graphics* graphics)
{
    CHeadTop::Draw(graphics);
    DrawEyebrow(Point(27, 57), Point(47, 55), graphics);
    DrawEyebrow(Point(80, 57), Point(60, 55), graphics);
    DrawEye(Point(35, 75), graphics);
    DrawEye(Point(72, 75), graphics);

}

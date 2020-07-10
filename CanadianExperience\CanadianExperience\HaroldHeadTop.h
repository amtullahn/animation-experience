/**
 * \file HaroldHeadTop.h
 *
 * \author Amtullah Naalwala
 *
 * Draws features for harold's head top
 */

#pragma once
#include "HeadTop.h"

/**
* Draws features for Harold's head top
*/
class CHaroldHeadTop :
	public CHeadTop
{
public:
   
    /// Constructor
    /// param name drawable name
    /// param filename filename for the image
	CHaroldHeadTop(const std::wstring& name, const std::wstring& filename);

    /// Destructor
	virtual ~CHaroldHeadTop();

    /// Draws the object
    /// \param graphics the object being drawn
	virtual void Draw(Gdiplus::Graphics* graphics) override;
};


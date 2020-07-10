/**
 * \file SpartyHeadTop.h
 *
 * \author Amtullah Naalwala
 *
 * Draw features for Sparty's headtop
 */

#pragma once
#include "HeadTop.h"


/**
 * Sparty's head top
 */
class CSpartyHeadTop :
	public CHeadTop
{
public:

	/// Constructor
	/// param name drawable name
	/// param filename filename for the image
	CSpartyHeadTop(const std::wstring& name, const std::wstring& filename);

	/// Destructor
	virtual ~CSpartyHeadTop();

	/// Draws the object
	/// \param graphics the object being drawn
	virtual void Draw(Gdiplus::Graphics* graphics) override;

private:

	/// Image for right eye
	std::unique_ptr<Gdiplus::Bitmap> mRightEye;

	/// Image for left eye
	std::unique_ptr<Gdiplus::Bitmap> mLeftEye;

};


/**
 * \file ImageDrawable.h
 *
 * \author Amtullah Naalwala
 *
 * Draws the image drawable
 */

#pragma once
#include <memory>

using namespace Gdiplus;

#include "Drawable.h"


/**
 * Draws the image drawable
 */
class CImageDrawable :
	public CDrawable
{
public:
	/// Constructor
	CImageDrawable(const std::wstring& name, const std::wstring& filename);
	
	/// Destructor
	virtual ~CImageDrawable();

	/// Default Constructor (disabled)
	CImageDrawable() = delete;
	
	/// Copy Constructor (disabled)
	CImageDrawable(const CImageDrawable&) = delete;

	/// Assignment operator (disabled)
	void operator=(const CImageDrawable&) = delete;
	virtual void Draw(Gdiplus::Graphics* graphics) override;
	virtual bool HitTest(Gdiplus::Point pos) override;

	/// Getter for Center
	/// \return mCenter center of the drawable object
	Gdiplus::Point GetCenter() { return mCenter; }

	/// Setter for Center
	/// \param center point to set center to 
	void SetCenter(Gdiplus::Point center) { mCenter = center; }

protected:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
private:
	/// center of drawable
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
	
};


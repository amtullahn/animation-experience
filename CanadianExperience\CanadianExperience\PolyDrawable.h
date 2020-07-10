/**
 * \file PolyDrawable.h
 *
 * \author Amtullah Naalwala
 *
 * Drawable based on polygon images
 */

#pragma once
#include "Drawable.h"
#include <vector>

/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class CPolyDrawable :
	public CDrawable
{
public:
	CPolyDrawable(const std::wstring& name);
	virtual ~CPolyDrawable();

	/// default constructor disable
	CPolyDrawable() = delete; 

	/// Copy constructor disabled
	CPolyDrawable(const CPolyDrawable&) = delete;

	/// Assignment operator disabled
	void operator= (const CPolyDrawable&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics) override;
	virtual bool HitTest(Gdiplus::Point pos) override;
	void AddPoint(Gdiplus::Point pos);

	/// Getter for the color
	/// \return mColor color of the drawable
	Gdiplus::Color GetColor() { return mColor; }

	/// Setter for the color
	/// \param color The color for the drawable
	void SetColor(Gdiplus::Color color) { mColor = color; }
private:
	/// the color of object
	Gdiplus::Color mColor = Gdiplus::Color::Black;

	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;

};



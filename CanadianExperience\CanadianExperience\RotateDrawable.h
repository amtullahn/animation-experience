/**
 * \file RotateDrawable.h
 *
 * \author Amtullah Naalwala
 *
 * Class for drawables based on bitmap images
 */


#pragma once
#include <memory>
#include <string>

//using namespace Gdiplus;

/// Constant ratio to convert radians to degrees
const double RadtoDeg = 57.295779513;

/**
 * Class for drawables based on bitmap images
 */
class CRotateDrawable
{
public:
    CRotateDrawable();
    virtual ~CRotateDrawable();

    void Load(const std::wstring& filename);
    void DrawImage(Gdiplus::Graphics* graphics, Gdiplus::Point position, double angle);

    /// Copy constructor disabled
    CRotateDrawable(const CRotateDrawable&) = delete;

    /// Assignment operator disabled
    void operator=(const CRotateDrawable&) = delete;

    /// Set center point for eyes
    /// \param center center point
    void SetCenter(Gdiplus::Point center) { mCenter = center; }

    /// Get center point for eyes
    /// \returns mCenter center point for eyes
    Gdiplus::Point GetCenter() const { return mCenter; }

    /// Determines if image is loaded or not
    /// \returns mLoaded if image is loaded or not
    bool IsLoaded() const { return mLoaded; }

protected:

    /// Image
    std::unique_ptr<Gdiplus::Bitmap> mImage;

    /// center point
    Gdiplus::Point mCenter = Gdiplus::Point(0, 0);

    /// if image is loaded 
    bool mLoaded = false;


};


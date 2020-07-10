#include "pch.h"
#include "RotateDrawable.h"
#include<string>

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CRotateDrawable::CRotateDrawable()
{
}

/**
 * Destructor
 */
CRotateDrawable::~CRotateDrawable()
{
}

/**
 * Load image from file
 * \param filename file to load
 */
void CRotateDrawable::Load(const std::wstring& filename)
{
    mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    if (mImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
    else
    {
        mLoaded = true;
    }
}

/**
 *  Drawing the image
 * \param graphics the graphics context to draw on
 * \param position the position to draw at
 * \param angle the rotation angle
 */
void CRotateDrawable::DrawImage(Gdiplus::Graphics* graphics, Gdiplus::Point position, double angle)
{
    auto state = graphics->Save();
    graphics->TranslateTransform((float)position.X, (float)position.Y);
    graphics->RotateTransform((float)(-angle * RadtoDeg));
    graphics->DrawImage(mImage.get(), -mCenter.X, -mCenter.Y, mImage->GetWidth(), mImage->GetHeight());
    graphics->Restore(state);
}



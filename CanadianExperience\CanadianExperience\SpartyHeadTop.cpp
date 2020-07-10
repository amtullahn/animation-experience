/**
 * \file SpartyHeadTop.cpp
 *
 * \author Amtullah Naalwala
 *
 * Draws features for Sparty Head Top
 */

#include "pch.h"
#include "SpartyHeadTop.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param name drawable name
 * \param filename filename for the image
 */
CSpartyHeadTop::CSpartyHeadTop(const std::wstring& name, const std::wstring& filename) : CHeadTop(name, filename)
{
    mRightEye = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/sparty_reye.png"));
    mLeftEye = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/sparty_leye.png"));

}

/**
 * Destructor
 */
CSpartyHeadTop::~CSpartyHeadTop()
{
}

void CSpartyHeadTop::Draw(Gdiplus::Graphics* graphics)
{
   
    CHeadTop::Draw(graphics);

    auto state1 = graphics->Save();
    graphics->TranslateTransform((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
    graphics->RotateTransform((float) (-mPlacedR * radToDiam));
    graphics->DrawImage(mRightEye.get(), -GetCenter().X + 20, -GetCenter().Y + 95, mRightEye->GetWidth(), mRightEye->GetHeight());
    graphics->Restore(state1);

    auto state2 = graphics->Save();
    graphics->TranslateTransform((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
    graphics->RotateTransform((float)(-mPlacedR * radToDiam));
    graphics->DrawImage(mLeftEye.get(), -GetCenter().X + 54, -GetCenter().Y + 96, mLeftEye->GetWidth(), mLeftEye->GetHeight());
    graphics->Restore(state2);
}

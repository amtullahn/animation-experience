/**
 * \file HeadTop.cpp
 *
 * \author Amtullah Naalwala
 *
 * Draws features for a Head top
 */

#include "pch.h"
#include "HeadTop.h"
#include "Timeline.h"

using namespace Gdiplus;

/**
 * Constructor
 * \param name drawable name
 * \param filename filename for the image
 */
CHeadTop::CHeadTop(const std::wstring& name, const std::wstring& filename) : CImageDrawable(name,filename)
{
}

/**
 * Destructor
 */
CHeadTop::~CHeadTop()
{
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
 * Draw an eyebrow
 * \param p1 Point to start drawing at
 * \param p2 Point to end drawing at
 * \param graphics graphics object we are drawing on 
 */
void CHeadTop::DrawEyebrow(Gdiplus::Point p1, Gdiplus::Point p2, Gdiplus::Graphics* graphics)
{
    Point eyebrowOne = TransformPoint(p1);
    Point eyebrowTwo = TransformPoint(p2);
    Pen eyebrowPenDraw(Color::Black, 2);   
    graphics->DrawLine(&eyebrowPenDraw, eyebrowOne, eyebrowTwo);
    //graphics->Restore(state);
}

/**
 * Draw an eye
 * \param p Point that the eye is centered on
 * \param graphics the graphics object drawing on
 */
void CHeadTop::DrawEye(Gdiplus::Point p, Gdiplus::Graphics* graphics)
{
    SolidBrush brush(Color::Black);
    float wid = 15.0f;
    float hit = 20.0f;

    Point eye = TransformPoint(p);

    auto state = graphics->Save();
    graphics->TranslateTransform((float)eye.X, (float)eye.Y);
    graphics->RotateTransform((float)(-mPlacedR * radToDiam));
    graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
    graphics->Restore(state);
}

/**
 * Draw the headtop
 * \param graphics the grahpics object we are drawing
 */
void CHeadTop::Draw(Gdiplus::Graphics* graphics)
{
    CImageDrawable::Draw(graphics);

    /// Distance horizontally from each eye center to the center
    int horizontalDist = mEyeDistance / 2;

    /// Compute left and right eye center X location
    int rightX = mCenterEye.X - horizontalDist;
    int leftX = mCenterEye.X + horizontalDist;

    /// Eye center Y value
    int yLocEye = mCenterEye.Y;

    DrawEyebrow(Point(leftX - 4, yLocEye - 20), Point(leftX + 9, yLocEye - 18), graphics);
    DrawEyebrow(Point(rightX - 10, yLocEye - 16), Point(rightX + 4, yLocEye - 18), graphics);

    if (mLeftEye.IsLoaded() && mRightEye.IsLoaded())
    {
        /// drawing the left eye
        Point lEye = TransformPoint(Point(leftX, yLocEye));
        mLeftEye.DrawImage(graphics, lEye, mPlacedR);

        /// drawing right eye
        Point rEye = TransformPoint(Point(rightX, yLocEye));
        mRightEye.DrawImage(graphics, rEye, mPlacedR);
    }
    else
    {
        DrawEye(Point(leftX, yLocEye), graphics);
        DrawEye(Point(rightX, yLocEye), graphics);
    }

}

/**
 * Set keyframe based on current status
 */
void CHeadTop::SetKeyframe()
{
    CDrawable::SetKeyframe();
    mChannel.SetKeyframe(GetPosition());

}

/**
 *  Get current channel from animation system
 */
void CHeadTop::GetKeyframe()
{
    CDrawable::GetKeyframe();
    if (mChannel.IsValid())
    {
        SetPosition(mChannel.GetPoint());
    }
}

/**
 *  Add channels for this drawable to a timeline
 * \param timeline timeline class
 */
void CHeadTop::SetTimeline(CTimeline* timeline)
{
    CImageDrawable::SetTimeline(timeline);
    timeline->AddChannel(&mChannel);
}


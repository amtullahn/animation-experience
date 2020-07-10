/**
 * \file HeadTop.h
 *
 * \author Amtullah Naalwala
 *
 *  Draws features for headtop
 */

#pragma once
#include "ImageDrawable.h"
#include "AnimChannelPoint.h"
#include "RotateDrawable.h"

/// Constant converts radius to diameter
const double radToDiam = 57.295779513;

/**
 * Draws features for headtop
 */
class CHeadTop :
	public CImageDrawable
{
public:

	/// Constructor
	/// param name drawable name
	/// param filename filename for the image
	CHeadTop(const std::wstring& name, const std::wstring& filename);

	/// Destructor
	virtual ~CHeadTop();

	//Gdiplus::Point TransformPoint(Gdiplus::Point p);

	virtual void DrawEyebrow(Gdiplus::Point p1, Gdiplus::Point p2, Gdiplus::Graphics* graphics);
	virtual void DrawEye(Gdiplus::Point p, Gdiplus::Graphics* graphics);

	/// Default constructor (disabled)
	CHeadTop() = delete;

	/// Copy constructor (disabled)
	CHeadTop(const CHeadTop&) = delete;

	/// Assignment operator (disabled)
	void operator=(const CHeadTop&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/// Checks if object is movable
	/// \return True if movable
	virtual bool IsMovable() override { return true; }

	/// Get left eye
	/// \returns pointer to the left eye
	CRotateDrawable* GetLeftEye() { return& mLeftEye; }

	/// Get right eye
	/// \returns poointer to the right eye
	CRotateDrawable* GetRightEye() { return &mRightEye; }

	/// Set eye center point
	/// \param center center point
	void SetEyeCenter(Gdiplus::Point center) { mCenterEye = center; }

	/// Get eyes center point
	/// \returns mCenterEye center point
	Gdiplus::Point GetEyeCenter() const {return mCenterEye; }

	/// Sets the distance between eyes
	/// \param dist Dist set distance between eyes
	void SetEyeDistance(int dist) { mEyeDistance = dist; }

	///Get distance between eyes
	/// \returns mEyeDistance distance between eyes
	int GetEyeDistance() const { return mEyeDistance; }

	virtual void SetKeyframe();

	virtual void GetKeyframe();

	virtual void SetTimeline(CTimeline* timeline);

private:

	Gdiplus::Point TransformPoint(Gdiplus::Point p);

	/// Point for eye center
	Gdiplus::Point mCenterEye = Gdiplus::Point(55, 79);

	/// int of distance between eyes
	int mEyeDistance = 27;

	/// This point's channel
	CAnimChannelPoint mChannel;

	/// Bitmap for left image of eye
	CRotateDrawable mLeftEye;

	/// Bitmap for right image of eye
	CRotateDrawable mRightEye;

};


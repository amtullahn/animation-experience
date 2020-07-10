/**
 * \file AnimChannelPoint.h
 *
 * \author Amtullah Naalwala
 *
 *  Animation channel for Points
 */

#pragma once
#include "AnimChannel.h"


/**
 * Animation channel for Points
 */
class CAnimChannelPoint :
	public CAnimChannel
{
public:
    CAnimChannelPoint();
    virtual ~CAnimChannelPoint();

    /// Copy constructor disabled
    CAnimChannelPoint(const CAnimChannelPoint&) = delete;
    ///Assignment operator disabled
    void operator=(const CAnimChannelPoint&) = delete;

    /// Get the point
    /// \returns mPoint Point
    Gdiplus::Point GetPoint() { return mPoint; }

    void SetKeyframe(Gdiplus::Point point);

    /** Class that represents a keyframe */
    class KeyframePoint : public CAnimChannel::Keyframe
    {
    public:

        /** Constructor
         * \param channel The channel we are for
         * \param point The point for the keyframe 
         */
        KeyframePoint(CAnimChannelPoint* channel, Gdiplus::Point point) :
            Keyframe(channel), mChannel(channel), mPoint(point) {}

        /// Default constructor (disabled)
        KeyframePoint() = delete;
        /// Copy constructor (disabled)
        KeyframePoint(const KeyframePoint&) = delete;

        /// Assignment operator disabled
        void operator=(const KeyframePoint&) = delete;

        /** Get the Point
        * \returns mPoint Point
        */
        Gdiplus::Point GetPoint() { return mPoint; }

        /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyfraem 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the Point */
        virtual void UseOnly() override { mChannel->mPoint = mPoint; }

    private:
        /// angle for the keyframe
        Gdiplus::Point mPoint = Gdiplus::Point(0,0);

        /// The channel this keyframe is associated with
        CAnimChannelPoint* mChannel;
    };

protected:
    void Tween(double t);

private: 

    /// point for channel
    Gdiplus::Point mPoint = Gdiplus::Point(0, 0);

    /// The first angle keyframe
    KeyframePoint* mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframePoint* mKeyframe2 = nullptr;


};


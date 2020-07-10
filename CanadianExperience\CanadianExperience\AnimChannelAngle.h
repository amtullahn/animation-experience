/**
 * \file AnimChannelAngle.h
 *
 * \author Amtullah Naalwala
 *
 * Animation channel for angles
 */

#pragma once
#include "AnimChannel.h"

/**
 * Animation channel for angles
 */
class CAnimChannelAngle :
	public CAnimChannel
{
public:
    CAnimChannelAngle();
    virtual ~CAnimChannelAngle();

    /// Copy constructor disabled
    CAnimChannelAngle(const CAnimChannelAngle&) = delete;

    /// Assignment operator disabled
    void operator=(const CAnimChannelAngle&) = delete;
    /// Get the angle
    /// \returns mAngle angle
    double GetAngle() { return mAngle; }

    void SetKeyframe(double angle);

    /** Class that represents a keyframe */
    class KeyframeAngle : public CAnimChannel::Keyframe
    {
    public:
      
        /** Constructor
         * \param channel The channel we are for
         * \param angle The angle for the keyframe */
        KeyframeAngle(CAnimChannelAngle* channel, double angle) :
            Keyframe(channel), mChannel(channel), mAngle(angle) {}

        /// Default constructor (disabled)
        KeyframeAngle() = delete;
        
        /// Copy constructor (disabled)
        KeyframeAngle(const KeyframeAngle&) = delete;

        /// Assignment operator disabled
        void operator=(const KeyframeAngle&) = delete;

        /** Get the angle
        * \returns mAngle angle
        */
        double GetAngle() { return mAngle; }

         /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyfraem 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the angle */
        virtual void UseOnly() override { mChannel->mAngle = mAngle; }

    private:
        /// angle for the keyframe
        double mAngle = 0;
  
        /// The channel this keyframe is associated with
        CAnimChannelAngle* mChannel;
    };

protected:
    /**
     * Compute an angle that is an interpolation between two keyframes
     *
     * This function is called after Use1 and Use2, so we have pointers to
     * to valid keyframes of the type KeyframeAngle. This function does the
     * tweening.
     * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
     * interpolate between.
     */
    void Tween(double t);

private:

    /// angle for the channel
    double mAngle = 0;

    /// The first angle keyframe
    KeyframeAngle* mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle* mKeyframe2 = nullptr;

};


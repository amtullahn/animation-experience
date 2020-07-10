/**
 * \file Timeline.cpp
 *
 * \author Amtullah Naalwala
 *
 * Implements a timeline that manages the animation
 */

#include "pch.h"
#include "Timeline.h"
#include "AnimChannel.h"

/**
* Constructor
*/
CTimeline::CTimeline()
{
}

/**
 * Destructor
 */
CTimeline::~CTimeline()
{
}

/**
 * Add a channel to this timeline
 * \param channel the channel to add 
 */
void CTimeline::AddChannel(CAnimChannel* channel)
{
    mChannels.push_back(channel);
    channel->SetTimeline(this);
}

/**
 * Deletes the keyframe
 */
void CTimeline::DeleteKeyframe()
{
    for (auto chan :mChannels)
    {
        chan->DeleteKeyframe();
    }
}

/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
* \param t Time to set to
*/
void CTimeline::SetCurrentTime(double t)
{
    // Set the time
    mCurrentTime = t;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}

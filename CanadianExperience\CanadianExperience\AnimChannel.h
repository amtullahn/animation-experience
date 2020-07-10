#pragma once
#include <string>
#include <memory>
#include <vector>
class CTimeline;

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */
class CAnimChannel
{
public:
    CAnimChannel();
    virtual ~CAnimChannel();

    /// Copy constructor disabled
    CAnimChannel(const CAnimChannel&) = delete;

    /// Assignment operator disabled
    void operator=(const CAnimChannel&) = delete;

    /** Set name member variable
    * \param name the name
    */
    void SetName(const std::wstring& name) { mName = name; }

    /** Get the name member variable
    * \returns mName name of the channel
    */
    std::wstring GetName() const { return mName; }

    /// Set timeline member variable
    /// \param timeline pointer to timeline object
    void SetTimeline(CTimeline* timeline) { mTimeline = timeline; }

    /// Get timeline member variable pointer
    /// \returns mTimeline pointer to timeline
    CTimeline* GetTimeline() { return mTimeline; }
    
    /// returns true or false for validity
    /// \returns true true if valid
    bool IsValid();

    /// Set key frame
    /// \param currFrame the current frame
    void SetFrame(int currFrame);

    /// Delete keyframe
    void DeleteKeyframe();

    /** Class that represents a keyframe */
    class Keyframe
    {
    public:

        /// Default constructor (disabled)
        Keyframe() = delete;
        /// Copy constructor (disabled)
        Keyframe(const Keyframe&) = delete;
        /// Assignment operator disabled
        void operator=(const Keyframe&) = delete;

        /// Set frame member variable
        /// \param frame the frame
        void SetFrame(const int frame) { mFrame = frame; }

        /// Get the frame member variable
        /// \returns mFrame frame
        int GetFrame() const { return mFrame; }

        /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() = 0;

        /** Use this keyframe as keyfraem 2 */
        virtual void UseAs2() = 0;

        /** Use this keyframe as the angle */
        virtual void UseOnly() = 0;

    protected:

        /** Constructor
         * \param channel Channel we are associated with */
        Keyframe(CAnimChannel* channel) : mChannel(channel) {}

        /// frame the keyframe positioned at
        int mFrame;

    private:
        /// The channel this keyframe is associated with
        CAnimChannel* mChannel;
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
    virtual void Tween(double t) = 0;
    void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);


private:
    std::wstring mName;     ///< The channel name
    int mKeyframe1 = -1;    ///< The first keyframe
    int mKeyframe2 = -1;    ///< The second keyframe

    /// timeline object
    CTimeline* mTimeline = nullptr;

    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<Keyframe>> mKeyframes;
};


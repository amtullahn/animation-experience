/**
 * \file Picture.h
 *
 * \author Amtullah Naalwala
 *
 *  The picture we are drawing 
 */

#pragma once
#include <vector>
#include "Actor.h"
#include "Timeline.h"

class CPictureObserver;

/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
class CPicture
{
public:
    CPicture() {}

    /// Copy Constructor (Disabled)
    CPicture(const CPicture&) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const CPicture&) = delete;

    /** The picture size
    * \returns Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** The picture size
    * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver* observer);
    void RemoveObserver(CPictureObserver* observer);
    void UpdateObservers();
    void Draw(Gdiplus::Graphics* graphics);
    void AddActor(std::shared_ptr<CActor> actor);

    void SetAnimationTime(double time);

    /** Iterator that iterate*/
    class Iter
    {
    public:
        /** Constructor
        * \param picture picture we are iterating over
        * \param pos position in the collection
        */
        Iter(CPicture* picture, int pos) : mPicture(picture), mPos(pos) {}

        /** Test for end of Iterator
        * \param other Iterator to compare to
        * \returns True if position equals not equal to other position
        */
        bool operator != (const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** Test for end of Iterator
        * \param other Iterator to compare to
        * \returns True if position equals not equal to other position
        */
        bool operator == (const Iter& other) const
        {
            return mPos == other.mPos;
        }

        /** Increment the iterator
        * \returns reference to iterator 
        */
        const Iter& operator++()
        {
            mPos += 1;
            return *this;
        }

        /** Get value at current position 
        * \returns Value at mPos in the collection
        */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }
    private:
        /// Picture we are iterating over
        CPicture* mPicture;
        /// Position in collection
        int mPos;
    };

    /// Get an iterator for the beginning of the collection 
    /// \returns Iter object at position 0
    Iter begin() { return Iter(this, 0); }

    /// Get an iter for the end of the collection
    /// \returns Iter object at position past the end
    Iter end() { return Iter(this, mActors.size()); }

    /** Get a pointer to the Timeline object
    * \returns Pointer to the Timeline object
    */
    CTimeline* GetTimeline() { return &mTimeline; }


private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);

    /// The observers of this picture
    std::vector<CPictureObserver*> mObservers;

    /// The actors in the picture
    std::vector<std::shared_ptr<CActor>> mActors;

    /// The animation timeline
    CTimeline mTimeline;

};


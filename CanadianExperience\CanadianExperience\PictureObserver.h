/**
 * \file PictureObserver.h
 *
 * \author Amtullah Naalwala
 *
 *  OBserver base class for a picture
 */

#pragma once

#include <memory>
#include <vector>
class CPicture;

/**
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
class CPictureObserver
{
public:
    /// Copy Constructor (Disabled)
    CPictureObserver(const CPictureObserver&) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const CPictureObserver&) = delete;

    virtual ~CPictureObserver();

    void SetPicture(std::shared_ptr<CPicture> picture);

    /// This function is called to update any observers
    virtual void UpdateObserver() = 0;

    /// Getter for the picture
    /// \returns mPicture the observed picture
    std::shared_ptr<CPicture>GetPicture() { return mPicture; }

protected:
    CPictureObserver() {}

private:
    /// Picture we are observing
    std::shared_ptr<CPicture> mPicture;
};


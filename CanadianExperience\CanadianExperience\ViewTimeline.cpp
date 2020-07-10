/**
 * \file ViewTimeline.cpp
 *
 * \author Amtullah Naalwala 
 */


#include "pch.h"
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "MainFrm.h"
#include "Picture.h"
#include "Timeline.h"

#include <sstream>

using namespace std;
using namespace Gdiplus;

/// The window height in pixels
const int WindowHeight = 60;

/// The spacing from the top of the 
/// window to the top of the tick marks in pixels
const int BorderTop = 20;

/// Space to the left of the scale in pixels
const int BorderLeft = 10;

/// Space to the right of the scale in pixels
const int BorderRight = 10;

/// The spacing between ticks on the timeline in pixels
const int TickSpacing = 3;

/// The length of a short tick mark in pixels
const int TickShort = 10;

/// The length of a long tick mark in pixels
const int TickLong = 20;


IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)

/** Constructor */
CViewTimeline::CViewTimeline()
{
    /// Bitmap image for the pointer
    //std::unique_ptr<Gdiplus::Bitmap> mPointer;
    mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer-down.png"));
    assert(mPointer->GetLastStatus() == Ok);

}

/** Destructor */
CViewTimeline::~CViewTimeline()
{
}

/**
 * Force an update of this window when the picture changes
 */
void CViewTimeline::UpdateObserver()
{
    Invalidate();
    UpdateWindow();
}




/** Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
    CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window 
 * \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
    // Get the timeline
    CTimeline* timeline = GetPicture()->GetTimeline();

    // Set the scroll system correctly
    CSize sizeTotal(timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, WindowHeight);
    SetScrollSizes(MM_TEXT, sizeTotal);
    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 10);

    CRect rect;
    GetClientRect(&rect);
    int hit = rect.Height();
    int wid = rect.Width();
    // TODO: Drawing code goes here
    auto a = mPointer.get();
    graphics.DrawImage(mPointer.get(), int(BorderLeft + TickSpacing * timeline->GetFrameRate() * timeline->GetCurrentTime() - mPointer->GetWidth() / 2), int(BorderTop), mPointer->GetWidth(), mPointer->GetHeight());

    Pen tickpen(Color::Black, 1);

    for (int tickNum = 0; tickNum < timeline-> GetNumFrames(); tickNum++)
    {
        bool eachSecond = (tickNum % timeline->GetFrameRate()) == 0;

        if (eachSecond) {

            // Convert the tick number to seconds in a string
            std::wstringstream str;
            str << tickNum / timeline->GetFrameRate();
            std::wstring wstr = str.str();

            RectF size;
            PointF origin(0.0f, 0.0f);
            graphics.MeasureString(wstr.c_str(), wstr.size(),
                &font, origin, &size);

            SolidBrush brush(Color(0, 0, 0));
            graphics.DrawString(wstr.c_str(), -1, &font, PointF(BorderLeft + TickSpacing * tickNum - size.Width / 2, BorderTop + TickLong + size.Height / 20), &brush);

            graphics.DrawLine(&tickpen, BorderLeft + TickSpacing * tickNum, BorderTop + TickLong, BorderLeft + TickSpacing * tickNum, BorderTop);

        }

        else 
        {
            graphics.DrawLine(&tickpen, BorderLeft + TickSpacing * tickNum, BorderTop + TickShort, BorderLeft + TickSpacing * tickNum, BorderTop);


        }
    }
}


/** Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context 
 * \return FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

/** Handle the Edit>Set Keyframe menu option */
 void CViewTimeline::OnEditSetkeyframe()
 {
     for (auto actor : *GetPicture())
     {
         actor->SetKeyframe();
     }
 }



 // Doxygen sometimes gets confused by these message 
 // maps, since they look like functions. I've found
 // it helps to move them to the end of the file.
 BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
	 ON_WM_CREATE()
	 ON_WM_ERASEBKGND()
	 ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
     ON_WM_LBUTTONDOWN()
     ON_WM_MOUSEMOVE()
     ON_COMMAND(ID_EDIT_DELETEKEYFRAME32782, &CViewTimeline::OnEditDeletekeyframe)
 END_MESSAGE_MAP()

/**
 * Handle a left button mouse press event
 * \param nFlags flags associated with the mouse press
 * \param point the location of the mouse press
 */
 void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
 {
     // TODO: Add your message handler code here and/or call default

      // Convert mouse coordinates to logical coordinates
     CClientDC dc(this);
     OnPrepareDC(&dc);
     dc.DPtoLP(&point);

     //GetPicture()->UpdateObservers();

     int x = point.x;

     // Get the timeline
     CTimeline* timeline = GetPicture()->GetTimeline();
     int pointerX = (int)(timeline->GetCurrentTime() *
         timeline->GetFrameRate() * TickSpacing + BorderLeft);

     mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 &&
         x <= pointerX + (int)mPointer->GetWidth() / 2;

     if (mMovingPointer)
     {
         int xx = 0;
     }

     __super::OnLButtonDown(nFlags, point);
 }


/**
 * Called when mouse moved
 * \param nFlags Flags associated with mouse movement
 * \param point where button pressed
 */
 void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
 {
     // TODO: Add your message handler code here and/or call default
      // Convert mouse coordinates to logical coordinates
     CClientDC dc(this);
     OnPrepareDC(&dc);
     dc.DPtoLP(&point);
     // Get timeline
     CTimeline* timeline = GetPicture()->GetTimeline();

     if (nFlags && MK_LBUTTON && mMovingPointer) 
     {
         double time = double(point.x - BorderLeft) / (timeline->GetFrameRate() * TickSpacing);
         if (time < 0)
         {
             time = 0;
         
         }
         else if (time > timeline->GetDuration())
         {
             time = timeline->GetDuration();
         }
         GetPicture()->SetAnimationTime(time);
     }
     else
     {
         mMovingPointer = false;
     }

     UpdateObserver();

     __super::OnMouseMove(nFlags, point);
 }


/**
 * Deleting the keyframe
 */
 void CViewTimeline::OnEditDeletekeyframe()
 {
     GetPicture()->GetTimeline()->DeleteKeyframe();
     GetPicture()->SetAnimationTime(GetPicture()->GetTimeline()->GetCurrentTime());
 }

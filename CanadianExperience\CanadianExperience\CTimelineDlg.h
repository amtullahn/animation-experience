/**
 * \file CTimelineDlg.h
 *
 * \author Amtullah Naalwala
 *
 * Dialog box for timeline 
 */

#pragma once

class CTimeline;

// CTimelineDlg dialog

/**
 *  Dialog box for timeline
 */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	/// Standard constructor
	CTimelineDlg(CWnd* pParent = nullptr);  
	virtual ~CTimelineDlg();
	void SetTimeline(CTimeline* timeline);

	void Take();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	/// Num frames
	int mNumFrames;

	/// The timeline we are editing
	CTimeline* mTimeline = nullptr;

	/// Frame rate
	int mFrameRate;
};

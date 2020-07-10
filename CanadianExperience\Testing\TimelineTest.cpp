#include "pch.h"
#include "TimelineTest.h"
#include "Timeline.h"
#include <AnimChannelAngle.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
    TEST_CLASS(CImageDrawableTest)
    {
    public:
        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestCTimelineNumFrames)
        {
            CTimeline timeline;
            /// Default value
            Assert::AreEqual(300, timeline.GetNumFrames());
            /// Test the setter
            timeline.SetNumFrames(320);
            Assert::AreEqual(320, timeline.GetNumFrames());
        }

        TEST_METHOD(TestCTimelineFrameRate)
        {
            CTimeline timeline;
            /// Default value
            Assert::AreEqual(30, timeline.GetFrameRate());
            ///Test the setter
            timeline.SetFrameRate(90);
            Assert::AreEqual(90, timeline.GetFrameRate());
        }

        TEST_METHOD(TestCTimelineCurrentTime)
        {
            CTimeline timeline;
            /// Default value
            Assert::AreEqual(double(0), timeline.GetCurrentTime());
            ///Test the setter
            timeline.SetCurrentTime(5000);
            Assert::AreEqual(double(5000), timeline.GetCurrentTime());
            
        }

        TEST_METHOD(TestCTimelineGetDuration)
        {
            CTimeline timeline;

            /// Default value
            Assert::AreEqual(10, timeline.GetDuration(), 0.0001);

            /// Changed duration
            timeline.SetFrameRate(375);
            Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);

            timeline.SetNumFrames(789);
            Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
        }

        TEST_METHOD(TestCTimelineGetCurrentFrame)
        {
            CTimeline timeline;

            /// Default value
            Assert::AreEqual(0, timeline.GetCurrentFrame());

            /// Changed time 
            timeline.SetCurrentTime(9.27);
            Assert::AreEqual(278, timeline.GetCurrentFrame());
        }

        TEST_METHOD(TestCTimelineAdd)
        {
            CTimeline timeline;
            CAnimChannelAngle channel;

            timeline.AddChannel(&channel);
            Assert::IsTrue(&timeline == channel.GetTimeline());
        }

    };
}
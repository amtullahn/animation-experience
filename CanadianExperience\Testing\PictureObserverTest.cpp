#include "pch.h"
#include "CppUnitTest.h"
#include "PictureObserverTest.h"
#include "PictureObserver.h"
#include "Picture.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	class CPictureObserverMock : public CPictureObserver
	{
	public:
		CPictureObserverMock() : CPictureObserver() {}
		virtual void UpdateObserver() override { mUpdated = true; }
		bool mUpdated = false;

	};

	TEST_CLASS(CPictureObserverTest)
	{
	public:
		TEST_METHOD(TestCPictureObserverConstruct)
		{
			CPictureObserverMock observer;

		}

		TEST_METHOD(TestCPictureObserverOneObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
			//tests to see if CPictureObserver::GetPicture works
			Assert::IsTrue(picture == observer.GetPicture());

		}

		TEST_METHOD(TestCPictureObserverMultipleObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create mock observers object
			CPictureObserverMock observer1;
			CPictureObserverMock observer2;


			// And set it for the observers:
			observer1.SetPicture(picture);
			observer2.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer1.mUpdated);
			Assert::IsTrue(observer2.mUpdated);

		}

		TEST_METHOD(TestCPictureObserverRemoveObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer1;

			// And set it for the observer:
			observer1.SetPicture(picture);
			{
				//remove the mock observer obj 2
				CPictureObserverMock observer2;

				// And set it for the observer 2:
				observer2.SetPicture(picture);


			}

			picture->UpdateObservers();

			Assert::IsTrue(observer1.mUpdated);

		}



	};
}
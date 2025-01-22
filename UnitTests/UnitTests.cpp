#include "pch.h"
#include "CppUnitTest.h"
#include "../Academic Graduation Hustle/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Game_Tests
{
	TEST_CLASS(TaskLogic_Tests)
	{
	public:
		
		TEST_METHOD(TaskSystem)
		{
			struct Invoker : public TaskInvoker
			{
				~Invoker()
				{ }
			};
			struct TestSubject : public TaskReciever
			{
				bool passed;

				TestSubject()
					: passed(false)
				{ }
				void pass()
				{
					this->passed = true;
				}
			};
			struct PassTest : public Task
			{
				TestSubject* subject;

				PassTest(TestSubject* subject_ptr)
					:subject(subject_ptr)
				{ }

				void execute() override
				{
					this->subject->pass();
				}
			};

			Invoker invoker;
			TestSubject subject;

			invoker.AssignTask(new PassTest(&subject));
			invoker.InvokeTask();

			Assert::IsTrue(subject.passed);
		}
	};
	TEST_CLASS(Scene_Tests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
	TEST_CLASS(GameObjects_Tests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
	TEST_CLASS(ObjectCreators_Tests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
	TEST_CLASS(WindowHandler_Tests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
	TEST_CLASS(GameManager_Tests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};
}
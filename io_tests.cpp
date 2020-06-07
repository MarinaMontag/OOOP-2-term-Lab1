#include "pch.h"
#include "CppUnitTest.h"

#include "../Project2/QueueP.h"
#include "../Project2/QueueP.cpp"
#include "../Project2/Task.h"
#include "../Project2/Task.cpp"
#include "../Project2/Guarantee.h"
#include "../Project2/Guarantee.cpp"
#include "../Project2/Regulation.h"
#include "../Project2/Regulation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	namespace io_tests
	{
		TEST_CLASS(io_tests)
		{
		public:
			TEST_METHOD(WriteReadTaskTest)
			{
				// тест-кейс перевіряє чи првильно об'єкт записується у файл та зчитується з нього
				string filename = "file.txt";
				ofstream os(filename);
				Assert::IsTrue(os.is_open());
				string taskName = "tn", execName = "en", firm = "fn";
				int period = 10;
				Task task1(taskName, execName, firm, period);
				os << &task1;
				os.close();
				ifstream is(filename);
				Assert::IsTrue(is.is_open());
				Task task2;
				is >> task2;
				Assert::IsTrue(task1.getTaskName() == task2.getTaskName());
				Assert::IsTrue(task1.getExecutorName() == task2.getExecutorName());
				Assert::IsTrue(task1.getFirma() == task2.getFirma());
				Assert::IsTrue(task1.getDaysOnTask() == task2.getDaysOnTask());
			}
		};
	}
}
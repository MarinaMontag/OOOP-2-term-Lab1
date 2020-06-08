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
	namespace queue_tests
	{
		TEST_CLASS(queue_tests)
		{
		public:
			TEST_METHOD(QueueCreate)
			{
				// перевіряє створення черги
				// якщо вона пуста на почтаку - тест успішний
				QueueP q;
				Assert::IsTrue(q.isEmpty());
			};
			TEST_METHOD(QueuePushNew)
			{
				// перевіряє додавання об'єкта
				// якщо кількість збільшилась на 1 - тест успішний
				QueueP q;
				Task task;
				ifstream is;
				q.Push(&task, is);
				Assert::IsTrue(q.getAmount() == 1);
			};
			TEST_METHOD(QueuePushGuarantee)
			{
				// перевіряє вставку об'єкта Guarantee
				// якщо на вершині черги цей об'єкт -  тест успішний
				QueueP q;				
				Guarantee* task = new Guarantee;
				ifstream is;
				q.Push(task, is);
				Assert::IsTrue(q.Pop()->isGuarantee() == 1);

			}
			TEST_METHOD(QueuePushRegulation)
			{
				// перевіряє вставку об'єкта Regulation
				// якщо на вершині черги цей об'єкт -  тест успішний
				QueueP q;
				Regulation* task = new Regulation;
				ifstream is;
				q.Push(task, is);
				Assert::IsTrue(q.Pop()->isRegulation() == 1);
			}
		};

	}
	namespace task_tests
	{
		TEST_CLASS(task_tests)
		{
			TEST_METHOD(TaskCreate)
			{
				// перевіряє ствоерння об'єтку Task 
				// якщо передані дані відповідають полям - тест успішний
				string taskName = "tn", execName = "en", firm = "fn";
				int period = 10;
				Task task(taskName, execName, firm, period);
				Assert::IsTrue(task.getTaskName() == taskName);
				Assert::IsTrue(task.getExecutorName() == execName);
				Assert::IsTrue(task.getFirma() == firm);
				Assert::IsTrue(task.getDaysOnTask() == period);
			}
			TEST_METHOD(GuaranteeCreate)
			{
				// перевіряє ствоерння об'єтку Guarantee
				// якщо передані дані відповідають полям - тест успішний
				string taskName = "tn", execName = "en", firm = "fn";
				int period = 10; int tu = 5, tl = 5;
				Guarantee task(taskName, execName, firm, period, tu, tl);
				Assert::IsTrue(task.getTaskName() == taskName);
				Assert::IsTrue(task.getExecutorName() == execName);
				Assert::IsTrue(task.getFirma() == firm);
				Assert::IsTrue(task.getDaysOnTask() == period);
				Assert::IsTrue(task.getTimeUsed() == tu);
				Assert::IsTrue(task.getTimeLeftGuar() == tl);
			}
			TEST_METHOD(RegulationCreate)
			{
				// перевіряє ствоерння об'єтку Regulation
				// якщо передані дані відповідають полям - тест успішний
				string taskName = "tn", execName = "en", firm = "fn";
				int period = 10; 
				string kind = "sk";
				int am = 1;
				Regulation task(taskName, execName, firm, period, kind, am);
				Assert::IsTrue(task.getTaskName() == taskName);
				Assert::IsTrue(task.getExecutorName() == execName);
				Assert::IsTrue(task.getFirma() == firm);
				Assert::IsTrue(task.getDaysOnTask() == period);
				Assert::IsTrue(task.getKindRegTask() == kind);
				Assert::IsTrue(task.getAmountComplTask() == am);
			}
		};
	}
}
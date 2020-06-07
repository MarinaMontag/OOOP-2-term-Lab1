#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/QueueP.h"
#include "../Project1/QueueP.cpp"
#include "../Project1/Task.h"
#include "../Project1/Task.cpp"
#include "../Project1/Guarantee.h"
#include "../Project1/Guarantee.cpp"
#include "../Project1/Regulation.h"
#include "../Project1/Regulation.cpp"


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
				QueueP q;
				Assert::IsTrue(q.isEmpty());
			};
			TEST_METHOD(QueuePushNew)
			{
				QueueP* q = new QueueP;
				Task* task = new Task;
				istream* is = new ifstream;
				q->Push(task, *is);
				Assert::IsTrue(q->getAmount() == 1);
				delete(q);
				delete(task);
				delete(is);
			};
			TEST_METHOD(QueuePushGuarantee)
			{
				QueueP* q = new QueueP;
				Guarantee* task = new Guarantee;
				istream* is = new ifstream;
				q->Push(task, *is);
				Assert::IsTrue(q->Pop()->isGuarantee() == 1);
				delete(q);
				delete(task);
				delete(is);
			}
			TEST_METHOD(QueuePushRegulation)
			{
				QueueP* q = new QueueP;
				Regulation* task = new Regulation;
				istream* is = new ifstream;
				q->Push(task, *is);
				Assert::IsTrue(q->Pop()->isRegulation() == 1);
				delete(q);
				delete(task);
				delete(is);
			}
		};

	}
	namespace task_tests
	{
		TEST_CLASS(task_tests)
		{
			TEST_METHOD(TaskCreate)
			{
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
#include "Task.h"


Task::Task() : taskName(""), executorName(""), Firma(""), daysOnTask(0) {}
Task::Task(string _taskName, string _executorName, string _Firma, int _daysOnTask) :
	taskName(_taskName), executorName(_executorName), Firma(_Firma), daysOnTask(_daysOnTask) {}

Task::~Task() {}

void			Task::setTaskName(const string _taskName) { taskName = _taskName; }
const string	Task::getTaskName() const { return taskName; }

void			Task::setExecutorName(const string _executorName) { executorName = _executorName; }
const string	Task::getExecutorName() const { return executorName; }

void			Task::setFirma(const string _firma) { Firma = _firma; }
const string	Task::getFirma() const { return Firma; }

void			Task::setDaysOnTask(const int _daysOnTask) { daysOnTask = _daysOnTask; }
const int		Task::getDaysOnTask() const { return daysOnTask; }

void			Task::show() const
{
	cout << "Task name: " << taskName << endl <<
		"Executor name: " << executorName << endl <<
		"Firma: " << Firma << endl <<
		"Days on task: " << daysOnTask << endl;
}

bool	Task::isRegulation() { return false; };
bool	Task::isGuarantee() { return false; };


Task& Task::input(ifstream& in, Task* object) const
{
	string _taskName;
	string _executorName;
	string _Firma;
	int _daysOnTask;

	getline(in, _taskName);
	getline(in, _executorName);
	getline(in, _Firma);
	in >> _daysOnTask;

	*object = Task(_taskName, _executorName, _Firma, _daysOnTask);
	return (*object);
}
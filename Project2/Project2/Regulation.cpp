#include "Regulation.h"


Regulation::Regulation() : Task(), kindRegTask(""), amountComplTask(0) {}
Regulation::Regulation(string _taskName, string _executorName, string _Firma, int _daysOnTask, string _kindRegTask, int _amountComplTask) :
	Task(_taskName, _executorName, _Firma, _daysOnTask), kindRegTask(_kindRegTask), amountComplTask(_amountComplTask) {};

Regulation::~Regulation() {}

void			Regulation::setKindRegTask(const string _kindRegTask) { kindRegTask = _kindRegTask; }
const string	Regulation::getKindRegTask() const { return kindRegTask; }

void			Regulation::setAmountComplTask(const int _amountComplTask) { amountComplTask = _amountComplTask; }
const int		Regulation::getAmountComplTask() const { return amountComplTask; }

void Regulation::show() const
{
	// вивід завдання
	cout << "----Regulation Task----" << endl;
	Task::show();
	cout << "Kind Regulation Task: " << kindRegTask << endl <<
		"Amount Complete Task: " << amountComplTask << endl;
}

bool Regulation::isGuarantee() { return false; }

bool Regulation::isRegulation() { return true; }

ofstream& operator << (ofstream& out, const Regulation* data)
{
	// вивід у файл
	out << data->getKindRegTask() << endl;
	out << data->getAmountComplTask() << endl;

	return (out);
}

ofstream& Regulation::returned(ofstream& out, const Task* data) const
{
	out << 2 << endl;
	Task::returned(out, data);
	out << (Regulation*)data;
	return (out);
}

Task& operator >> (ifstream& in, Regulation* object)
{
	// звчитування з файлу
	string _kindRegTask;
	int _amountComplTask;
	string something;
	getline(in, something);
	getline(in, _kindRegTask);
	in >> _amountComplTask;
	object->setKindRegTask(_kindRegTask);
	object->setAmountComplTask(_amountComplTask);

	return (*object);
}

Task& Regulation::input(ifstream& in, Task* object) const
{
	Task::input(in, object);
	in >> (Regulation*)object;
	return (*object);
}
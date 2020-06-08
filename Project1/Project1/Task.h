#ifndef TASK
#define TASK

using namespace std;
#include <string>
#include <fstream>
#include <iostream>

class Task
{
public:
	Task();
	Task(string _taskName, string _executorName, string _Firma, int _daysOnTask);

	virtual ~Task();

	void			setTaskName(const string _taskName);
	const string	getTaskName() const;

	void			setExecutorName(const string _executorName);
	const string	getExecutorName() const;

	void			setFirma(const string _firma);
	const string	getFirma() const;

	void			setDaysOnTask(const int _daysOnTask);
	const int		getDaysOnTask() const;

	virtual void	show() const;

	virtual bool	isRegulation();
	virtual bool	isGuarantee();

	virtual	Task& input(ifstream& in, Task* object) const;


private:
	string taskName;
	string executorName;
	string Firma;
	int	daysOnTask;
};

#endif
#ifndef GUARANTEE
#define GUARANTEE

#include "Task.h"

class Guarantee: public Task
{
public:
	Guarantee();
	Guarantee(string _taskName, string _executorName, string _Firma, int _daysOnTask, int _timeUsed, int _timeLeftGuar);

	~Guarantee();

	void		setTimeUsed(const int _timeUsed);
	const int	getTimeUsed() const;

	void		setTimeLeftGuar(const int _timeLeftGuar);
	const int	getTimeLeftGuar() const;

	virtual void show() const;
	virtual	bool isGuarantee();
	virtual	bool isRegulation();

	virtual Task& input(ifstream& in, Task* object) const;
	friend Task& operator >> (ifstream& in, Guarantee* object);

private:
	int timeUsed;
	int timeLeftGuar;
};

#endif
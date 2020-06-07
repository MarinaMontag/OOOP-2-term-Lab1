#pragma once
#ifndef QUEUEP
#define QUEUEP

#include "Task.h"
#include "Guarantee.h"
#include "Regulation.h"
#include <iostream>
struct Node
{
	Task*	data;
	Node*	next;
	int		priority;
};

class QueueP
{
public:
	QueueP();
	~QueueP();

	bool	isEmpty();
	int		getAmount();
	bool	CompareElements(Node* elementOne, Node* elementTwo);

	void	Push(Task* data, istream&);
	Task* Pop();
	void	Clean();

	void	Show();

	int		MainTask();
	void	Sort();



	friend Task& operator>>(ifstream& in,
		Task& object);

private:
	Node* head;
	Node* tail;
	int		amount;
};

#endif
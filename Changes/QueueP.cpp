#include "QueueP.h"

QueueP::QueueP() : head(NULL), tail(NULL), amount(0){}

QueueP::~QueueP() {}

bool	QueueP::isEmpty()
{
	return head == NULL;
}

int		QueueP::getAmount() { return amount; }

void	QueueP::Push(Task* data, istream& is)
{
	// додавання в чергу
	string trash;
	int _priority = 0;
	cout << "Input priority for new element: ";
	getline(is, trash, '\n');
	_priority = atoi(trash.c_str());
	Node* cptail = tail;
	Node* newData = new Node;
	newData->data = data;
	newData->next = NULL;
	newData->priority = _priority;
	if (head == NULL)
	{
		head = newData;
		tail = newData;
	}
	else
	{
		tail->next = newData;
		tail = tail->next;
	}
	amount++;
	cout << endl << "New element successfully add..." << endl;
}

bool	QueueP::CompareElements(Node* elementOne, Node* elementTwo)
{
	// порівняння тасків за пріорітетом
	return elementOne->priority > elementTwo->priority;
}

Task* QueueP::Pop()
{
	// видалення з верху черги поверненням елемента який виаляється
	if (isEmpty())
	{
		cout << "Container is empty..." << endl;
		return NULL;
	}
	Node* popElement = head;
	Node* cpHead = head;
	while (cpHead->next)
	{
		if (CompareElements(popElement, cpHead->next))
			popElement = cpHead->next;
		cpHead = cpHead->next;
	}
	cpHead = head;
	Node* popElementNext = popElement->next;
	if (popElement == head)
	{
		head = head->next;
		popElement->next = NULL;
		if (tail == popElement)
			tail = head;
	}
	else if (popElement == tail)
	{
		while (cpHead->next != tail)
			cpHead = cpHead->next;
		tail = cpHead;
		tail->next = NULL;
	}
	else
	{
		while (cpHead->next != popElement)
			cpHead = cpHead->next;
		
		cpHead->next = popElementNext;
		popElement->next = NULL;
	}
	Task* data = popElement->data;
	delete popElement;
	amount--;
	cout << "Element successfully remove..." << endl;
	return data;
}

void	QueueP::Clean()
{
	// видалення усіх елементів
	while (!isEmpty())
		Pop();
	cout << "All elements successfully remove..." << endl;
}

void	QueueP::Show()
{
	//друк елементів
	Node* cpHead = head;
	if (isEmpty())
		cout << "Container is empty..." << endl;
	while (cpHead)
	{
		cout << "Priority: " << cpHead->priority << endl;
		cpHead->data->show();
		cpHead = cpHead->next;
		cout << endl;
	}
}

int		QueueP::MainTask()
{
	// запуск функції об'єкта за його назвою фірми
	int count = 0;
	string firm;
	cout << "Input Firm: ";
	getchar();
	getline(cin, firm, '\n');
	Node* cpHead = head;
	while (cpHead)
	{
		if (cpHead->data->getFirma() == firm && cpHead->data->isGuarantee())
			count++;
		cpHead = cpHead->next;
	}
	return (count);
}


void	QueueP::Sort()
{
	// сортування бульбашкою
	Task* swap;
	int swap_priority;
	Node* cpHead = head;
	if (isEmpty())
	{
		cout << "Container is empty..." << endl;
		return;
	}
	while (head->next)
	{
		if (!CompareElements(head, head->next))
		{
			swap = head->data;
			swap_priority = head->priority;
			head->data = head->next->data;
			head->priority = head->next->priority;
			head->next->data = swap;
			head->next->priority = swap_priority;
			head = cpHead;
		}
		else
			head = head->next;
	}
	head = cpHead;
	cout << "Elements were sorted..." << endl;
}

ofstream& operator << (ofstream& out, Node* head)
{
	// вивід вузла черги в файл
	while (head)
	{
		head->data->returned(out, head->data);
		head = head->next;
	}
	return out;
}

void	QueueP::WriteInFile()
{
	// виввід у файл черги
	if (isEmpty())
	{
		cout << "Container is empty..." << endl;
		return;
	}
	ofstream out("Task.txt");
	if (!out.is_open())
	{
		cout << "Cant open file"<< endl;
		return;
	}
	out << head;
	out.close();
	cout << "Successful saving to file" << endl;
}

Task& operator>>(ifstream& in, Task& object)
{
	object.input(in, &object);
	return (object);
}

int		QueueP::ReadFromFile(QueueP Container)
{
	// зчитування черги з файлу
	ifstream in;
	in.open("Task.txt");
	if (!in.is_open())
	{
		cout << "Error opening file!" << endl;
		return (0);
	}

	int k;
	int count = 0;
	while (in >> k)
	{
		string trash;
		getline(in, trash);
		if (k == 1)
		{
			Task* T = new Guarantee;
			in >> *T;
			Container.Push(T, cin);
			count++;
		}
		else if (k == 2)
		{
			Task* T = new Regulation;
			in >> *T;
			Container.Push(T, cin);
			count++;
		}
	}
	*this = Container;
	return (count);
}
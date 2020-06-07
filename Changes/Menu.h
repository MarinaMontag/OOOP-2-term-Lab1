#ifndef MENU
#define MENU

#include "QueueP.h"

class Menu
{
public:
	static Menu* CreateMenu();
	void		Begin();
	static bool RemoveMenu();
private:
	QueueP Container;
	static Menu* _self;
	Menu() {}
	virtual ~Menu() {}
};

#endif


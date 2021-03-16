#ifndef TOOLKIT_CONCRETE_ITEMS_H
#define TOOLKIT_CONCRETE_ITEMS_H

#include "toolkitItemsInterface.h"
#include <iostream>

class BasicScrollbar : public IScrollBar {
public:
	BasicScrollbar() { std::cout << "creating basic scrollbar\n"; }
};

class BasicMouseIcon : public IMouseIcon {
public:
	BasicMouseIcon() { std::cout << "creating basic mouse icon\n"; }
};

class BasicWindowsBorder : public IWindowsBorder {
public:
	BasicWindowsBorder() { std::cout << "creating basic windows border\n"; }
};


#endif //TOOLKIT_CONCRETE_ITEMS_H
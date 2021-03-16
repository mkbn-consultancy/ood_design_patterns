#ifndef MAC_LIKE_TOOLKIT_H
#define MAC_LIKE_TOOLKIT_H

#include "toolkitItemsInterface.h"
#include <iostream>

class MacLikeScrollbar : public IScrollBar {
public:
	MacLikeScrollbar() { std::cout << "creating mac-like scrollbar\n"; }
};

class MacLikeMouseIcon : public IMouseIcon {
public:
	MacLikeMouseIcon() { std::cout << "creating mac-like mouse icon\n"; }
};

class MacLikeWindowsBorder : public IWindowsBorder {
public:
	MacLikeWindowsBorder() { std::cout << "creating mac-like windows border\n"; }
};


#endif //MAC_LIKE_TOOLKIT_H
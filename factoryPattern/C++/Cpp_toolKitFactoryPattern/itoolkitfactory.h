#ifndef FACTORY_PATTERN_H
#define FACTORY_PATTERN_H

//forward declarations
class IScrollBar;
class IMouseIcon;
class IWindowsBorder;

class IToolkitFactory {
public:
	virtual IScrollBar* createScrollBar() = 0;
	virtual IMouseIcon* createMouseIcon() = 0;
	virtual IWindowsBorder* createWindowsBorder() = 0;
	//...
};

#endif //FACTORY_PATTERN_H
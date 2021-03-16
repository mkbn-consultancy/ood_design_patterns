#ifndef TOOLKIT_CONCRETE_FACTORIES_H
#define TOOLKIT_CONCRETE_FACTORIES_H

#include "itoolkitfactory.h"
#include "regularTollkit.h"

class BasicToolkitFactory : public IToolkitFactory {
public:
	virtual IScrollBar* createScrollBar() { return new BasicScrollbar; }
	virtual IMouseIcon* createMouseIcon() { return new BasicMouseIcon; }
	virtual IWindowsBorder* createWindowsBorder() { return new BasicWindowsBorder; }
	//...
};
#endif // !TOOLKIT_CONCRETE_FACTORIES_H

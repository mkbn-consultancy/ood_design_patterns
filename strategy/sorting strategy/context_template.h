#ifndef __CONTEXTTEMPLATE_H__
#define __CONTEXTTEMPLATE_H__

#include "strategy.h"

#include <string>
#include <vector>
#include <memory>

#include <iostream> //for debugging

template<class SortFunc>
class ContextTemplate
{
public:
    ContextTemplate() = default;
    ~ContextTemplate() = default;
    void doSomeBusinessLogic() const
    {
        // ...
        SortFunc func;
        std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
        std::string result = func(std::vector<std::string>{"a", "e", "c", "b", "d"});
        std::cout << result << "\n";
        // ...
    }
};

#endif //__CONTEXTTEMPLATE_H__
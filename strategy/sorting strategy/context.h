#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "strategy.h"

#include <string>
#include <vector>
#include <memory>

#include <iostream> //for debugging

class Context
{
public:
    Context(IStrategy* strategy = nullptr) : _strategy(strategy)
    {
    }
    ~Context()
    {
    }
    void set_strategy(IStrategy* strategy)
    {
        _strategy.reset(strategy);
    }
    void doSomeBusinessLogic() const
    {
        // ...
        std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
        std::string result = _strategy->doAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
        std::cout << result << "\n";
        // ...
    }
private:
    std::shared_ptr<IStrategy> _strategy;
};

#endif //__CONTEXT_H__
#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <string>
#include <vector>

class IStrategy
{
public:
    virtual ~IStrategy() {}
    virtual std::string doAlgorithm(const std::vector<std::string> &data) const = 0;
};

#endif // __STRATEGY_H__
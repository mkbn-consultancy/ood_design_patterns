#ifndef __INCREASESORT_H__
#define __INCREASESORT_H__

#include "strategy.h"
#include <algorithm>

class IncreaseSort : public IStrategy
{
public:
    std::string doAlgorithm(const std::vector<std::string> &data) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));

        return result;
    }
};

#endif // __INCREASESORT_H__
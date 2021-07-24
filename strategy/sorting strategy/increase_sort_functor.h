#ifndef __INCREASESORTFUNCTOR_H__
#define __INCREASESORTFUNCTOR_H__

#include <algorithm>
#include <string>
#include <vector>

class IncreaseSortFunctor
{
public:
    std::string operator()(const std::vector<std::string> &data)
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));

        return result;
    }
};

#endif // __INCREASESORTFUNCTOR_H__
#ifndef __REVERSESORTFUNCTOR_H__
#define __REVERSESORTFUNCTOR_H__

#include <algorithm>
#include <string>
#include <vector>

class ReverseSortFunctor
{
public:
    std::string operator()(const std::vector<std::string> &data)
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter) {
            result += letter;
        });
        std::sort(std::begin(result), std::end(result));
        for (int i = 0; i < result.size() / 2; i++)
        {
            std::swap(result[i], result[result.size() - i - 1]);
        }

        return result;
    }
};

#endif //__REVERSESORTFUNCTOR_H__
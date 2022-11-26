#include <cstdint>
#include <iterator>
#include <list>

namespace mystd
{

using It = std::list<std::int32_t>::iterator;
using DifferenceType = It::difference_type;

void advance(It &it, DifferenceType n)
{
    while (n > 0)
    {
        ++it;
        --n;
    }

    while (n < 0)
    {
        --it;
        ++n;
    }
}

DifferenceType distance(It first, It last)
{
    DifferenceType result = 0;

    while (first != last)
    {
        ++first;
        ++result;
    }

    return result;
}

It next(It it, DifferenceType n = 1)
{
    mystd::advance(it, n);
    return it;
}

It prev(It it, DifferenceType n = -1)
{
    mystd::advance(it, n);
    return it;
}

} // namespace mystd

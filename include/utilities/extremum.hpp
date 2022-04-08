#ifndef EXTREMUM_CPP
#define EXTREMUM_CPP

#include <iterator>

namespace utilities {
template <typename FwdIter, typename Comparator>
FwdIter extremum(FwdIter begin, FwdIter end, Comparator comp) {
    if (begin == end) {
        return begin;
    }
    FwdIter result = begin;
    FwdIter iter = begin;
    ++iter;
    while (iter != end) {
        if (comp(*iter, *result)) {
            result = iter;
        }
        ++iter;
    }
    return result;
}

} // namespace utilities

#endif

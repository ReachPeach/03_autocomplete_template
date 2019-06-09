
#include "binary_search_deluxe.hpp"
#include "term.hpp"

int
binary_search_deluxe::first_index_of(std::vector<term> req, const term &key,
                                     const std::function<bool(const term &, const term &)> &comp) {

    std::vector<term>::iterator low;
    low = std::lower_bound(req.begin(), req.end(), key, comp);
    return low - req.begin();
}

int
binary_search_deluxe::last_index_of(std::vector<term> req, const term &key,
                                    const std::function<bool(const term &, const term &)> &comp) {

    std::vector<term>::iterator up;
    up = std::upper_bound(req.begin(), req.end(), key, comp);
    return up - req.begin();
}

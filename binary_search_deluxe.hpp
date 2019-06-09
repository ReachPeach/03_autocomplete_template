#pragma once

#include "term.hpp"

class binary_search_deluxe {
public:
    static int
    first_index_of(std::vector<term> req, const term &key,
                   const std::function<bool(const term &, const term &)> &comp);

    static int
    last_index_of(std::vector<term> req, const term &key,
                  const std::function<bool(const term &, const term &)> &comp);
};
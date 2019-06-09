#pragma once

#include "binary_search_deluxe.hpp"

class autocomplete {

    std::vector<term> terms;
public :
    std::vector<term> all_matches(const std::string &prefix) const;

    size_t number_of_matches(const std::string &prefix) const;

    explicit autocomplete(std::vector<term> list);
};
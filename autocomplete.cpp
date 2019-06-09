#include <utility>


#include "autocomplete.hpp"

autocomplete::autocomplete(std::vector<term> list) : terms(std::move(list)){;
    std::sort(this->terms.begin(), this->terms.end());
}

std::vector<term> autocomplete::all_matches(const std::string &prefix) const {
    term key(prefix, 0);
    auto first = binary_search_deluxe::first_index_of(terms, key, term::by_prefix_order(prefix.size()));
    auto second = binary_search_deluxe::last_index_of(terms, key, term::by_prefix_order(prefix.size()));
    std::vector<term> ans(terms.begin() + first, terms.begin() + second);
    std::sort(ans.begin(), ans.end(), term::by_reverse_weight_order());
    return ans;
}

size_t autocomplete::number_of_matches(const std::string &prefix) const {
    term key(prefix, 0);
    auto first = binary_search_deluxe::first_index_of(terms, key, term::by_prefix_order(prefix.size()));
    auto second = binary_search_deluxe::last_index_of(terms, key, term::by_prefix_order(prefix.size()));
    return second - first;
}


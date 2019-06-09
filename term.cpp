
#include <string>
#include <iostream>
#include <functional>


#include "term.hpp"

term::term() = default;

term::term(std::string name, size_t weight_) : word(std::move(name)), weight(weight_) {
}

term::term(const term &s) = default;

term::term(term &&other) noexcept : word(std::move(other.word)), weight(other.weight) {
}

term &term::operator=(const term &s) {
    if (this == &s) {
        return *this;
    }
    word = s.word;
    weight = s.weight;
    return *this;
}

term &term::operator=(term &&s) noexcept {
    if (this == &s) {
        return *this;
    }

    word = s.word;
    weight = s.weight;
    return *this;
}


bool term::operator<(const term &other) const {
    return this->word < other.word ? true : (this->word == other.word ? this->weight < other.weight : false);
}

bool term::operator>(const term &other) const {
    return this->word > other.word ? true : (this->word == other.word ? this->weight > other.weight : false);
}

bool term::operator<=(const term &other) const {
    return !(*this > other);
}

bool term::operator>=(const term &other) const {
    return !(*this < other);
}

bool term::operator==(const term &other) const {
    return this->word == other.word && this->weight == other.weight;
}

bool term::operator!=(const term &other) const {
    return !(*this == other);
}

std::string term::to_string() const {
    return std::to_string(this->weight) + " " + this->word;
}

std::ostream &operator<<(std::ostream &stream, const term &s) {
    stream << s.to_string();
    return stream;
}

std::function<bool(const term &, const term &)> term::by_reverse_weight_order() {
    return [](const term &s1, const term &s2) { return s1.weight > s2.weight; };
}

std::function<bool(const term &, const term &)> term::by_prefix_order(int r) {
    return [r](const term &s1, const term &s2) { return s1.word.substr(0, r) < s2.word.substr(0, r); };
}



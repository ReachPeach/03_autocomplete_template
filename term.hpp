#pragma once

#include <string>
#include <functional>
#include <iostream>

class term {
private:
    std::string word;
    size_t weight;
public:
    term();

    term(std::string name, size_t weight_);

    term(const term &other);

    term(term &&other) noexcept;


    term &operator=(const term &other);

    term &operator=(term &&other) noexcept;

    bool operator<(const term &other) const;

    bool operator<=(const term &other) const;

    bool operator>(const term &other) const;

    bool operator>=(const term &other) const;

    bool operator==(const term &other) const;

    bool operator!=(const term &other) const;

    std::string to_string() const;

    friend std::ostream &operator<<(std::ostream &stream, const term &s);

    static std::function<bool(const term &, const term &)> by_reverse_weight_order();

    static std::function<bool(const term &, const term &)> by_prefix_order(int r) ;

};

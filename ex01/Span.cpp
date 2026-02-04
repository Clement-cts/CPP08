#include "Span.hpp"

Span::Span() : _N(0), _v() {}

Span::Span(unsigned int N) : _N(N), _v() {
    _v.reserve(N);
}

Span::Span(const Span& other) : _N(other._N), _v(other._v) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _v = other._v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int x) {
    if (_v.size() >= _N)
        throw std::runtime_error("Span: capacity exceeded");
    _v.push_back(x);
}

int Span::longestSpan() const {
    if (_v.size() < 2)
        throw std::runtime_error("Span: not enough elements");
    std::vector<int>::const_iterator mn =
        std::min_element(_v.begin(), _v.end());
    std::vector<int>::const_iterator mx =
        std::max_element(_v.begin(), _v.end());
    
    return *mx - *mn;
}
 
int Span::shortestSpan() const {
    if (_v.size() < 2)
        throw std::runtime_error("Span: not enough elements");
    
    std::vector<int> tmp(_v);
    std::sort(tmp.begin(), tmp.end());

    int best = std::numeric_limits<int>::max();
    for (std::vector<int>::size_type i = 1; i < tmp.size(); ++i) {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < best)
            best = diff;
    }
    return best;
}
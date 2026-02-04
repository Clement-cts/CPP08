#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>
# include <iostream>
# include <ctime>
# include <cstdlib>

class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int x);

        template <typename It>
        void addRange(It first, It last) {
            std::vector<int> tmp;
            for (It it = first; it != last; ++it)
                tmp.push_back(*it);
            if (_v.size() + tmp.size() > _N)
                throw std::runtime_error("Span: capacity exceeded");
            _v.insert(_v.end(), tmp.begin(), tmp.end());
        }
        int shortestSpan() const;
        int longestSpan() const;

    private:
        unsigned int _N;
        std::vector<int> _v;
};

#endif
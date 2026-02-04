#include "Span.hpp"

/*int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
        try {
            sp.addNumber(42);
        } catch (const std::exception& e) {
            std::cout << "'Excepted exception: " << e.what() << std::endl;
        }
        Span big(10000);
        std::vector<int> v;
        srand(time(NULL));
        for (int i = 0; i < 10000; ++i)
            v.push_back(rand());
        big.addRange(v.begin(), v.end());

        std::cout << "big shortestSpan: " << big.shortestSpan() << std::endl;
        std::cout << "big longestSpan: " << big.longestSpan() << std::endl;

        Span tiny(10);
        tiny.addNumber(1);
        try {
            std::cout << tiny.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }   
    } catch (const std::exception& e) {
        std::cerr << "Fatal: " << e.what() << std::endl;
    }
}*/

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
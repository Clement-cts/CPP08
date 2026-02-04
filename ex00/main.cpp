#include "easyfind.hpp"

void printTitle(const std::string& title) {
    std::cout << "\n===== " << title << " =====" << std::endl;
}

template <typename T>
void fillContainer(T& c, int start, int step, int count) {
    for (int i = 0; i < count; i++)
        c.insert(c.end(), start + i * step);
}

int main() {
    srand(time(NULL));

    //Vector
    printTitle("VECTOR");
    std::vector<int> v;
    fillContainer(v, 0, 3, 10);
    try {
        std::cout << "Searching 9... ";
        std::cout << *easyfind(v, 9) << std::endl;

        std::cout << "Searching 42... ";
        std::cout << *easyfind(v, 42) << std::endl; //exception not found
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //List
    printTitle("LIST");
    std::list<int> l;
    fillContainer(l, 5, 5, 6);
    try {
        std::cout << "Searching 15... ";
        std::cout << *easyfind(l, 15) << std::endl;

        std::cout << "Searching 14... ";
        std::cout << *easyfind(l, 14) << std::endl; // Exception not found
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //deque
    printTitle("DEQUE");
    std::vector<int> d;
    fillContainer(d, -10, 2, 12);
    try {
        std::cout << "Searching -6... ";
        std::cout << *easyfind(d, -6) << std::endl;

        std::cout << "Searching 999... ";
        std::cout << *easyfind(d, 999) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //const test
    printTitle("CONST CONTAINER");
    const std::vector<int> cv(v);
    try {
        std::cout << "Searching 6 in const vector... ";
        std::cout << *easyfind(cv, 6) << std::endl;

        std::cout << "Searching 100 in const vector... ";
        std::cout << *easyfind(cv, 100) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nAll tests done." << std::endl;
    return 0;
}
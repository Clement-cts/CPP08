# include "MutantStack.hpp"
# include <stack>

#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

static void testSubjectLike() {
    std::cout << "=== Subject test (MutantStack) ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    (void)s;
}

static void testListSameOutput() {
    std::cout << "\n=== Same logic with std::list ===" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

static void testConstAndReverse()
{
    std::cout << "\n=== Const + reverse iterators ===" << std::endl;

    MutantStack<int> m;
    m.push(1);
    m.push(2);
    m.push(3);

    const MutantStack<int> cm(m);
    for (MutantStack<int>::const_iterator it = cm.cbegin(); it != cm.cend(); ++it)
        std::cout << *it << std::endl;

    std::cout << "--- reverse ---" << std::endl;
    for (MutantStack<int>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
        std::cout << *it << std::endl;
}

int main()
{
    testSubjectLike();
    testListSameOutput();
    testConstAndReverse();
    return 0;
}
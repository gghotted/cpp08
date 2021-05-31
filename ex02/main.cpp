#include <iostream>
#include "mutantstack.hpp"

void testIterator(MutantStack<int>& mstack)
{
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  for (; it != ite; it++)
    std::cout << *it << '\n';
}

void testReverseIterator(MutantStack<int>& mstack)
{
  MutantStack<int>::reverse_iterator it = mstack.rbegin();
  MutantStack<int>::reverse_iterator ite = mstack.rend();
  for (; it != ite; it++)
    std::cout << *it << '\n';
}

void testConstIterator(const MutantStack<int>& mstack)
{
  MutantStack<int>::const_iterator cit = mstack.begin();
  MutantStack<int>::const_iterator cite = mstack.end();
  // *cit = 42 // error : because cit is const_iterator;
  for (; cit != cite; cit++)
    std::cout << *cit << '\n';
}

int main(int argc, char** argv)
{
  if (argc != 2)
    return 1;

	MutantStack<int> mstack;
  for (int i = 0; i < 10; i++)
    mstack.push(i);

  int testCase = argv[1][0] - '0';
  if (testCase == 0) testIterator(mstack);
  if (testCase == 1) testReverseIterator(mstack);
  if (testCase == 2) testConstIterator(mstack);
	return (0);
}

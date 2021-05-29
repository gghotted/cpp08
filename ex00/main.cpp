#include <vector>
#include <set>
#include <iostream>
#include "easyfind.hpp"

void testNotFound()
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  std::vector<int>::iterator vi = easyfind(v, 3);
  if (vi != v.end())
    std::cout << *vi << '\n';
  else
    std::cout << "no such\n";
}

void testFound()
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  std::vector<int>::iterator vi = easyfind(v, 2);
  if (vi != v.end())
    std::cout << *vi << '\n';
  else
    std::cout << "no such\n";
}

void testSet()
{
  std::set<int> s;

  s.insert(1);
  s.insert(2);
  std::set<int>::iterator si = easyfind(s, 3);
  if (si != s.end())
    std::cout << *si << '\n';
  else
    std::cout << "no such\n";

  si = easyfind(s, 1);
  if (si != s.end())
    std::cout << *si << '\n';
  else
    std::cout << "no such\n";
}

int main(int argc, char** argv)
{
  if (argc != 2)
    return 1;

  int testCase = argv[1][0] - '0';
  if (testCase == 0) testNotFound();
  if (testCase == 1) testFound();
  if (testCase == 2) testSet();
}

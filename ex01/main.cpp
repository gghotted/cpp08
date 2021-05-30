#include <iostream>
#include <vector>
#include "span.hpp"

void testNormal()
{
  Span span(5);

  span.addNumber(6);
  span.addNumber(100);
  span.addNumber(5);
  span.addNumber(100);
  span.addNumber(1);

  std::cout << span.longestSpan() << '\n';
  std::cout << span.shortestSpan() << '\n';
}

void testAddNumberByIterator()
{
  srand(time(0));
  std::vector<int> v;
  for (int i = 0; i < 5; i++)
  {
    v.push_back(rand() % 100);
    std::cout << v.back() << ' ';
  }
  std::cout << '\n';

  Span span(5);
  span.addNumber(v.begin(), v.end());
  std::cout << "longest: " << span.longestSpan() << '\n';
  std::cout << "shortest: " << span.shortestSpan() << '\n';
}

void testSizeOverflow()
{
  Span span(1);

  try
  {
    span.addNumber(1);
    span.addNumber(2);
  }
  catch(const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
}

void testNotEnoughSize()
{
  Span span(2);

  try
  {
    span.longestSpan();
  }
  catch(const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }

  span.addNumber(42);
  try
  {
    span.longestSpan();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

void testAssignation()
{
  Span span(5);

  span.addNumber(6);
  span.addNumber(100);
  span.addNumber(5);
  span.addNumber(100);
  span.addNumber(1);

  Span span2(2);
  span2.addNumber(1);
  span2.addNumber(2);
  span2 = span;
  std::cout << span2.longestSpan() << '\n';
  std::cout << span2.shortestSpan() << '\n';
}

int main(int argc, char** argv)
{
  if (argc != 2)
    return 1;

  int testCase = argv[1][0] - '0';
  if (testCase == 0) testNormal();
  if (testCase == 1) testAddNumberByIterator();
  if (testCase == 2) testSizeOverflow();
  if (testCase == 3) testNotEnoughSize();
  if (testCase == 4) testAssignation();
}

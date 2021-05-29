#include <iostream>
#include "span.hpp"

int main()
{
  Span span(5);

  span.addNumber(1);
  span.addNumber(5);
  span.addNumber(6);
  span.addNumber(100);
  span.addNumber(100);

  std::cout << span.longestSpan() << '\n';
  std::cout << span.shortestSpan() << '\n';
}

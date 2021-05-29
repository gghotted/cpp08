#include "span.hpp"

Span::Span(unsigned int n) : maxSize(n)
{
}

Span::Span(const Span& span)
{
  *this = span;
}

Span::~Span()
{
}

Span& Span::operator = (const Span& span)
{
  maxSize = span.maxSize;
  numbers = span.numbers;
  return *this;
}

void Span::addNumber(int n)
{
  if (numbers.size() == maxSize)
    throw std::out_of_range("already full");
  numbers.insert(n);
}

Span::Span()
{
}

int Span::shortestSpan()
{
  if (numbers.size() < 2)
    throw std::out_of_range("required minimum size is 2");
  std::set<int> diffs;
  myTransform(
      numbers.begin(), --numbers.end(),
      ++numbers.begin(), std::inserter(diffs, diffs.begin()),
      diff);
  return *diffs.begin();
}

int Span::longestSpan()
{
  if (numbers.size() < 2)
    throw std::out_of_range("required minimum size is 2");
  return *--numbers.end() - *numbers.begin();
}

int Span::diff(int a, int b)
{
  return (std::abs(a - b));
}

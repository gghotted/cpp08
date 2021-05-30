#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>
#include <set>

class Span
{
 public:
  Span(unsigned int n);
  Span(const Span& span);
  virtual ~Span();

  Span& operator = (const Span& span);

  void addNumber(int n);

  template<typename Iter>
  void addNumber(Iter _begin, Iter end)
  {
    for (Iter begin = _begin; begin != end; begin++)
      addNumber(*begin);
  }

  int shortestSpan();
  int longestSpan();

 private:
  Span();
  static int diff(int a, int b);

  template<typename InputIt, typename OutputIt, typename Fnc>
  static void myTransform(
      InputIt _begin, InputIt end,
      InputIt begin2, OutputIt output, Fnc fnc)
  {
    for (InputIt begin = _begin; begin != end; begin++, begin2++, output++)
      *output = fnc(*begin, *begin2);
  }

  std::multiset<int> numbers;
  unsigned int maxSize;
};

#endif

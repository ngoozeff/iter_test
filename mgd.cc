#include <vector>
#include <functional>

extern int apply(
    std::function<int(std::vector<int>::const_iterator, std::vector<int>::const_iterator)> f,
    std::vector<int>::const_iterator b,
    std::vector<int>::const_iterator e
    );

int sum(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e)
{
  int s = 0;
  for (auto it = b; it != e; ++it)
    s += *it;

  return s;
}

int foo(
    std::vector<int>::const_iterator b,
    std::vector<int>::const_iterator e
    )
{
  using namespace std::placeholders;

  printf("[foo] %d\n", _ITERATOR_DEBUG_LEVEL);

  std::function<int(std::vector<int>::const_iterator, std::vector<int>::const_iterator)> f
    = std::bind(sum, _1, _2);

  printf("[foo] %d\n", sizeof(f));

  return apply(f, b, e);
}


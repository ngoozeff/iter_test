#include <cstdio>
#include <vector>
#include <functional>

extern int sum(std::vector<int>::const_iterator, std::vector<int>::const_iterator);

int apply(
    std::function<int(std::vector<int>::const_iterator, std::vector<int>::const_iterator)> f,
    std::vector<int>::const_iterator b,
    std::vector<int>::const_iterator e
    )
{
  return f(b, e);
}

extern int foo(
    std::vector<int>::const_iterator b,
    std::vector<int>::const_iterator e
    );

int bar(
    std::vector<int>::const_iterator b,
    std::vector<int>::const_iterator e
    )
{
  using namespace std::placeholders;

  printf("[bar] %d\n", _ITERATOR_DEBUG_LEVEL);

  std::function<int(std::vector<int>::const_iterator, std::vector<int>::const_iterator)> f
    = std::bind(sum, _1, _2);

  printf("[bar] %d\n", sizeof(f));

  return apply(f, b, e);
}

int main()
{
  using namespace std::placeholders;

  std::vector<int> v {1,2,3};
  int s = sum(cbegin(v), cend(v));

  printf("%d\n", s);

  s=0;

  std::function<int(std::vector<int>::const_iterator, std::vector<int>::const_iterator)> f
    = std::bind(sum, _1, _2);

  s = f( v.begin(), v.end() );

  printf("%d %d\n", s, _ITERATOR_DEBUG_LEVEL);

  s = 0;
  s = apply(f, cbegin(v), cend(v));

  printf("%d\n", s);

  s = 0;
  s = bar(cbegin(v), cend(v));

  printf("%d\n", s);

  s = 0;
  s = foo(cbegin(v), cend(v));

  printf("%d\n", s);

  return 0;
}


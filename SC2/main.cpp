#include <iostream>

void sort(int *array, bool reversed);

int main()
{
  int a[10]{0};

  for (int i = 0; i < 10; ++i)
  {
    std::cin >> a[i];
  }

  int reverse = 0;
  std::cin >> reverse;

  sort(a, reverse);

  for (int i = 0; i < 10; ++i)
  {
    std::cout << a[i] << ' ';
  }
}

void sort(int *array, bool reversed)
{
  for (int i = 0; i < 10; ++i)
  {
    for (int j = i + 1; j < 10; ++j)
    {
      if (!reversed)
      {
        if (array[i] > array[j])
        {
          int tmp = array[i];
          array[i] = array[j];
          array[j] = tmp;
        }
      }
      else
      {
        if (array[i] < array[j])
        {
          int tmp = array[i];
          array[i] = array[j];
          array[j] = tmp;
        }
      }
    }
  }
}

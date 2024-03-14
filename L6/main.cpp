#include <iostream>
#include <string>

typedef unsigned long int myint;     // Вводим новое название типа

enum Color
{
  Red,
  Green,
  Blue
};     // Объявляем перечисляемый тип

struct showColor
{
  Color clr;     // Объявляем поле структуры

  std::string getName()
  {     // Объявляем метод структуры
    switch (clr)
    {
    case Red:
      return "Red";
    case Blue:
      return "Blue";
    case Green:
      return "Green";
    }
  }

  void show()
  {     // Объявляем метод структуры
    std::cout << getName() << std::endl;
  }
};

void staticColor()
{
  std::cout << "Static variables:" << std::endl;
  showColor a, b, c;

  a.clr = Red;       // Задаём значение полю clr переменной a
  b.clr = Green;     // Задаём значение полю clr переменной b
  c.clr = Blue;      // Задаём значение полю clr переменной c
  a.show();          // Вызываем метод show переменной a
  b.show();          // Вызываем метод show переменной b
  c.show();          // Вызываем метод show переменной c
  std::cout << std::endl;
}

void dynamicColor()
{
  std::cout << "Dynamic variables:" << std::endl;
  showColor *a;     // Объявляем указатель
  myint b;

  std::cout << "Input array size: ";
  std::cin >> b;     // Получаем число элементов массива

  a = new showColor[b];     // Выделяем память под массив

  for (myint i = 0; i < b; i++)
  {
    int r = (rand() % 3);     // Получаем случайное число от 0 до 2
    a[i].clr = (Color)r;      // Преобразуем число r в тип Color
    std::cout << "r = " << r << "; a[" << i << "].clr = " << a[i].clr << "; a[" << i
              << "].getName() = " << a[i].getName() << std::endl;
  }

  delete[] a;     // Освобождаем память
}

int main()
{
  staticColor();
  dynamicColor();
  system("pause");
  return 0;
}

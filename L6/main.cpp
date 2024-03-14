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
    default:                    ///< 1. Создаем секцию default
      return "Color unset";     ///<
    }
  }

  void show()
  {     // Объявляем метод структуры
    std::cout << getName() << std::endl;
  }
};

struct dynArr           ///< 3. Создаем структуру dynArr
{                       ///<
  showColor *array;     ///< Указатель на динамический массив
  const myint size;     ///< Храним размер массива

  dynArr(const myint size):              ///< Конструктор получающий в качестве
    size(size)                           ///< параметра размер массива
  {                                      ///<
    array = new showColor[size];         ///< Выделение памяти под массив
    for (myint i = 0; i < size; i++)     ///< Заполнение массива случайными
    {                                    ///< значениями в цикле
      int r = (rand() % 3);              ///<
      array[i].clr = (Color)r;           ///<
    }                                    ///<
  }                                      ///<

  ~dynArr()             ///< Деструктор вызываемый при завершении
  {                     ///< программы или при вызове оператора delete
    delete[] array;     ///<
  }                     ///<

  void print()                           ///< Метод вывода массива
  {                                      ///< в поток cout
    for (myint i = 0; i < size; i++)     ///<
    {                                    ///<
      std::cout << "array[" << i << "].clr = " << array[i].clr << "; array[" << i     ///<
                << "].getName() = " << array[i].getName() << std::endl;               ///<
    }                                                                                 ///<
  }                                                                                   ///<
};                                                                                    ///<

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

  std::cout << "==========\n";         ///< 2. Выведем массив после выделения памяти
  for (myint i = 0; i < b; i++)        ///< Пройдемся в цикле от 0 до b (размера цикла)
  {                                    ///<
    std::cout << a[i].clr << '\n';     ///< Выведем в консоль значения clr каждого
  }                                    ///< элемента
  std::cout << "==========\n";         ///<

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

  dynArr a{8};     ///< Иницилизация переменной a типа dynArr
  a.print();       ///< Вывод всех значений
  system("pause");
  return 0;
}

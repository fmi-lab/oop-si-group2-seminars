# Седмица 3: Шаблонни функции. Функции от по-висок ред.
*07.03.2017*

## План

* [Шаблонни функции](#Шаблонни-функции)
* [Функции от по-висок ред](#Функции-от-по---висок-ред)
* [Задачи](#Задачи)

## Шаблонни-функции

Шаблоните се използват при еднакви по функционалност, но различими по тип, който
приемат или връщат, функции.

*Пример:*
```cpp
void printArray (int* array, size_t size) {
    std::cout << "{";

    if (size > 0) {
        for (size_t i = 0; i < size - 1; i++) {
            std::cout << " " << array[i] << ",";
        }

        std::cout << " " << array[size - 1] << " ";
    }

    std::cout << "}";
}
```

Подобна функция, тъй като приема масив от int, ще трябва да бъде пренаписана за
който и да е масив от тип различен от int. Това би могло да се избегне чрез
използването на template-и.

*Пример:*
```cpp
template <typename T>
void printArray (T* array, size_t size) {
    std::cout << "{";

    if (size > 0) {
        for (size_t i = 0; i < size - 1; i++) {
            std::cout << " " << array[i] << ",";
        }

        std::cout << " " << array[size - 1] << " ";
    }

    std::cout << "}";
}
```

Компилаторът ще изгенерира автоматично частните (типизираните) случаи (само
тези, които са необходими) на шаблонната функция, т.е. освобождаваме се от това
ръчно да копираме функции и поддържаме по-чист код. И така сега, ако искам да
изпечатам масиви от различни типове, то мога просто да използвам шаблонната
функция.

*Пример:*
```cpp
#include <iostream>

...

int main() {

    int intArray[] = { 1, 2, 5, 10 };
    double doubleArray[] = { 2.5, -9.3 };
    char charArray[] = "Rick";
    char* stringArray[] = { "Wubba", "lubba", "dub", "dub" };

    printArray(intArray, sizeof(intArray) / sizeof(int));
    printArray(doubleArray, sizeof(doubleArray) / sizeof(double));
    printArray(charArray, sizeof(charArray) / sizeof(char));
    printArray(stringArray, sizeof(stringArray) / sizeof(char*));

    return 0;
}
```

С една функция можете да изведете на екрана съдържанието на най-различни по тип
масиви. В масива от символи дори ще бъде изведена и терминиращата нула (ще се
вижда като празен символ).

Добре е да се придържате към принципа [DRY (Don't Repeat
Yourself)](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself) и използването
на template-и би ви било от ползва за това.

Стандартна конвенция е имената представящи шаблонният тип да бъдат единствена
главна буква (в случая T, но може и друга). Идеята е бързо да се отличава като
шаблонен тип. Иначе може да напишете на мястото на T каквото искате като име на
тип стига да не е вече съществуващо име тип и да е валидно според синтаксиса на
C++ име, но по-добре се придържайте към конвенцията.

Освен `template <typename T>` може да срещнете и `template <class T>`, в
повечето случаи те са взаимозаменяеми. По исторически причини съществува
`template <class T>`, тъй като [Bjarne
Stroustrup](https://en.wikipedia.org/wiki/Bjarne_Stroustrup) (създателя на C++)
в началото просто не е искал да включва нова ключова дума и всъщност по-късно
след като C++ станал по-широко използван език,
[ISO](https://en.wikipedia.org/wiki/ISO) комитет определил, новата ключова дума
`typename` за по-ясна, тъй като по този начин се избягва и понякога объркващото
за начинаещи overload-ване на `class`. Принципно `template` има малко
по-разширена функция, а за обратна съвместимост все пак е запазено значението на
`template <class T>`.

Ще използваме за шаблони `template <typename T>`.

## Функции от по-висок ред

## Задачи
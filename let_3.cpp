#include <iostream>
#include <cmath>
long long int h2d(const char *str) {
    int count = 0;
    if (str == nullptr || *str == '\0') { exit(-1); }   // Проверка строки: если строка пустая, то прога прервется
    bool is_negative = (str[0] == '-');                      // Проверка на отрицательное число.
    if (*str == '+' || *str == '-') {
        ++str;
    }              // Сдвиг на след символ, если уд усл
    if (*str == '0' && *(++str) == 'x') {
        ++str;
    }          // Сдвиг на след символ, если уд усл
    else { exit(-1); }
    if (*str == '\0') { exit(-1); }                     // Если строка состояла только из "-0x" или "+0x", то exit(-1)
    long long int result = 0;
    while (*str != '\0') { ++str; }     // инвертируем массив (обратный порядок), если без cmath, то не надо
    --str;
    while (*str != 'x') {    // алгоритм преобразования (более наглядный)
        if (*str >= '0' && *str <= '9') {
            result = result + (*str - '0') * pow(16, count);
        } else {
            if (*str >= 'A' && *str <= 'F') {
                result = result + (*str - 'A' + 10) * pow(16, count);
            } else {
                if (*str >= 'a' && *str <= 'f') {
                    result = result + (*str - 'a' + 10) * pow(16, count);
                } else {
                    exit(-1);
                }

            }
        }
        ++count;
        --str;
    }
    return (is_negative) ? result * -1 : result;

}
// без cmath
/*
 * while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result*16 + (*str - '0');
        } else {
            if (*str >= 'A' && *str <= 'F') {
                result = result*16 + (*str - 'A' + 10);
            } else {
                if (*str >= 'a' && *str <= 'f') {
                    result = result*16 + (*str - 'a' + 10);
                } else {
                    exit(-1);
                }

            }
        }

        ++str;
    }
 */
 int main(int argc, char** argv) {
     for (int count{ 1 }; count < argc; ++count)
    {
        std::cout << h2d(argv[argc-count])+114 << '\n';
    }
}

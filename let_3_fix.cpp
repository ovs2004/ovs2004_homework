#include <iostream> //Овсяников АА, исправленный вариант

int64_t hex2int(const char *str) {
    if (str == nullptr || *str == '\0') { exit(-1); }
    bool is_negative = (str[0] == '-');
    if (*str == '+' || *str == '-') { ++str; }
    if (*str == '0' && *(++str) == 'x') { ++str; }
    else { exit(-1); }
    if (*str == '\0') { exit(-1); }
    int64_t result=0;
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 16 + (*str - '0');
        } else if (*str >= 'A' && *str <= 'F') {
            result = result * 16 + (*str - 'A' + 10);
        } else if (*str >= 'a' && *str <= 'f'){
            result = result * 16 + (*str - 'a' + 10);
        } else {
            exit(-1);
        }
        ++str;
    }

    return (is_negative) ? result * -1 : result;
}

int main(int argc, char** argv) {
    for (int count=argc-1; count>0; --count) {
        std::cout << hex2int(argv[count]) + 114 << '\n';
    }
}

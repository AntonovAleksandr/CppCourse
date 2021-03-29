#include <iostream>
#include <complex>
//Antonov Aleksandr Aleksandrovich
//1) atoi


int my_atoi(char* str);
int to_int(char ch);

int main() {
    char str [265];
    my_atoi(nullptr);
    while(str[0]!='E') {
        std::cout << "Enter number or E to exit: ";
        std::cin >> str;
        std::cout << "Your number is: " << my_atoi(str) << std::endl;
        std::cout << "Atoi number: " << atoi(str) << std::endl;
    }
    return 0;
}

int to_int(char ch){
    if(isdigit(ch)){
        return int(ch - '0');
    }
}

int my_atoi(char *str ){
    if(str == nullptr) return 0;

    char *pointer = str;
    char ch;
    int result = 0, sign = 1;

    while (*pointer){
        ch = (*pointer++);
        if(isdigit(ch))
        {
            result*= 10;
            result += to_int(ch);
        } else if (ch == '-' && result == 0) {
            sign *= -1;
        } else if (ch == '+' && result == 0) {
            sign *= 1;
        } else {
            break;
        }
    }
    return result * sign;
}



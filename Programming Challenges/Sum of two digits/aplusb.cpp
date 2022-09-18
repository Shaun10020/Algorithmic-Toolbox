#include <iostream>

int sum_of_digits(int first_digit,int second_digit){
    return first_digit+second_digit;
}

int main(){
    int first_digit;
    int second_digit;
    std::cin >> first_digit;
    std::cin >> second_digit;
    std::cout << sum_of_digits(first_digit,second_digit) << "\n";
    return 0;
}

#include <iostream>

int last_digit_of_fibonacci_number(int n){
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }
    return current;
}

int main(){
    int n;
    std::cin >>n;
    std::cout<<last_digit_of_fibonacci_number(n)<<'\n';

    return 0;
}
#include <iostream>

int fibonacci_fast(int n){
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current;
}

int main(){
    int n;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
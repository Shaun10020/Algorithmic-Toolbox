#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }
    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<long long>& numbers){
    int max_product=0;
    int n=numbers.size();

    int index1=0;
    int index2=1;
    for(int first=0;first<n;first++){
        if (numbers[index1]<numbers[first]){
            index1=first;
        }}
    if(index1==index2){
        index2=0;
    }
    for(int first=0;first<n;first++){
        if (index1!=first&&numbers[index2]<numbers[first]){
            index2=first;
        }
    }
    return numbers[index1]*numbers[index2];
    }

int main() {

    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }


    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}

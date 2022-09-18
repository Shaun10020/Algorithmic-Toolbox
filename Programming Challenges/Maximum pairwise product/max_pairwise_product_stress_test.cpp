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

int MaxPairwiseProductFast(const std::vector<int>& numbers){
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
    //std::cout<<index1<<" "<<index2<<"\n";
    return numbers[index1]*numbers[index2];
    }

int main() {
    /*
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    */
   while (true){
   int n=rand()%1000+2;
   std::vector<int> numbers(n);
   for (int i=0;i<n;i++){
       numbers[i]=rand()%100000000;
   }

    //std::cout << MaxPairwiseProduct(numbers) << "\n";
    int result1=MaxPairwiseProduct(numbers);
    int result2=MaxPairwiseProductFast(numbers);
    if(result1==result2){
        std::cout<<"OK" << "\n";
   }else{
       std::cout<<"Wrong Answer"<<"\n";
       for(int i=0;i<n;i++){
           std::cout<<numbers[i]<<" ";
       }
       std::cout<<"\n";
       std::cout<<result1<<" "<<result2<<"\n";
       while(true){}
   }
   }
    return 0;
}

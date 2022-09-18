#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> a(n+1,0);
  a[0]=0;
  a[1]=1;
  for (int i=0;i<n+1;i++){
    if(i%3==0){
      if(i%2==0){
        if(a[i/3]<a[i/2]){
          a[i]=a[i/3]+1;
        }
        else if(a[i/2]<a[i-1]){
          a[i]=a[i/2]+1;
        }
        else{
          a[i]=a[i-1]+1;
        }
      }
      else{
        if(a[i/3]<a[i-1]){
          a[i]=a[i/3]+1;
        }
        else{
          a[i]=a[i-1]+1;
        }
      }
    }
    else{
      if(i%2==0){
        if(a[i/2]<a[i-1]){
          a[i]=a[i/2]+1;
        }
        else{
          a[i]=a[i-1]+1;
        }
      }
      else{
          a[i]=a[i-1]+1;
      }
    }
  }
  while(n>=1){
    sequence.push_back(n);
    if(n%3==0&&a[n]-1==a[n/3]){
      n=n/3;
    }else if(n%2==0&&a[n]-1==a[n/2]){
      n=n/2;
    }else{
      n=n-1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

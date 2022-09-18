#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int l, int r,int *m,int*n) {
  int x = a[l];
  *m = l;
  *n=l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      *n=*n+1;
      //std::cout<<"2. Swaping from "<<*n<<"("<<a[*n]<<")"<<" to "<<i<<"("<<a[i]<<")"<<'\n';
      swap(a[i], a[*n]);
      if(a[*n]<x){
      *m=*m+1;
      //std::cout<<"3. Swaping from "<<*n<<"("<<a[*n]<<")"<<" to "<<*m<<"("<<a[*m]<<")"<<'\n';
      swap(a[*n], a[*m]);}
    }
  }
  //std::cout<<"4. Swaping from "<<*m<<"("<<a[*m]<<")"<<" to "<<l<<"("<<a[l]<<")"<<'\n';
  swap(a[l], a[*m]);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //std::cout<<"Partitioning from "<<l<<" to "<<r<<'\n';
  //std::cout<<"Partition pivot is "<<a[k]<<'\n';
  //std::cout<<"1. Swaping from "<<k<<"("<<a[k]<<")"<<" to "<<l<<"("<<a[l]<<")"<<'\n';
  swap(a[l], a[k]);
  int m=0;
  int n=0;
  partition3(a, l, r,&m,&n);
  //std::cout<<"Partition result :"<<'\n';
  //for (size_t i = 0; i < a.size(); ++i) {
  //  std::cout << a[i] << ' ';
  //}
  //std::cout<<'\n';
  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, n + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

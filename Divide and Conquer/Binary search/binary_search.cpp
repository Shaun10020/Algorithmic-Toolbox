#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1; 
  if (a[left]==x){
    return left;
  }
  if (a[right]==x){
    return right;
  }
  if (x>a[right] || x<a[left]){
    return -1;
  }
  while (a[left]<=x && x<=a[right]){
    int tem=((right-left)/2)+left;
    if(x==a[tem]){
      return tem;
    }
    else if(x>a[tem]){
      left=tem;
    }
    else{
      right=tem;
    }
    if(right-left<=1){
      if (a[left]==x){
        return left;
      }
      if (a[right]==x){
        return right;
      }
      return -1;
    }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
  return 0;
}

#include <iostream>

int get_change(int m) {
    int n;
  while(m>=10){
      m-=10;
      n++;
  }
  while(m>=5){
      m-=5;
      n++;
  }
  while(m>=1){
      m-=1;
      n++;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
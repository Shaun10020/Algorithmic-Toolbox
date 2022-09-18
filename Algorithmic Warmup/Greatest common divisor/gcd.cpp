#include <iostream>

long long gcd_fast(int a, int b) {
  if(b>a){
      a,b=b,a;
  }
  if(b>0){
      return gcd_fast(b,a%b);
  }
  else{
      return a;
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}

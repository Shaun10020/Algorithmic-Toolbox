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

long long lcm_fast(long long a, long long b) {
  long long lcm=(a*b)/gcd_fast(a,b);
  return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

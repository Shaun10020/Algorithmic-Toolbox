#include <iostream>
#include <vector>
#include <limits>

int get_change(int m) {
  std::vector<int> a(m,std::numeric_limits<int>::max());
  if(m==0){return 0;}
  for(int i=0;i<a.size();i++){
    if(i==0||i==2||i==3){
      a[i]=1;
    }
    else if(i>=4){
      if(a[i-4]<a[i-3]){
        a[i]=a[i-4]+1;
      }
      else if(a[i-3]<a[i-1]){
        a[i]=a[i-3]+1;
      }
      else{
        a[i]=a[i-1]+1;
      }
    }else if(i>=3){
      if(a[i-3]<a[i-1]){
        a[i]=a[i-3]+1;
      }
      else{
        a[i]=a[i-1]+1;
      }
    }
    else{
      a[i]=a[i-1]+1;
    }
  }
  return a[m-1];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

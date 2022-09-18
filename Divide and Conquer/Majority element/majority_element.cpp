#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int ave = left+(right-left)/2;
  int left_major=get_majority_element(a,left,ave);
  int right_major=get_majority_element(a,ave,right);
  if (left_major==-1 && right_major==-1){
    return -1;
  }
  else if(left_major!=right_major){
    int count=0;
    int element=a[left];
    for (int i=left;i<right;i++){
      if (element==a[i]){
        count++;
      }
      else{
        if(count>0){
          count--;
        }
        else{
          element=a[i];
          count++;
        }
      }
    }
    if(count>0){
      count=0;
      for (int i=left;i<right;i++){
        if (element==a[i]){
          count++;
        }
      }
      if(count>(right-left)/2){
      //std::cout<<"1.From "<<left<<" to "<<right-1<<" : "<<element<<'\n';
        return element;
      }
      else{
        //std::cout<<"2.From "<<left<<" to "<<right-1<<" : "<<-1<<'\n';
        return -1;
        }
    }
    else{
      //std::cout<<"3.From "<<left<<" to "<<right-1<<" : "<<-1<<'\n';
      return -1;
    }
  }
  else{
    //std::cout<<"4.From "<<left<<" to "<<right-1<<" : "<<left_major<<'\n';
    return left_major;
  }
  //std::cout<<"5.From "<<left<<" to "<<right<<" : "<<-1<<'\n';
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

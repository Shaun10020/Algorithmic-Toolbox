#include <iostream>
#include <string>
#include <vector>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  std::vector<std::vector<int>> a;
  for(int i=0;i<str1.size()+1;i++){
    std::vector<int> b(str2.size()+1,0);
    if(i==0){
      for(int j=0;j<b.size();j++){
        b[j]=j;
      }
    }
    else{
      b[0]=i;
    }
    a.push_back(b);
  }
  for(int i=0;i<a.size();i++){
    for(int j=0;j<a[i].size();j++){
      if(i==0&&j==0){continue;}
      if(a[i][j]==0){
      int var1=a[i][j-1]+1;
      int var2=a[i-1][j]+1;
      int var3=a[i-1][j-1];
      if(str1[i-1]!=str2[j-1]){
        var3=var3+1;
      }
      if(var3<=var2&&var3<=var1){a[i][j]=var3;}
      else if(var2<=var3&&var2<=var1){a[i][j]=var2;}
      else{a[i][j]=var1;}
      }
    }
  }
  //std::cout<<"    ";
  //for(int i=0;i<str2.size();i++){
  //  std::cout<<str2[i]<<" ";
  //}
  //std::cout<<'\n';
  //for(int i=0;i<a.size();i++){
  //  if(i!=0){
  //  std::cout<<str1[i-1]<<" ";}
  //  else{
  //    std::cout<<"  ";
  //  }
  //  for(int j=0;j<a[i].size();j++){
  //    std::cout<<a[i][j]<<" ";
  // }
   // std::cout<<'\n';
  //}
  return a[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

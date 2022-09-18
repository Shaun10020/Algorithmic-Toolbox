#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  std::vector<std::vector<int>> a;
  //Initialization the array
  for(int i=0;i<w.size()+1;i++)
  {
    std::vector<int> b(W+1,0);
    a.push_back(b);
  }

  // Compute the optimal weight for each cell
  for(int i=0;i<a.size();i++){
    if(i==0){continue;}
    for(int j=0;j<a[0].size();j++){
      a[i][j]=a[i-1][j];
      if(j>=w[i-1]){
        int value=a[i-1][j-w[i-1]]+w[i-1];
        if (value>a[i][j]){
          a[i][j]=value;
        }
      }
    }
  }
  
  //Display the Array, used for debug the result
  // for(int i=0;i<a.size();i++){
  //   for(int j=0;j<a[i].size();j++){
  //     std::cout<<a[i][j]<<" ";
  //  }
  //   std::cout<<'\n';
  // }

  //Find the maximum weight
  int max_weight=0;
  for(int i=0;i<W+1;i++){
    if(max_weight<a[w.size()][i]){
      max_weight=a[w.size()][i];
    }
  }
  return max_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}

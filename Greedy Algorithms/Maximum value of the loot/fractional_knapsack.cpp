#include <iostream>
using namespace std;
#include <algorithm> 
#include <vector>
using std::vector;

bool cmp(pair<int, float>& a,pair<int, float>& b)
{
    return a.second > b.second;
}
  

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector <pair<int, float>> M;

  for(int i=0;i<weights.size();i++){
    M.push_back(make_pair(i,(float)values[i]/(float)weights[i]));
  } 
  sort(M.begin(),M.end(),cmp);
  for(auto &item:M){
    if (capacity==0){
      break;
    }
    if (capacity>=weights[item.first]){
      value+=values[item.first];
      capacity-=weights[item.first];
    }else{
      value+=item.second*capacity;
      break;
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}

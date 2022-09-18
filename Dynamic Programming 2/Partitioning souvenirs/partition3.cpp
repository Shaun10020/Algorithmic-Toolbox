#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>

using std::vector;

int partition3(vector<int> &A)
{

  //Computer Total sum and verify 3 divisiable or not, and check if coin larger than total value/3
  int sum = std::accumulate(A.begin(), A.end(), 0);
  if (sum % 3 != 0)
  {
    return 0;
  }
  int target = sum / 3;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] > target)
    {
      return 0;
    }
  }

  //repeat 3 times to find can seperate 3 parts or not
  for (int count = 0; count < 3; count++)
  {
    //intialize set vector
    std::vector<std::set<int>> set_vector;
    for (int i = 0; i < target + 1; i++)
    {
      std::set<int> set_1;
      set_1.insert(0);
      set_vector.push_back(set_1);
    }
    std::vector<int> a(target + 1, 0);

    //loop every coin
    for (int i = 0; i < A.size(); i++)
    {
      for (int j = 0; j < target + 1; j++)
      {
        if (j == 0)
        {
          continue;
        }
        else if (a[target - j] != 0 && A[i] - j < 1)
        {
          a[target - j + A[i]] = 1;
          set_vector[A[i]].insert(A[i]);
          set_vector[A[i]].insert(set_vector[target - j].begin(),set_vector[target - j].end());
        }
        if (a[A[i]] == 0)
        {
          a[A[i]] = 1;
          set_vector[A[i]].insert(A[i]);
        }
      }
      if (a[target] == 1)
      {
        break;
      }
    }
    if (a[target] == 1)
    {
      for (auto it = set_vector[target].begin(); it != set_vector[target].end(); ++it)
      {
        if (*it == 0)
        {
          continue;
        }
        std::vector<int>::iterator index;
        index=find(A.begin(),A.end(),*it);
        A.erase(index);
      }
    }
    else
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}

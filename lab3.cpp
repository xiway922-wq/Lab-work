#include <iostream>
#include <vector>
#include <limits>

using namespace std;


pair<int, int> maxsearch(const vector<vector<double>> & arr, int n, int k)
{
 double maxVal = -numeric_limits<double>::infinity();
 int r = -1, c = -1;

 for(int i = 0; i < n; ++i)
 {
  for(int j = 0; j < n; ++j)
  {
    if (i == j && i < k) continue;
    if(arr[i][j] > maxVal)
    {
      maxVal = arr[i][j];
      r = i; c = j;
    }
  }
 }
    return {r,c};
}


void filldiagonal(vector<vector<double>> & arr, int n)
{

  for (int k = 0; k < n; ++k)
    {
        auto [r, c] = maxsearch(arr, n, k);
        swap(arr[k][k], arr[r][c]);
    }
}


int rowsearch (const vector<vector<double>> & arr, int n)
{
  for(int i = 0; i < n; ++i)
  {
    bool haspos = false;
    for(int j = 0; j < n; ++j)
    {
      if(arr[i][j] > 0)
      {
        haspos = true;
        break;
      }
    }
    if(haspos==false)
      {
        return i+1;
      }  
  }

  return -1;
}


int main() 
{
constexpr int MAX = 10; 
cout << "Enter the matrix size: "; 
int n; 
cin >> n;

if(n > MAX || n < 1)
return 1;

vector<vector<double>> arr(n, vector<double>(n));

for(int i = 0; i < n; ++i)
{
    for(int j = i; j < n; ++j)
    {
      cout << "Enter [" << i <<"]" << "[" << j << "] ";
      cin >> arr[i][j];
      arr[j][i] = arr[i][j];
    }
}
cout << '\n';  

for(int i = 0; i < n; ++i)
{
    for(int j = 0; j < n; ++j)
    {
      cout << arr[i][j] << ' ';
    }
 cout << '\n';
}  
cout << '\n';  

filldiagonal(arr, n);

for(int i = 0; i < n; ++i)
{
    for(int j = 0; j < n; ++j)
    {
      cout << arr[i][j] << ' ';
    }
 cout << '\n';
}   
cout << '\n';   

int rowpos = rowsearch (arr, n);
  if (rowpos==-1)
    cout << "There is no row without positive elements";
  else
    cout << "The row without positive: " << rowpos;

return 0;
}
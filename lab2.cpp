#include <iostream>
#include <cmath>
#include <string>
#include <random>

using namespace std;

void ManualArr(int n, double arr[]);
void AutoArr(int n, double arr[]);
void MaxAbsElement(int n, double arr[]);
void SumBetweenPos(int n, double arr[]);



int main()
{
    constexpr int MAXSIZE = 100;
    cout << "Enter the number of elements n: " << '\n';
    int n;
    cin >> n;

    if (n > MAXSIZE || n < 1)
        return 1;

    double arr[MAXSIZE];

    cout << "Choose input method (manual/auto): ";
    string inputType;
    cin >> inputType;

    if (inputType == "manual")
        ManualArr(n, arr);
    else if (inputType == "auto")
        AutoArr(n, arr);
    else
        return 2;

    return 0;
}



void MaxAbsElement(int n, double arr[])
{
    double maxAbs = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (fabs(arr[i]) > fabs(maxAbs))
        {
            maxAbs = arr[i];
        }
    }
    cout << "Max element of array: " << maxAbs << endl;
}



void SumBetweenPos(int n, double arr[])
{
    int first = -1, second = -1;
    int k = 0;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > 0)              //Если считать, что ноль положительное, то: if(arr[i] >= 0)
            {
                if (first == -1) first = i;
                else if (second == -1) 
                {
                    second = i;
                    break;
                }
            }
        }

    if (first == -1 || second == -1)
    {
        cout << "Less than two positive elements." << endl;
        return;
    }

    double sum = 0.0;
    for (int i = first + 1; i < second; ++i)
    {
        sum += arr[i];
    }
    cout << "Sum of the numbers between two positive: " << sum << endl;

    return;
}



void ManualArr(int n, double arr[])
{
    for (int i = 0; i < n; ++i)
    {
        cout << "enter a value of " << i << " element" << endl;
        cin >> arr[i];
    }

    MaxAbsElement(n, arr);
    SumBetweenPos(n, arr);

}

void AutoArr(int n, double arr[])
{
    double min, max;
    cout << "Enter min limit: ";
    cin >> min;
    cout << "Enter max limit: ";
    cin >> max; 

    if(min > max)
    {
        cout << "Error. min > max";
        return;
    }

    random_device rd;                   
    mt19937_64 gen(rd());                  
    uniform_real_distribution<double> dist(min, max);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = dist(gen);
        cout << arr[i] << " ";
    }
    cout << endl;

    MaxAbsElement(n, arr);
    SumBetweenPos(n, arr);

}
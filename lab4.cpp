#include <iostream> 

using namespace std;

bool isdate(const char* str2, int start, int length);


char* _strchr(const char* str, char c)
{
    for (int i = 0; ; ++i)
    {
        if(str[i] == c)
        {
            return (char*)&str[i];
        }
        if(str[i] == '\0')
        {
            return nullptr;
        }
    }
}


int main()
{   
    // Задача А
    cout << "Enter the line: ";
    char str[301];

    char asym;
    int i = 0;
    while(cin.get(asym) && asym != '\n' && i < 300)
    {
        str[i] = asym;
        ++i;
    } 
    str[i] = '\0';
    
    cout << "Enter the element: ";
    char c;
    cin >> c;
    cin.ignore(); 

    char* result = _strchr(str, c);
    
    if (result != nullptr) 
    {
        cout << "found at position: " << (result - str) << '\n';
        cout << "tail: " << result << '\n';
    }
    else 
    {
        cout << "not found" << endl;
    } 


    // Задача Б
    cout << "Enter the line: ";
    char str2[301];

    char bsym;
    int k = 0;
    while(cin.get(bsym) && bsym != '\n' && k < 300)
    {
        str2[k] = bsym;
        ++k;
    }
    str2[k] = '\0';

    int j = 0;
    int count = 0;
    while(str2[j] != '\0')
    {
        while(str2[j] == ' ') 
        {
            ++j;  
        }

        if(str2[j] == '\0')
        {
            break;
        }

        int start = j;

        while(str2[j] != ' ' && str2[j] != '\0')
        {
            ++j;
        }
        
        int length = j - start;

        if(isdate(str2, start, length)) 
        {
        ++count;
        }
    }  

    cout << "Dates: " << count;

    return 0;
}

bool isdate(const char* str2, int start, int length)
{
    if (length != 10) return false;

    if (str2[start + 0] < '0' || str2[start + 0] > '9') return false;
    if (str2[start + 1] < '0' || str2[start + 1] > '9') return false;
    if (str2[start + 2] != '/')   return false;
    if (str2[start + 3]  < '0' || str2[start + 3] > '9') return false;
    if (str2[start + 4] < '0' || str2[start + 4] > '9') return false;
    if (str2[start + 5] != '/')   return false;
    if (str2[start + 6] < '0' || str2[start + 6] > '9') return false;
    if (str2[start + 7] < '0' || str2[start + 7] > '9') return false;
    if (str2[start + 8] < '0' || str2[start + 8] > '9') return false;
    if (str2[start + 9] < '0' || str2[start + 9] > '9') return false;

    int day   = (str2[start + 0] - '0') * 10 + (str2[start + 1] - '0');
    int month = (str2[start + 3] - '0') * 10 + (str2[start + 4] - '0');

    if(day < 1 || day > 31)   return false;
    if(month < 1 || month > 12)   return false;

    return true;
}
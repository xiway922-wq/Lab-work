#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void Showfile(const string& path);

int main()
{
    cout << "Enter the path to input file or name (if the file is in the program folder): ";
    string inpath;
    getline(cin, inpath);

ifstream fin(inpath);

    cout << "Enter the path to output file or name (if the file is in the program folder): ";
    string outpath;
    getline(cin, outpath);

ofstream fout(outpath, ios::out);

    string line;
    string prevline;
    int count = 0;
    int numline = 0;
    int startline = 0;
    int numgroup = 0;
    bool first = true;

    while(getline(fin, line))
    {
        numline++;

        if(first)
        {
            prevline = line;
            startline = numline;
            count = 1;
            first = false;
        }

        else if (line == prevline)
        {
            ++count;
        }

            else
            {
                if (count > 1)
                {
                    ++numgroup;
                    fout << "Group: " << numgroup << '\n';
                    fout << "Number of the first line: " << startline << '\n';
                    fout << "Number of repetitions: " << count << '\n';
                    fout << "Line text: " << prevline << '\n' << '\n';
                }
                prevline = line;
                startline = numline;
                count = 1;
            }


    }

    if (count > 1)
    {
        ++numgroup;
        fout << "Group: " << numgroup << '\n';
        fout << "Number of the first line: " << startline << '\n';
        fout << "Number of repetitions: " << count << '\n';
        fout << "Line text: " << prevline << '\n';
    }

    fin.close();  

    fout.close();

    char answer;
    cout << "Show input file? (y/n): " << '\n';
    cin >> answer;
    if(answer == 'y')
    Showfile(inpath);
    

    cout << "Show output file? (y/n): " << '\n';
    cin >> answer;
    if(answer == 'y')
    Showfile(outpath);
    
}

void Showfile(const string& path)
{
    ifstream f(path);
    string s;
    while (getline(f, s))
    {
        cout << s << '\n';
    }
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
    ifstream inputFile;
    string filename;
    string search_w;
    string found_w;
    bool found = 0;
    string line;

    if (argc == 1)
    {
        string sen, sub;
        int position;
        cout << "Enter the Sentence" << endl;
        getline(cin, sen);

        cout << "Enter string to find" << endl;
        cin >> sub;

        position = (sen.find(sub));
        if (position == -1)
            cout << "Not found";
        else
            cout << "Found in position " << position;
    }


    if (argc > 1)
    {

        search_w = &*argv[1];
        filename = &*argv[2];

        inputFile.open(filename);
        if (inputFile)
        {
            while (getline(inputFile, line))
                {
                    if (line.find(search_w) != -1)
                    {
                        cout << line << endl << endl;
                        found = 1;

                    }
                }
            
            if (found == 0)
            {
                cout << "Word " << search_w << "not found in file: " << filename;
            }

            inputFile.close();
        }
        else
            cout << "Error, couldn't read file: " << filename;
    }



    return 0;
}

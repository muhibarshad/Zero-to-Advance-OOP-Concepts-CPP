#include "iostream"
#include "fstream"

using namespace std;

int main()
{
    int a;
    float f;

    // open or create a file in output (writing) mode
    ofstream outf("test.txt"); // OR		//fstream outf("test.txt", ios::out);

    if (!outf) // checking file is opened/created
    {
        cout << "File Error!" << endl;
        exit(0);
    }

    while (cin >> a >> f) // taking input from user press ctrl+z
    {
        outf << a << " " << f << endl; // writing data to file
    }

    outf.close(); // closing the file

    /*Reading from file*/

    // open a file in input (reading) mode
    ifstream inf("test.txt"); // OR		//fstream outf("test.txt", ios::in);

    if (!inf) // checking file is opened/created
    {
        cout << "File Error!" << endl;
        exit(0);
    }

    while (inf >> a >> f) // taking input (reading) from file till EOF
    {
        cout << a << " " << f << endl; // writing data to console
    }

    /*

    //Reading from file using eof() function

    inf >> a >> f;						//reading first record
    while (!inf.eof())					//keep running till EOF
    {
        cout << a << " " << f << endl;	//writing data to console
        inf >> a >> f;					//reading next record
    }

    */

    inf.close(); // closing the file

    return 0;
}
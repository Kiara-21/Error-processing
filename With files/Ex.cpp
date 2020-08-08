#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    const int m = 5;
    int A[m][m];
    int B[m][m];

    int amount = 0;
    int min_mnoj = 1;

    ifstream rd_A;
    rd_A.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        rd_A.open("Matrix_A.txt");
    }
    catch (const std::exception & err)
    {
        cout << "Matrix A file not found" << endl;
        return 0;
    }


    try {
        while (!rd_A.eof())
        {
            rd_A >> A[amount/5][amount % 5];
            amount++;
        }

    }
    catch (const std::exception & er) {
        cout << "Type error" << endl;
        return 0;
    }

    try {
        if (amount != 25) {
            throw 111;
            return 0;
        }
    }
    catch (int th){
        cout << "Error #" << th << " - wrong number of items";
        return 0;
    }



    for (int i = 0; i < m; ++i)
    {
        int min = A[i][0];
        for (int j = 1; j < m; ++j)
            if (A[i][j] < min)
                min = A[i][j];
        min_mnoj = min_mnoj * min;
    }

    cout << "Product of minimum items in rows = " << min_mnoj << endl;

    cout << "\n********************\n";

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
                B[i][j] = A[j][i];


    ofstream wr_B;
    wr_B.exceptions(ofstream::badbit | ofstream::failbit);

    try
    {
        wr_B.open("Matrix_B.txt");
    }
    catch (const std::exception & e)
    {
        cout << "Matrix B file not found" << endl;
    }

    try
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                wr_B << B[i][j] <<" ";
            }
            wr_B << endl;
        }
    }
    catch (const std::exception & errr)
    {
        cout << "Cannot write to file" << endl;
        return 0;
    }

    rd_A.close();
    wr_B.close();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    cout << "\n********************\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }


    return 0;
}
#include <iostream>
using namespace std;

const int SIZE = 10;

class matrix
{
    int rows, cols;
    int a[SIZE][SIZE];

public:
    matrix()
    {
        rows = cols = 0;
    }

    void getdata();
    void showdata();

    matrix mat_add(matrix m2);
    matrix mat_mul(matrix m2);
    matrix mat_transpose();
    bool mat_diag();
};

/* Input */
void matrix :: getdata()
{
    do
    {
        cout << "Enter rows and columns (1 to " << SIZE << "): ";
        cin >> rows >> cols;

        if (rows < 1 || rows > SIZE || cols < 1 || cols > SIZE)
            cout << "Invalid size. Please re-enter.\n";

    } while (rows < 1 || rows > SIZE || cols < 1 || cols > SIZE);

    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];
}


/* Display */
void matrix :: showdata()
{
    if (rows == 0 || cols == 0)
    {
        cout << "Matrix is empty. No data to display.\n";
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}


/* Addition */
matrix matrix :: mat_add(matrix m2)
{
    matrix r;

    if (rows != m2.rows || cols != m2.cols)
    {
        cout << "Addition not possible\n";
        return r;
    }

    r.rows = rows;
    r.cols = cols;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            r.a[i][j] = a[i][j] + m2.a[i][j];

    return r;
}

/* Multiplication */
matrix matrix :: mat_mul(matrix m2)
{
    matrix m3;

    if (cols != m2.rows)
    {
        cout << "Multiplication not possible\n";
        return m3;
    }

    m3.rows = rows;
    m3.cols = m2.cols;

    for (int i = 0; i < m3.rows; i++)
        for (int j = 0; j < m3.cols; j++)
        {
            m3.a[i][j] = 0;
            for (int k = 0; k < cols; k++)
                m3.a[i][j] += a[i][k] * m2.a[k][j];
        }

    return m3;
}

/* Transpose */
matrix matrix :: mat_transpose()
{
    matrix m3;
    m3.rows = cols;
    m3.cols = rows;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m3.a[j][i] = a[i][j];

    return m3;
}

/* Diagonal */
bool matrix :: mat_diag()
{


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != j && a[i][j] != 0)
                return false;
        }
    }
    return true;    
}


/* Main with Switch Case */
int main()
{
    matrix m1, m2, m3;
    int ch;
    // m1.showdata();
    cout << "\n***Menu of matrix operations***\n";
    cout << "\n1. Addition";
    cout << "\n2. Multiplication";
    cout << "\n3. Transpose of Matrix 1";
    cout << "\n4. Diagonal of Matrix 1";
    cout << "\n5. Exit\n";
    do{
        cout << "\nEnter your choice: ";
    cin >> ch;

    switch (ch)
    {
        case 1:
            cout<<"\nfor addition\n";
            cout << "Enter Matrix 1\n";
            m1.getdata();
    
            cout << "Enter Matrix 2\n";
            m2.getdata();
            cout << " Matrix 1\n";
            m1.showdata();
            cout << " Matrix 2\n";
            m2.showdata();
            m3 = m1.mat_add(m2);
            cout << "Addition Result:\n";
            m3.showdata();
            break;

        case 2:
            cout<<"\nfor multiplication\n";
            cout << "Enter Matrix 1\n";
            m1.getdata();

            cout << "Enter Matrix 2\n";
            m2.getdata();
            cout << " Matrix 1\n";
            m1.showdata();
            cout << " Matrix 2\n";
            m2.showdata();
            m3 = m1.mat_mul(m2);
            cout << "Multiplication Result:\n";
            m3.showdata();
            break;

        case 3:
            cout<<"\nfor transpose\n";
            cout << "Enter Matrix :\n";
            m1.getdata();
            cout << " Matrix \n";
            m1.showdata();
            m3 = m1.mat_transpose();
            cout << "Transpose Result:\n";
            m3.showdata();
            break;

        case 4:
            cout<<"\nfor diagonal matrix:\n";
            cout << "Enter Matrix \n";
            m1.getdata();
            cout << " Matrix \n";
            m1.showdata();
            if(m1.mat_diag())
            {
                cout << "Diagonal Matrix:\n";
                m1.showdata();
            }
            else
                cout << "Not a diagonal matrix\n";
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice\n";
    }
    }while(1);
    return 0;
}
    
#include <iostream>
#include <cmath>
#include <cstdlib>

const int max_size = 10;
typedef double matrix[max_size][max_size];


void inputMat(matrix& Mat, int r, int c);
void printMat(matrix& Mat, int r, int c);
bool op1valid(int r1, int c1, int r2, int c2, int& n);
void addMat(matrix& Mat1, matrix& Mat2, matrix& Mat3, int n);
void subMat(matrix& Mat1, matrix& Mat2, matrix& Mat3, int n);
bool op2valid(int c1, int r2);
void multMat(matrix& Mat1, matrix& Mat2, matrix& mat3, int r1, int c1, int c2);
bool op3valid(int r, int c, int& n);
long long detcalc(matrix& Mat, int n);
void MatcoF(matrix& Mat, int r, int c, int n);
void Matadjoint(matrix& Mat, matrix& adj, int n);
bool op4valid(matrix& mat);
void inverseMat(matrix& Mat1, matrix& Mat2, int n);
void intialize();

matrix MatA;
matrix MatB;
matrix MatC;
matrix MatD;
matrix temp;
int n;


using namespace std;



int main()
{
    int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

    cout << "Please enter dimensions of Matrix A:";

    cin >> r1 >> c1;

    cout << endl;

    cout << "Please enter dimensions of Matrix B:";

    cin >> r2 >> c2;

    cout << endl;

    cout << "Please enter values of Matrix A:";

    inputMat(MatA, r1, c1);

    cout << endl;

    cout << "Please enter values of Matrix B:";

    inputMat(MatB, r2, c2);

    cout << endl;

    int operation = 0;

    while (operation != 7) {

        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):";

        cin >> operation;

        cout << endl;

        switch (operation) {
        case 1:
            if (op1valid(r1, c1, r2, c2, n)) {
                intialize();
                addMat(MatA, MatB, MatC, n);
                printMat(MatC, r1, c2);
                break;
            }
            else {
                cout << "The operation you chose is invalid for the given matrices." << endl;
                break;
            }
        case 2:
            if (op1valid(r1, c1, r2, c2, n)) {
                intialize();
                subMat(MatA, MatB, MatC, n);
                printMat(MatC, r1, c2);
                break;
            }
            else {
                cout << "The operation you chose is invalid for the given matrices." << endl;
                break;
            }
        case 3:
            if (op2valid(c1, r2)) {
                intialize();
                multMat(MatA, MatB, MatC, r1, c1, c2);
                printMat(MatC, r1, c2);
                break;
            }
            else {
                cout << "The operation you chose is invalid for the given matrices." << endl;
                break;
            }
        case 4:
            if (op2valid(c1, r2) && op3valid(r2, c2, n) && op4valid(MatB)) {
                intialize();
                inverseMat(MatB, MatD, n);
                multMat(MatA, MatD, MatC, r1, c1, c2);
                printMat(MatC, r1, c2);
                break;
            }
            else {
                cout << "The operation you chose is invalid for the given matrices." << endl;
                break;
            }
        case 5:
            if (op3valid(r1, c1, n)) {
                long long det = detcalc(MatA, n);
                cout << det << endl;
                break;
            }
            else {
                cout << "The operation you chose is invalid for the given matrices." << endl;
                break;
            }
        case 6:
            if (op3valid(r2, c2, n)) {
                long long det = detcalc(MatB, n);
                cout << det << endl;
                break;
            }
            else {
                cout << "The operation you chose is invalid for the given matrices." << endl;
                break;
            }
        case 7:
            cout << "Thank you!";
            break;

        }
    }
}


void inputMat(matrix& Mat, int r, int c)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> Mat[i][j];
        }
    }
}

void intialize()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            MatC[i][j] = 0;
            MatD[i][j] = 0;
        }
    }
}

void printMat(matrix& Mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            Mat[i][j] = round(Mat[i][j]);
            if (Mat[i][j] == -0) {
                cout << abs(Mat[i][j]) << " ";
            }
            else {
                cout << Mat[i][j] << " ";
            }
        }
        cout << "\n";
    }
}


bool op1valid(int r1, int c1, int r2, int c2, int& n)
{
    if (r1 == r2 && c1 == c2)
    {
        n = r1;
        return true;
    }
    else
    {
        return false;
    }
}


void addMat(matrix& Mat1, matrix& Mat2, matrix& Mat3, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Mat3[i][j] = Mat1[i][j] + Mat2[i][j];
        }
    }
}


void subMat(matrix& Mat1, matrix& Mat2, matrix& Mat3, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            Mat3[i][j] = Mat1[i][j] - Mat2[i][j];
        }
    }
}


bool op2valid(int c1, int r2)
{
    if (c1 == r2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void multMat(matrix& Mat1, matrix& Mat2, matrix& mat3, int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            mat3[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                mat3[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}


bool op3valid(int r, int c, int& n)
{
    if (r == c) {
        n = r;
        return true;
    }
    else {
        return false;
    }
}


long long detcalc(matrix& Mat, int n)
{
    long long D = 0;
    matrix temp;
    if (n == 1) {
        D = Mat[0][0];
        return D;
    }
    else if (n == 2) {
        D = (Mat[0][0] * Mat[1][1]) - (Mat[0][1] * Mat[1][0]);
        return D;
    }
    else {
        for (int k = 0; k < n; k++) {
            int itemp = 0;
            for (int i = 1; i < n; i++) {
                int jtemp = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    temp[itemp][jtemp] = Mat[i][j];
                    jtemp++;
                }
                itemp++;
            }
            D += (pow(-1, k) * Mat[0][k] * detcalc(temp, n - 1));
        }
        return D;
    }
}


void MatcoF(matrix& Mat, matrix& temp, int r, int c, int n)
{
    int itemp = 0;
    int jtemp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != r && j != c) {
                temp[itemp][jtemp] = Mat[i][j];
                jtemp++;
                if (jtemp == n - 1) {
                    jtemp = 0;
                    itemp++;
                }
            }
        }
    }
}


void Matadjoint(matrix& Mat, matrix& adj, int n)
{
    if (n == 1) {
        adj[0][0] = 1;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                MatcoF(Mat, temp, i, j, n);
                adj[j][i] = (pow(-1, i + j) * detcalc(temp, n - 1)); 
            }
        }
    }
}


bool op4valid(matrix& mat)
{
    int det = detcalc(mat, n);
    if (det == 0) {
        return false;
    }
    else {
        return true;
    }
}

void inverseMat(matrix& Mat1, matrix& Mat2, int n)
{
    matrix adj;
    Matadjoint(Mat1, adj, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Mat2[i][j] = (adj[i][j]) / double(detcalc(Mat1, n));
        }
    }
}

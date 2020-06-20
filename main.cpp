#include <iostream>
#include "PartA/IntMatrix.h"
#include "Matrix.h"
using std::cout;
using std::endl;

using namespace mtm;
int main() {

    Matrix<IntMatrix> m1(Dimensions(3,4));
    for (int i = 0; i < m1.height(); ++i) {
        for (int j = 0; j < m1.width(); ++j) {
            cout << m1(i,j) << endl;
        }
    }
    IntMatrix im(Dimensions(2,7),5);
    Matrix<IntMatrix> m2(Dimensions(3,4),im);
    Matrix<IntMatrix> m3 = m2;
    m1 = m2 = m3;
    for (int i = 0; i < m1.height(); ++i) {
        for (int j = 0; j < m1.width(); ++j) {
            cout << m1(i,j) << endl;
        }
    }
    //    TemArray<TemArray<IntMatrix>> a(5);
//    for (int i = 0; i < a.size(); ++i) {
//        for (int j = 0; j < a[i].size(); ++j) {
//            Dimensions d(i+1,j+1);
//            a[i][j] = IntMatrix(d,i);
//        }
//    }
//    for (int i = 0; i < a.size(); ++i) {
//        for (int j = 0; j < a[i].size(); ++j) {
//            Dimensions d(i+1,j+1);
//            cout << a[i][j] << endl;
//        }
//    }
//    TemArray<IntMatrix> a(20);
//    for (int i = 0; i < a.size(); ++i) {
//        Dimensions d(i+1,i+2);
//        a[i] = IntMatrix(d,i);
//    }
//    for (int j = 0; j < a.size(); ++j) {
//        cout << a[j] << endl;
//    }
//    a[19](0,0) = -3;
//    try {
//        cout << a[1934567];
//    }
//    catch(std::exception& e){
//        cout << e.what() << endl;
//    }

    return 0;
}

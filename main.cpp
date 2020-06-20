#include <iostream>
#include "PartA/IntMatrix.h"
#include "Matrix.h"
using std::cout;
using std::endl;

using namespace mtm;
int main() {

    Matrix<int>diagonal_2 = Matrix<int>::Diagonal(5,3);
    for (int i = 0; i < diagonal_2.height(); ++i) {
        for (int j = 0; j < diagonal_2.width(); ++j) {
            cout << diagonal_2(i,j) << "   ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    Dimensions dim(2,4);
    Matrix<int> m1(dim,9);
    Matrix<bool> ma = m1 < 4;
    for (int i = 0; i < ma.height(); ++i) {
        for (int j = 0; j < ma.width(); ++j) {
            cout << ma(i,j) << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    Matrix<int> m2(dim,4);
    Matrix<bool> mb = m2 <= 4;
    for (int i = 0; i < mb.height(); ++i) {
        for (int j = 0; j < mb.width(); ++j) {
            cout << mb(i,j) << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    Matrix<int> m3(dim,2);
    Matrix<bool> mc = m3 > 4;
    for (int i = 0; i < mc.height(); ++i) {
        for (int j = 0; j < mc.width(); ++j) {
            cout << mc(i,j) << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    Matrix<int> m4(dim,5);
    Matrix<bool> md = m4 >= 4;
    for (int i = 0; i < md.height(); ++i) {
        for (int j = 0; j < md.width(); ++j) {
            cout << md(i,j) << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    Matrix<int> m5(dim,2);
    Matrix<bool> me = m5 == 4;
    for (int i = 0; i < me.height(); ++i) {
        for (int j = 0; j < me.width(); ++j) {
            cout << me(i,j) << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    Matrix<int> m6(dim,2);
    Matrix<bool> mf = m6 != 4;
    for (int i = 0; i < mf.height(); ++i) {
        for (int j = 0; j < mf.width(); ++j) {
            cout << mf(i,j) << " ";
        }
        cout << "\n";
    }

//    IntMatrix im(Dimensions(2,7),5);
//    Matrix<IntMatrix> m2(Dimensions(3,4),im);
//    Matrix<IntMatrix> m3 = m2;
//    m1 = m2 = m3;
//    for (int i = 0; i < m1.height(); ++i) {
//        for (int j = 0; j < m1.width(); ++j) {
//            cout << m1(i,j) << endl;
//        }
//    }
//    //    TemArray<TemArray<IntMatrix>> a(5);
////    for (int i = 0; i < a.size(); ++i) {
////        for (int j = 0; j < a[i].size(); ++j) {
////            Dimensions d(i+1,j+1);
////            a[i][j] = IntMatrix(d,i);
////        }
////    }
////    for (int i = 0; i < a.size(); ++i) {
////        for (int j = 0; j < a[i].size(); ++j) {
////            Dimensions d(i+1,j+1);
////            cout << a[i][j] << endl;
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

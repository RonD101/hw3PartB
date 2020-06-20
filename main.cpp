#include <iostream>
#include "PartA/IntMatrix.h"
#include "Matrix.h"
using std::cout;
using std::endl;

using namespace mtm;
int main() {

    Matrix<int> m1(Dimensions(3,4),5);
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

#include <iostream>
#include "Array.h"
#include "PartA/IntMatrix.h"
using std::cout;
using std::endl;

using namespace mtm;
int main() {
    Array<IntMatrix> a(20);
    for (int i = 0; i < a.size(); ++i) {
        Dimensions d(i+1,i+2);
        a[i] = IntMatrix(d,i);
    }
    for (int j = 0; j < a.size(); ++j) {
        cout << a[j] << endl;
    }
    a[19](0,0) = -3;
    try {
        cout << a[1934567];
    }
    catch(std::exception& e){
        cout << e.what() << endl;
    }
    return 0;
}

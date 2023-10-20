#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cout << "Enter a num: ";
    cin >> a;
    cout << "Enter b num: ";
    cin >> b;

    int div1 = 1;
    int min_num = (a < b) ? a : b;

    for (int i = 1; i <= min_num; i++) {
        if (a % i == 0 && b % i == 0) {
            div1 = i;
        }
    }

    cout << div1 << endl;

    return 0;
}

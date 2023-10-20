#include <iostream>

using namespace std;

void hanoi(int n, int from_peg, int to_peg, int aux_peg) {
    if (n == 1) {
        cout << "Move disk 1 from peg " << from_peg << " to peg " << to_peg << endl;
        return;
    }
    
    hanoi(n - 1, from_peg, aux_peg, to_peg);
    cout << "Move disk " << n << " from peg " << from_peg << " to peg " << to_peg << endl;
    hanoi(n - 1, aux_peg, to_peg, from_peg);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    
    hanoi(n, 1, 3, 2);
    
    return 0;
}

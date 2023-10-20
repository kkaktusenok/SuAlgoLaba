#include <iostream>
#include <vector>

bool canPayWithoutChange(const std::vector<int>& coins, int N, int index) {
    if (N == 0) {
        return true;
    }
    if (index < 0) {
        return false;
    }
    
    return canPayWithoutChange(coins, N - coins[index], index - 1) ||
           canPayWithoutChange(coins, N, index - 1);
}

int main() {
    int N;
    std::cout << "Enter count N: ";
    std::cin >> N;

    int M;
    std::cout << "Enter count of kind monets ";
    std::cin >> M;

    std::vector<int> coins(2 * M);
    std::cout << "Enter kind of monets: ";
    for (int i = 0; i < 2 * M; ++i) {
        std::cin >> coins[i];
    }

    if (canPayWithoutChange(coins, N, 2 * M - 1)) {
        std::cout << "Yes,we can pay withou change" << std::endl;
    } else {
        std::cout << "No,we need change" << std::endl;
    }

    return 0;
}

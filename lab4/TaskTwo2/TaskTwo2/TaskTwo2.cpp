#include <iostream>
#include <string>

using namespace std;

string addStarsBetweenLetters(const std::string& input, int index) {
    if (index == input.length() - 1) {
        return input.substr(index, 1);
    }
    
    return input.substr(index, 1) + '*' + addStarsBetweenLetters(input, index + 1);
}

int main() {
    string input;
    cout << "Enter String: ";
    cin >> input;

    string result = addStarsBetweenLetters(input, 0);
    cout << "result:  " << result << endl;

    return 0;
}

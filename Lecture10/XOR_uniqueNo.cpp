#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 5> arr = {4, 6, 9, 4, 6};
    int ans = 0;

    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }

    cout << ans << endl;
    cout << arr.size() << endl;

    return 0;
}

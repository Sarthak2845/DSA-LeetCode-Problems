#include <iostream>
using namespace std;

void leftRot(int arr[], int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void rightRot(int arr[], int n) {
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    cout << "Array after right rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    int tempArr[5];
    for (int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }

    cout << "Left rotation" << endl;
    leftRot(arr, n); 

    cout << "Right rotation" << endl;
    rightRot(tempArr, n);  

    return 0;
}

#include <iostream>
#include <stack>
#include<algorithm>
#include<cmath>
using namespace std;

void iterativeHanoi(int n, int src, int dest, int aux) {
    stack<int> s1, s2, s3;
    int totalMoves = pow(2, n) - 1;
    for (int i = n; i >= 1; i--) {
        s1.push(i);
    }
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            if (!s1.empty() && (s2.empty() || s1.top() < s2.top())) {
                s2.push(s1.top());
                s1.pop();
                cout << "Move disk " << s2.top() << " from rod " << src << " to rod " << dest << endl;
            }
            else {
                s1.push(s2.top());
                s2.pop();
                cout << "Move disk " << s1.top() << " from rod " << dest << " to rod " << src << endl;
            }
        }
        else if (i % 3 == 2) {
            if (!s1.empty() && (s3.empty() || s1.top() < s3.top())) {
                s3.push(s1.top());
                s1.pop();
                cout << "Move disk " << s3.top() << " from rod " << src << " to rod " << aux << endl;
            }
            else {
                s1.push(s3.top());
                s3.pop();
                cout << "Move disk " << s1.top() << " from rod " << aux << " to rod " << src << endl;
            }
        }
        else {
            if (!s2.empty() && (s3.empty() || s2.top() < s3.top())) {
                s3.push(s2.top());
                s2.pop();
                cout << "Move disk " << s3.top() << " from rod " << dest << " to rod " << aux << endl;
            }
            else {
                s2.push(s3.top());
                s3.pop();
                cout << "Move disk " << s2.top() << " from rod " << aux << " to rod " << dest << endl;
            }
        }
    }
}

int main() {
    int n, src = 1, dest = 2, aux = 3;
    cout << "Enter the number of disks: ";
    cin >> n;
    iterativeHanoi(n, src, dest, aux);
    return 0;
}

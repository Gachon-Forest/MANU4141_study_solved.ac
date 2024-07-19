/*
Date: 7/17
No: 11866
Tier: s - 5
Name: 요세푸스 문제 0
Language: c++
*/

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;

    vector<int> circle(N);

    for (int i = 0; i < N; i++) 
    {
        circle[i] = i + 1;
    }

    cout << "<";

    int idx = 0;

    while (circle.size() > 1)
    {
        idx = (idx + K - 1) % circle.size();

        cout << circle[idx];

        circle.erase(circle.begin() + idx);

        if (circle.size() > 0) 
        {
            cout << ", ";
        }
    }
    cout << circle[0] << ">" << endl;

    return 0;
} 

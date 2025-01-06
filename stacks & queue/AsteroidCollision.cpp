#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    for (int i = 0; i < asteroids.size(); ++i) {
        if (s.empty() || asteroids[i] > 0) {
            s.push(asteroids[i]);
        } else {
            while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
                s.pop();
            }
            if (s.empty() || s.top() < 0) {
                s.push(asteroids[i]);
            } else if (s.top() == abs(asteroids[i])) {
                s.pop();
            }
        }
    }
    vector<int> result(s.size());
    for (int i = s.size() - 1; i >= 0; --i) {
        result[i] = s.top();
        s.pop();
    }
    return result;
}

int main(){
    vector<int> asteroids = {-1, 500, 10, -50};
    vector<int> result = asteroidCollision(asteroids);
    cout << "After all collisions, the state of the asteroids are: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
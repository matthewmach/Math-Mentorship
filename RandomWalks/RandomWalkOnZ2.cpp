#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<string> combo;

int choose(int a, int b){
    if (a == 0 || b == 0)
        return 1;
    int dif = a-b, answer=1;
    for (int x=0; x<b; x++)
        answer *= a-x;
    for (int x=0; x<b; x++)
        answer /= b-x;
    return answer;
}   

void gen (int index, string cur, int end){
    if (index >= end)
        combo.push_back(cur);
    else{
        gen (index+1, cur + '0', end);
        gen (index+1, cur + '1', end);
        gen (index+1, cur + '2', end);
        gen (index+1, cur + '3', end);
    }
}

int main() {
    int h, walks=0, count=0;
    cout << "Number of steps: ";
    cin >> h;

    gen (0, "", h);
    
    cout << endl << "Winning Walks:" << endl;

    for (int x=0; x<combo.size(); x++){
        int locationx=0, locationy=0, y=0;
        while (y<h){
            if (combo[x][y] == '0') //0 is N
                locationx++;
            else if (combo[x][y] == '2') //2 is S
                locationx--;
            else if (combo[x][y] == '1') //1 is E
                locationy++;
            else //4 is W
                locationy--;
            y++;
        } 
        if (locationx == 0 && locationy == 0){
            walks++;
            cout << combo[x] << endl;
        }
    }
    
    cout << endl << "Number of winning walks: " << walks << endl;

    // int formula = pow (n-1, h/2) * choose (h, h/2), denom = pow(n, k);
    // cout << "Formula: " << formula << "/" << denom << endl;
    cout << "Probability of winning walk: " << walks << "/" << combo.size() << " = " << fixed << showpoint << setprecision(5) << (double)walks/(double)combo.size() << endl;
    return 0;
}

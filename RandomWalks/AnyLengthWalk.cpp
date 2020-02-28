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

void gen (int index, string cur, int end, int n){
    if (index >= end)
        combo.push_back(cur);
    else{
        for (int x=0; x<n; x++){
            char c = x+'0';
            gen (index+1, cur + c, end);
        }
    }
}

int main() {
    int n, h, walks=0, count=0;
    cout << "Number of options: ";
    cin >> n;
    cout << "Number of coin flips: ";
    cin >> h;

    gen (0, "", h, n);
    
    cout << endl << "Winning Walks:" << endl;

    for (int x=0; x<combo.size(); x++){
        int location=0, y=0;
        while (y<n){
            if (combo[x][y] == '0') //0 is back
                location--;
            else
                location++;
            y++;
        } 
        if (location == 0){
            walks++;
            cout << combo[x] << endl;
        }
    }
    
    cout << endl << "Number of winning walks: " << walks << endl;

    int formula = pow (n-1, h/2) * choose (h, h/2), denom = pow(n, k);
    cout << "Formula: " << formula << "/" << denom << endl;
    cout << "Probability of winning walk: " << walks << "/" << combo.size() << " = " << fixed << showpoint << setprecision(5) << (double)walks/(double)combo.size() << endl;
    return 0;
}

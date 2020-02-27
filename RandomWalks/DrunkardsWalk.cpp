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
    }
}

int f(int i, int h){
    int ans = choose(h - 1 + 2 * i, h - 1 + i);
    for (int j=0; j < i; j++)
        ans -= f(j, h) * choose(2 * (i - j) - 1, i - j - 1);
    return ans;
}

int main() {
    int n, h, walks=0, count=0;
    
    cout << "Location of home: ";
    cin >> h;
    cout << "Number of coin flips: ";
    cin >> n;

    gen (0, "", n);
    
    cout << endl << "Winning Walks:" << endl;

    for (int x=0; x<combo.size(); x++){
        int location=0, y=0;
        bool home = false;
        while (y<n && !home){
            if (combo[x][y] == '0') //0 is right
                location++;
            else                    //1 is left
                location--;
            if (location == h){
                walks++;              
                cout << combo[x] << endl;
                count++;
                home = true;
            }
            y++;
        } 
    }
    
    cout << endl << "Number of winning walks: " << walks << endl;

    int formula = 0;
    for (int i=0; i<(n-h)/2+1; i++)
        formula += f(i, h) * pow (2, n-2*i-h);
    cout << "Answer Calculated by Formula: " << formula << endl;

    cout << "Probability of winning walk: " << walks << "/" << combo.size() << " = " << fixed << showpoint << setprecision(5) << (double)walks/(double)combo.size() << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
string party1[4] = {"02", "11", "12", "13"};


bool adj (string b1, string b2){
    if (abs((int)b1[0] - (int)b2[0]) == 1 && b1[1] == b2[1]) 
        return true;
    else if (b1[0] == b2[0] && abs((int)b1[1] - (int)b2[1]) == 1)
        return true;
    return false;
}

bool check (string b1, string b2, string b3){
    if (adj(b1, b2)){
        if (adj(b1, b3))
            return true;
        else if (adj(b2, b3))
            return true;
    }
    else if (adj(b1, b3)){
        if (adj(b1, b2))
            return true;
        else if (adj(b2, b3))
            return true;
    }
    return false;
}

bool partOf (string num){
    for (int x = 0; x < 4; x++)
        if (party1[x].compare(num) == 0)
            return true;
    return false;
}

int wins (string b1, string b2, string b3){
    int count = 0;
    if (partOf(b1))
        count++;
    if (partOf(b2))
        count++;
    if (partOf(b3))
        count++;
    if (count > 1)
        return 1;
    return 0;
}

int main() {
    int countD = 1, win, count=0;
    vector<string> block, temp, temp2;
    for (int x = 0; x < 3; x++)
        for (int y = 1; y < 4; y++){
            string s = to_string(x) + to_string(y);    
            block.push_back(s);
        }
        for (int y = 1; y < block.size(); y++)
            for (int z = y+1; z < block.size(); z++)
                if (check(block[0], block[y], block[z])){
                    temp = block;
                    temp.erase(remove(temp.begin(), temp.end(), block[0]), temp.end());
                    temp.erase(remove(temp.begin(), temp.end(), block[y]), temp.end());
                    temp.erase(remove(temp.begin(), temp.end(), block[z]), temp.end());
                    for (int a=0; a < temp.size(); a++)
                        for (int b = a+1; b < temp.size(); b++)
                            for (int c = b+1; c < temp.size(); c++)
                                if (check(temp[a], temp[b], temp[c])){
                                    temp2 = temp;
                                    temp2.erase(remove(temp2.begin(), temp2.end(), temp[a]), temp2.end());
                                    temp2.erase(remove(temp2.begin(), temp2.end(), temp[b]), temp2.end());
                                    temp2.erase(remove(temp2.begin(), temp2.end(), temp[c]), temp2.end());
                                    if (check(temp2[0], temp2[1], temp2[2])){
                                        win = wins(block[0], block[y], block[z]) + wins(temp[a], temp[b], temp[c]) + wins(temp2[0], temp2[1], temp2[2]);
                                        if (win > 1){
                                            cout << "District " << countD << ": " << endl << block[0] << " " << block[y] << " " << block[z] << endl << temp[a] << " " << temp[b] << " " << temp[c] << endl << temp2[0] << " " << temp2[1] << " " << temp2[2] << endl << endl;
                                            countD++;
                                        }
                                        count++;
                                    }

                                }   
                }
    cout << "Total number of districts: " << count << endl;
    cout << "Total won by Matt: " << countD-1 << endl;
    cout << "Total won by Jim: " << count-countD+1 << endl;
    return 0;
}

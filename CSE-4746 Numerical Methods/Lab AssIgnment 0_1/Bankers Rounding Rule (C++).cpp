/*

 Author : Catalyst71
 < While there is a code, there is a bug > ¯\_(ツ)_/¯

*/


#include<bits/stdc++.h>
using namespace std;


bool checkOk(int significantNumber, int givenPoint) {
    return givenPoint < significantNumber;
}


int main()
{
    string number, finalNumber;
    int significant_count = 0, lastSigPos = -1, val, pos1, pos2;
    bool dPoint = true;

    cout << '\t' << "Bankers Rounding Rule\n\n";
    cout << "Enter Number : ";
    cin >> number;
    cout << "Enter upto how many significant digits you want to round up: ";
    cin >> val;

    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '.') dPoint = false;
    }
    if (dPoint) {
        int temp = 0 ;
        int j = number.size() - 1;
        while (number[j] == '0')temp++, j--;
        significant_count = number.size() - temp;
        if (checkOk(significant_count, val) == false) {
            while (1) {
                cout << "Enter a different value which is less than " << significant_count << " : ";
                cin >> val;
                if (checkOk(significant_count, val))break;
            }
        }
        if (number[val] > '5') number[val - 1] += 1;
        else if (number[val] == '5') {
            int digit = number[val - 1] - '0';
            if (digit & 1)number[val - 1] += 1;
        }
        for (int i = 0; i < val; i++) {
            finalNumber += number[i];
        }
        cout << "Rounded Value : " << finalNumber << "\n";
    }
    else {
        for (int i = 0; i < number.size(); i++) {
            if (number[i] >= '1' && number[i] <= '9') {
                significant_count++;
                lastSigPos = i;
            } else if (number[i] == '0') {
                if (lastSigPos == -1)continue;
                else {
                    significant_count++;
                    lastSigPos = i;
                }
            }
        }
        cout << significant_count << "\n";
        if (checkOk(significant_count, val) == false) {
            while (1) {
                cout << "Enter a different value which is less than " << significant_count << " : ";
                cin >> val;
                if (checkOk(significant_count, val))break;
            }
        }
        significant_count = 0;
        lastSigPos = -1;
        val++;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] >= '1' && number[i] <= '9') {
                significant_count++;
                lastSigPos = i;
            } else if (number[i] == '0') {
                if (lastSigPos != -1) {
                    significant_count++;
                    lastSigPos = i;
                }
            }
            if (significant_count == val - 1) {
                pos1 = lastSigPos;
            } else if (significant_count == val) {
                pos2 = lastSigPos;
                break;
            }
        }

        if (number[pos2] > '5') number[pos1] += 1;
        else if (number[pos2] == '5') {
            int digit = number[pos1] - '0';
            if (digit & 1)number[pos1] += 1;
        }
        for (int i = 0; i < pos2; i++) {
            finalNumber += number[i];
        }

        cout << finalNumber << "\n";
    }


}

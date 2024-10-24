#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Kiểm tra tính hợp lệ của số điện thoại
bool checkPhone(string str) {
    if (str.length() != 10) {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if ('0' > str[i] || str[i] > '9') {
            return false;
        }
    }
    return true;
}


// Chuyển thời gian sang giây
int secondCall(string secondTime) {
    int hours, minutes, seconds;
    char colon;
    
    stringstream ss(secondTime);
    ss >> hours >> colon >> minutes >> colon >> seconds;
    
    return hours * 3600 + minutes * 60 + seconds;
}

// Tính thời gian gọi theo giây
int timeCall(string time1, string time2) {
    
    int a = secondCall(time1);
    int b = secondCall(time2);
    
    return b - a;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int countWrongNumber = 0;
    int total = 0;
    unordered_map <string, int> totalFrom;
    unordered_map <string, int> totalTime;
    string temp;
    while (getline(cin, temp)) {
        
        if(temp == "#") {
            break;
        }
        
        stringstream ss(temp);
        string sdt1, sdt2, time1, time2;
        string colon, day;
        ss >> colon >> sdt1 >> sdt2 >> day >> time1 >> time2;
        
        if (checkPhone(sdt1) && checkPhone(sdt2)) {
            
        }
        else {
            countWrongNumber++;
        }
        
        total++;
        
        totalFrom[sdt1]++;
        
        int a = timeCall(time1, time2);
        
        totalTime[sdt1] += a;
    }
    
    while (cin >> temp) {
        
        if (temp == "?check_phone_number") {
            if (countWrongNumber != 0) {
                cout << countWrongNumber << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else if (temp == "?number_calls_from") {
            
            cin >> temp;
            cout << totalFrom[temp] << endl;
        }
        else if (temp == "?number_total_calls") {
            cout << total << endl;
        }
        else if (temp == "?count_time_calls_from") {
            cin >> temp;
            cout << totalTime[temp] << endl;
        }
        else if (temp == "#") {
            break;
        }
    }
    
    return 0;
}

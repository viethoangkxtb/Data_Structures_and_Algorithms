#include<bits/stdc++.h>
using namespace std;

map <string, int> phoneNumber;
map <string, int> timePhoneCall;
int check = 1;
int count1 = 0;

int convertHourToSecond (string timeCall) {
    int result;
    result = ((int)timeCall[0] * 10 + (int)timeCall[1]) * 3600 + ((int)timeCall[3] * 10 + (int)timeCall[4]) * 60 + ((int)timeCall[6] * 10 + (int)timeCall[7]);
    return result;
}

int main() {
    string tmp;
    cin >> tmp;
    while (tmp != "#") {
        cout << count1 << endl;
        cout << tmp << endl;
        string sdt1, sdt2;
        cin >> sdt1 >> sdt2;
        
        if (sdt1.length() != 10) {
            check = 0;
        }
        for (int i = 0; i < 10; i++) {
            if (!(sdt1[i] >= '0' && sdt1[i] <= '9')) {
                check = 0;
                break;
            }
        }
        
        if (sdt2.length() != 10) {
            check = 0;
        }
        for (int i = 0; i < 10; i++) {
            if (!(sdt2[i] >= '0' && sdt2[i] <= '9')) {
                check = 0;
                break;
            }
        }
        
        count1++;
        phoneNumber[sdt1]++;
        
        string day;
        cin >> day;
        string time1, time2;
        cin >> time1 >> time2;
        cin >> tmp;
        
        timePhoneCall[sdt1] += convertHourToSecond(time2) - convertHourToSecond(time1);
    }
    cin >> tmp;
    while (tmp != "#") {
        if (tmp == "?check_phone_number") {
            cout << check << endl;
            cin >> tmp;
            continue;
        }
        if (tmp == "?number_calls_from") {
            string sdt;
            cin >> sdt;
            cout << phoneNumber[sdt] << endl;
            cin >> tmp;
            continue;
        }
        if (tmp == "?number_total_calls") {
            cout << count1 << endl;
            cin >> tmp;
            continue;
        }
        if (tmp == "?count_time_calls_from") {
            string sdt;
            cin >> sdt;
            cout << timePhoneCall[sdt] << endl;
            cin >> tmp;
            continue;
        }
    }
    
    return 0;
}
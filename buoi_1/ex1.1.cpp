#include <bits/stdc++.h>

using namespace std;
typedef struct info{
    int hashed_value;
    int total_call;
    int time_call;
}info;
int hash_time(string s){
    return (s[0]-'0')*36000 + (s[1]-'0')*3600 + (s[3]-'0')*600 + (s[4]-'0')*60 + (s[6]-'0')*10 + (s[7]-'0');
}
int main()
{
    unordered_map<string, pair<int, int>> map_phone_number; //<phone_number, <value, time>>
    unordered_map<string, int> total_called_time;
    int count_phone_number = 0;
    int total_calls = 0;

    bool format_phone_number = true;
    while(1){
        string act, f_number, t_number, date, start_time, end_time;
        cin>>act;
        if(act=="#") break;
        if(act=="call"){
            cin>>f_number>>t_number>>date>>start_time>>end_time;
            if(map_phone_number[f_number].first==0) map_phone_number[f_number].first=++count_phone_number;
            if(map_phone_number[t_number].first==0) map_phone_number[t_number].first=++count_phone_number;
            total_called_time[f_number]+=(hash_time(end_time)-hash_time(start_time));
            total_calls++;
            map_phone_number[f_number].second++;
            if(f_number.length()!=10||t_number.length()!=10) format_phone_number = false;
        }
    }
    for(auto e:total_called_time){
        printf("%d %d\n", e.first, e.second);
    }
    for(auto e:map_phone_number){
        printf("%d %d %d\n", e.first, e.second.first, e.second.second);
    }
    while(1){
        string cmd;
        cin>>cmd;
        if(cmd=="#") break;
        else if(cmd=="?check_phone_number"){
            if(format_phone_number) printf("1\n");
            else printf("0\n");
        }
        else if(cmd=="?number_total_calls"){
            cout<<total_calls<<"\n";
        }
        else if(cmd=="?number_calls_from"){
            string phone_number;
            cin>>phone_number;
            cout<<map_phone_number[phone_number].second<<"\n";
        }
        else if(cmd=="?count_time_calls_from"){
            string phone_number;
            cin>>phone_number;
            cout<<total_called_time[phone_number]<<"\n";
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

    
class Event{
    public:
        string day;
        int start_time;
        int end_time;
        vector<string>users;
        Event(string day,int start_time, int duration, vector<string>users){
            this->day=day;
            this->start_time=start_time;
            this->end_time = start_time+duration;
            this->users = users;
        }
};

class Calendar{
    private:
        string user;
        vector<Event*>events;
    public:
        Calendar(string user){
            this->user = user;
        }
        void addEvent(Event* event){
            events.push_back(event);   
        }
        void showEvents(string day){
            if(events.size()==0)cout<<"none"<<endl;
            for(auto u:events){
                if(u->day==day){
                    cout<<u->start_time<<"-"<<u->end_time<<" ";
                    for(auto k:u->users)cout<<k<<" ";
                    cout<<endl;
                }
            }
        }
};

map<string,Calendar*> user_map;
map<string,vector<Event*>>event_map;


void addUser(string user){
    if(user_map[user]==nullptr){
        Calendar *calendar = new Calendar(user);
        user_map[user]=calendar;
        cout<<"success"<<endl;
    }
    else cout<<"failure"<<endl;
}

bool isOK(string day){
    string yea,dat,mon;
    if(day.size()!=10 || day[4]!='-' || day[7]!='-')return false;
    yea = day.substr(0,4);
    mon = day.substr(5,2);
    dat = day.substr(8,2);
    for(int i=0;i<10;++i){
        if(i!=4 && i!=7){
            if(day[i]>='0' && day[i]<='9'){}
            else return false;
        }
    }
    int month = (mon[0]-'0')*10+(mon[1]-'0');
    int date = (dat[0]-'0')*10+(dat[1]-'0');
    int year = 0;
    for(int i=0;i<yea.size();++i){
        year+=pow(10,3-i)*(yea[i]-'0');
    }
    int status=0; 

    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) && ( date>31 || date<1) )
    {
        status = 3; 
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (date>30 || date<1) )
    {
        status = 4; 
    }
    else if ((month == 2) && (year % 4 == 0) && (date>29 || date<1))
    {
        status = 5; 
    }
    else if ((month == 2) && (year % 4 != 0) && (date>28 || date<1) )
    {
        status = 6; 
    }
    else if ((year < 999) || (year > 10000))
    {
        status = 1;
    }
    if ((month < 1) || (month > 12))
    {
        status = 2;
    }
    return status==0;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        if(s=="add-user"){
            string user;
            cin>>user;
            addUser(user);
        }
        else if(s=="create-event"){
            string day;
            int start_time,duration,no;
            cin>>day>>start_time>>duration>>no;
            vector<string>users(no);
            map<string,int>vis;
            for(int j=0;j<no;++j){
                cin>>users[j];
                vis[users[j]]++;
            }
            if(!isOK(day)){
                cout<<"failure"<<endl;
                continue;
            }
            vector<Event*> eve = event_map[day];
            bool flag = false;
            for(auto u:eve){
                if(u->start_time>=start_time+duration || u->end_time<=start_time){}
                else{
                    for(auto k:u->users){
                        if(vis[k]){
                            cout<<"failure"<<endl;
                            flag=true;
                            break;
                        }
                    }
                }
            }

            if(flag)continue;
            for(auto u:users){
                if(user_map[u]==nullptr){
                    cout<<"failure"<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag)continue;
            
            Event* n_event = new Event(day,start_time,duration,users);
            event_map[day].push_back(n_event);
            for(auto u:users){
                if(user_map[u]!=nullptr)user_map[u]->addEvent(n_event);
                
            }
            
            cout<<"success"<<endl;
           
            
        }
        else if(s=="show-events"){
            string day,user;
            cin>>day>>user;
            if(!isOK(day)){
                cout<<"failure"<<endl;
                continue;
            }
            if(user_map[user]==nullptr){
                cout<<"failure"<<endl;
                continue;
            }
            user_map[user]->showEvents(day);
            
            
        }
        else if(s=="suggest-slot"){
            string day;
            int start_range,end_range,duration,no;
            cin>>day>>start_range>>end_range>>duration>>no;
            if(!isOK(day)){
                cout<<"failure"<<endl;
                continue;
            }
            vector<string>users(no);
            map<string,int>vis;
            for(int j=0;j<no;++j){
                cin>>users[j];
                vis[users[j]]++;
            }
            vector<Event*> eve = event_map[day];
            vector<int>count(1440,0);
            for(auto u:eve){
                int q = 0;
                for(auto k:u->users){
                    if(vis[k]){
                        q=1;
                        break;
                    }
                }
                if(q){
                    for(int j=u->start_time;j<u->end_time;++j){
                        count[j]++;
                    }
                }
            }
            for(int j=start_range;j<end_range;++j){
                if(count[j]==0){
                    cout<<j<<endl;
                    break;
                }
            }
        }
        else{
            cout<<"failure"<<endl;
        }
    }
    return 0;
}

/*
add-user user1
add-user user2
add-user user3
add-user user4
create-event 2021-07-21 600 60 2 user1 user2
create-event 2021-07-21 660 30 2 user1 user3
create-event 2021-07-21 615 60 2 user2 user3
create-event 2021-07-21 660 30 2 user2 user4
show-events 2021-07-21 user1
show-events 2021-07-21 user2
suggest-slot 2021-07-21 570 750 45 2 user1 user2
suggest-slot 2021-07-21 570 700 60 2 user2 user3

*/


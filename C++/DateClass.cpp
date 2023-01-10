#include<iostream>
using namespace std;
class Date{
private:
    int year_;
    int month_;
    int day_;
public:
    void SetDate(int year,int month,int day){
        year_=year;
        month_=month;
        day_=day;
    }
    void AddDay(int inc){
        if(month_==1||month_==3||month_==5||month_==7||month_==8||month_==10||month_==12){
            if((day_+inc)>31){
                day_=(day_+inc)-31;
                month_++;
            }else{
                day_+=inc;
            }
        }else if ((day_+inc)>28 && month_==2){
            month_++;
            day_=day_+inc-29;
        }else{
            if((day_+inc)>30){
                day_=day_+inc-30;
                month_++;
            }else{
                day_+=inc;
            }
        }
    }
    void AddMonth(int inc){
        if(month_+inc>12){
            year_++;
            month_=month_+inc-12;
        }else {
            month_+=inc;
        }
    }
    void AddYear(int inc){
        year_+=inc;

    }
    void ShowDate(){
        cout<<"Today is "<<year_<<":"<<month_<<":"<<day_<<endl;
    }
};
int main(void){
    Date today;
    int y,m,d;
    cout<<"Input Today's Year : ";
    cin>>y;
    cout<<"Input Today's Month : ";
    cin>>m;
    cout<<"Input Today's Day : ";
    cin>>d;
    today.SetDate(y,m,d);
    today.ShowDate();
    today.AddDay(1);
    today.AddMonth(1);
    today.AddYear(0);
    today.ShowDate();
    
    return 0;
}

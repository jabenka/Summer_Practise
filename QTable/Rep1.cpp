#include<QString>
#include<QTextStream>
#include<vector>
using namespace std;
struct Rep1{
    QString Name;
    int Days;
    Rep1(){
        Name="";
        Days=0;
    }
    Rep1(QString mon,int day){
        Name=mon;
        Days=day;
    }
    friend QTextStream& operator >>(QTextStream& in,Rep1& obj){
        obj.Name=in.readLine();
        in>>obj.Days;
        in.readLine();
        return in;
    }
    friend QTextStream& operator<<(QTextStream& out,Rep1& obj){
        out<<obj.Name<<'\n';
        out<<obj.Days<<'\n';
        return out;
    }
};
class Months{
public:
    vector<Rep1> months;
public:
    friend QTextStream& operator>>(QTextStream& in,Months& obj){
        Rep1 k;
        while(!in.atEnd()){
            in>>k;
            obj.months.push_back(k);
        }
        return in;
    }
    friend QTextStream& operator<<(QTextStream& out,Months& obj){
        for(int i=0;i<obj.months.size();i++){
            out<<obj.months[i];
        }
        return out;
    }
};

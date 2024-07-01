#include<Qstring>
#include<vector>
#include<QTextStream>
using namespace std;
struct Rep2{
    QString Name;
    QString Surname;
    int Age;
    Rep2(){
        Name="";
        Surname="";
        Age=0;
    }
    Rep2(QString mon,QString surname,int age){
        Name=mon;
        Surname=surname;
        Age=age;
    }
    friend QTextStream& operator >>(QTextStream& in,Rep2& obj){
        obj.Name=in.readLine();
        obj.Surname=in.readLine();
        in>>obj.Age;
        in.readLine();
        return in;
    }
    friend QTextStream& operator<<(QTextStream& out,Rep2 obj){
        out<<obj.Name<<'\n';
        out<<obj.Surname<<'\n';
        out<<obj.Age<<'\n';
        return out;
    }
};
class Person{
public:
    vector<Rep2> persons;
    int size;
public:
    friend QTextStream& operator>>(QTextStream& in,Person& obj){
        Rep2 temp;
        while(!in.atEnd()){
            in>>temp;
            obj.persons.push_back(temp);
        }
        return in;
    }

    friend QTextStream& operator<<(QTextStream& out,Person obj){
        for(int i=0;i<obj.persons.size();i++){
            out<<obj.persons[i];
        }
        return out;
    }

};




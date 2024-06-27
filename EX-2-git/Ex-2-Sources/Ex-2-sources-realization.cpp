#include <iostream>
#include<cmath>
#include<vector>
#include"Ex-2-sources-headers.h"
using namespace std;


bool Prime::IsPrime(unsigned int a){
        if(a==0){
            return false;
        }
        if(a==1){
            return false;
        }
        if(a==2){
            return true;
        }

        for(int i=2;i<=sqrt(a);i++){
            if(a%i==0){
                return false;
            }
        }
        return true;
    }
vector<unsigned int> Prime::isPrime(unsigned int a){
        vector<unsigned int> res;
        if(IsPrime(a)){
            res.push_back(a);
        }else{
            unsigned int f=a;
            int i=2;
            while(i<=f){
                if(f%i!=0){
                    i++;
                }
                if(f%i==0){

                    res.push_back(i);
                    f/=i;
                }
            }
        }
        return res;
    }





double Sinus::Sin(double x, double eps){
        double sum=x, h; int i=4;
        h=(-1)*(pow(x,3)/6);
        do{
            sum+=h;  //Формула очередного слагаемого
            h*=(-1)*((pow(x,2)/((i)*(i+1))));
            i+=2;}
        while( fabs(h)>eps );
        return sum;
    }


vector<double>Root::Roots(double a,double b,double c){
        double x1, x2, d;
        vector<double> res;
        d = pow(b, 2) - 4 * a * c;
        if (d < 0)
        {

            return res;
        }
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);
        res.push_back(x1);
        res.push_back(x2);
    }

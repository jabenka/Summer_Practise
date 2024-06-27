#include <QtTest>
#include<vector>
#include"../Ex-2-Sources/Ex-2-sources-headers.h"

// add necessary includes here

class Ex_2_tests : public QObject
{
    Q_OBJECT

public:
    Ex_2_tests();
    ~Ex_2_tests();

private slots:

    void test_case1();
    void test_case2();
    void test_case3();
};

Ex_2_tests::Ex_2_tests() {}

Ex_2_tests::~Ex_2_tests() {}


void Ex_2_tests::test_case1() {
    Prime t;
    QCOMPARE(t.IsPrime(7),true);
    QCOMPARE(t.IsPrime(2147483647),true);
    QCOMPARE(t.IsPrime(12),false);


}
void Ex_2_tests::test_case2(){
    Sinus sinus;
    QCOMPARE(sinus.Sin(0,0.001),0);

}
void Ex_2_tests::test_case3(){
    Root r;
    double a=1,b=-5,c=6;
    std::vector<double> res;
    res=r.Roots(a,b,c);
    double n=1.0;
    for(int i=0;i<res.size();i++){
        n*=res[i];
    }
    QCOMPARE(n,6);
}

QTEST_APPLESS_MAIN(Ex_2_tests)

#include "tst_ex_2_tests.moc"

////
//// Created by kenny on 25/08/2020.
////
//
#include <iostream>
#include <string>


#define g(line) a##line
#define f(a) g(a)
#define UNIQ_ID f(__LINE__)

int UNIQ_ID = 5;
int UNIQ_ID = 5;


using namespace std;
int main() {
    int UNIQ_ID = 5;
    string UNIQ_ID = "hello";
}
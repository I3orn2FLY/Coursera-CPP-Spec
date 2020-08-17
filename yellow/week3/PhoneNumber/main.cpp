//
// Created by kenny on 14/08/2020.
//

#include <iostream>
#include "phone_number.h"

/*
 * +7-495-111-22-33
   * +7-495-1112233
   * +323-22-460002
   * +1-2-coursera-cpp
   * 1-2-333 - некорректный номер - не начинается на '+'
   * +7-1233 - некорректный номер - есть только код страны и города
*/
int main() {
//    PhoneNumber phoneNumber("+7-495-111-22-33");
//    PhoneNumber phoneNumber("+1-2-coursera-cpp");
    PhoneNumber phoneNumber("+7-1233");
    cout << phoneNumber.GetCountryCode() << " " << phoneNumber.GetCountryCode() << " " << phoneNumber.GetLocalNumber();
}


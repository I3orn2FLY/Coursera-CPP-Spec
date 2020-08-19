//
// Created by kenny on 18/08/2020.
//

#include <iostream>
#include <string>

using namespace std;

void SendSms(const string &number, const string &message) {
    cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string &email, const string &message) {
    cout << "Send '" << message << "' to e-mail " << email << endl;
}

class INotifier {
public:
    virtual void Notify(const string &message) const = 0;
};

class SmsNotifier : public INotifier {
public:
    explicit SmsNotifier(const string &s) : phone_number_(s) {}

    void Notify(const string &message) const override {
        SendSms(phone_number_, message);
    }

private:
    const string phone_number_;
};

class EmailNotifier : public INotifier {
public:
    explicit EmailNotifier(const string &s) : email_(s) {}

    void Notify(const string &message) const override {
        SendEmail(email_, message);
    }

private:
    const string email_;
};


void Notify(INotifier &notifier, const string &message) {
    notifier.Notify(message);
}


int main() {
    SmsNotifier sms{"+7-495-777-77-77"};
    EmailNotifier email{"na-derevnyu@dedushke.ru"};

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
    return 0;
}
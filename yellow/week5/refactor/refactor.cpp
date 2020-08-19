#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string &name, const string &person_type) : name_(name), person_type_(person_type) {}

    void Walk(const string &destination) const {
        simpleAction("walks to", destination);
        extraWalk();
    }

    string getName() const {
        return name_;
    }

    string getType() const {
        return person_type_;
    }

protected:
    virtual void extraWalk() const {}

    void simpleAction(const string &ac, const string &obj) const {
        cout << who() << " " << ac << ": " << obj << endl;
    }

    void simpleAction(const string &ac) const {
        cout << who() << " " << ac << endl;
    }

    string who() const {
        return person_type_ + ": " + name_;
    }

private:
    const string name_, person_type_;
};

class Student : public Person {
public:

    Student(const string &name, const string &fav_song) : Person(name, "Student"), song_(fav_song) {
    }

    void Learn() const {
        simpleAction("learns");
    }

    void SingSong() const {
        simpleAction("sings a song", song_);
    }

    void extraWalk() const override {
        SingSong();
    }


private:
    const string song_;
};


class Teacher : public Person {
public:

    Teacher(const string &name, const string &subject) : Person(name, "Teacher"), subject_(subject) {
    }

    void Teach() const {
        simpleAction("teaches", subject_);
    }

private:
    const string subject_;
};


class Policeman : public Person {
public:
    Policeman(const string &name) : Person(name, "Policeman") {}

    void Check(const Person &p) const {
        cout << who() << " checks " << p.getType() << ". " << p.getType() << "'s name is: "
             << p.getName() << endl;
    }

};


void VisitPlaces(const Person &person, const vector<string> &places) {
    for (const auto &p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    t.Teach();
    return 0;
}

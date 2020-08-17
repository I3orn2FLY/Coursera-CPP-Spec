#include <iostream>
#include <vector>
#include <map>


using namespace std;
//enum class Lang {
//    DE, FR, IT
//};
//struct Region {
//    string std_name;
//    string parent_std_name;
//    map<Lang, string> names;
//    int64_t population;
//};

int FindMaxRepetitionCount(const vector<Region> &regions) {
    map<tuple<const string &, const string &, const map<Lang, string> &, const int64_t &>, int> m;

    for (const auto &region: regions) {
        auto t = tie(region.std_name, region.parent_std_name, region.names, region.population);
        if (m.count(t)) {
            m[t] += 1;
        } else {
            m[t] = 1;
        }
    }

    int max_rep = 0;

    for (const auto &item: m) {
        max_rep = max(max_rep, item.second);
    }
    return max_rep;


}


int main() {
    cout << FindMaxRepetitionCount({
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           },
                                           {
                                                   "Russia",
                                                   "Eurasia",
                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                   89
                                           },
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           },
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           },
                                           {
                                                   "Russia",
                                                   "Eurasia",
                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                   89
                                           },
                                   }) << endl;

    cout << FindMaxRepetitionCount({
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                                                   89
                                           },
                                           {
                                                   "Russia",
                                                   "Eurasia",
                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"},      {Lang::IT, "Russia"}},
                                                   89
                                           },
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                                                   89
                                           },
                                           {
                                                   "Moscow",
                                                   "Toulouse",
                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                                                   89
                                           },
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"},   {Lang::FR, "Moscou"},      {Lang::IT, "Mosca"}},
                                                   31
                                           },
                                   }) << endl;

    return 0;
}


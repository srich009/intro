//mr evans in SI

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

ostream& operator<<(ostream& out, vector<int>& v) {
    for(int i = 0; i < v.size(); ++i) {
        out << v.at(i) << ' ';
    }
    return out;
}

int main() {
    ifstream fin;
    ofstream fout;
    string fin_name, fout_name;

    cout << "enter input file name: ";
    cin >> fin_name;
    cout << "enter output file name: ";
    cin >> fout_name;

    fin.open(fin_name.c_str());
    if (!fin.is_open()) {
        cerr << fin_name << " was not opened properly" << endl;
        return 1;
    }

    fout.open(fout_name.c_str());
    if (!fout.is_open()) {
        cerr << fout_name << " was not opened properly" << endl;
        return 1;
    }

    int x;
    int max = -1;
    vector<int> v;
    while (fin >> x) {
        if (x < 0) {
            cerr << "encountered a negative number in " << fin_name << endl;
            return 1;
        }
        if (x > max) max = x;
        v.push_back(x);
    }

    // cout << "v: " << v << endl;

    vector<int> count(max+1);
    for(int i = 0; i < v.size(); ++i) {
        count.at(v.at(i))++;
    }

    // cout << "count: " << count << endl;

    for(int i = 0; i < count.size(); ++i) {
        for(int j = 0; j < count.at(i); ++j) {
            fout << i << ' ';
        }
        fout << endl;
    }

    cout << "finished." << endl;

    return 0;
}



/*


goo.gl/BZFKsn


*/
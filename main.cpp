
//assignment 4
// cisc 3130

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;


void CalcBigrams(ifstream&, string, string);
int main()
{
    ifstream file("austen-emma.txt");
    cout << "Enter two words: ";
    string w1, w2;
    cin >> w1 >> w2;

    CalcBigrams(file, w1, w2);

    return 0;
}
std::string normalizeString(const std::string& str) {
std::string res = str;
std::cout << str << " ";
std::transform(res.begin(), res.end(), res.begin(), ::tolower);
res.erase(std::remove_if(res.begin(), res.end(), std::ptr_fun<int,int>(ispunct)), res.end());
std::cout << res << "\n";
return res;
}
void CalcBigrams(ifstream& file, string w1, string w2)
{
    string word1, word2;

    map<pair<string, string>, int> m1;
    map<string, int> m2;
    map<pair<string, string>, double> m3;

    map<pair<string, string>, int>::iterator it1;
    map<string, int>::iterator it2;

    pair<string, string> p;

    // The while loop reads in words unitl it reaches the EOF
    file >> word1;
    while(file)
    {
        file >> word2;
        p = make_pair(word1, word2);
        m1[p]++; // insert m1, or increment int val if key already exists
        m2[word1]++; // insert to m2, or increment int val if key already exists
        word1 = word2; // word2 needs to be re-used as word1 in the next pair
    }

    it1 = m1.begin();
    it2 = m2.begin();
    double prob;

    // keep loop until IT reaches the end
while(it1 != m1.end())
    {
        prob = (1.0*it1->second)/m2[it1->first.first]; //divides the int val of pair with the int val of word1 for pair in m1
       // multiply by 1.0 to make it a double
        m3[it1->first] = prob;  // insert pair of words into map, set the vaue part to prob
        it1++;
    }

    // this statement shows that m1 and m2 are being filled up by correct number
    p = make_pair(w1, w2);
    cout << m1[p] << " / " << m2[w1] << " = " << 1.0*m1[p]/m2[w1] << endl; // prints a decimal number

    cout << m3[p] << endl;

}

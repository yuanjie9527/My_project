#include "Associative_Container.hpp"

#include <vector>
void count_word_number()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        ++word_count[word];
    }

    for (const auto &w : word_count)
    {
        cout << w.first << "occurs" << w.second
             << ((w.second > 1) ? "times" : "time") << endl;
    }
}
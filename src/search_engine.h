#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class SearchEngine {
private:

    // word -> list of documents
    unordered_map<string, vector<string>> invertedIndex;

    // document -> word frequency
    unordered_map<string, unordered_map<string, int>> wordFrequency;

public:
    void indexDocument(string filename);

    void search(string keyword);

    void multiKeywordSearch(string query);

    void booleanSearch(string query);
};

#endif
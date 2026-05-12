#include "search_engine.h"
#include "utils.h"

#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void SearchEngine::indexDocument(string filename) {

    ifstream file(filename);


    if (!file) {
        return;
    }

    string line;

    set<string> uniqueWords;

    while (getline(file, line)) {

        line = toLowerCase(line);
        line = removePunctuation(line);

        vector<string> words = tokenize(line);

        for (string word : words) {

            word = stemWord(word);

            if (isStopWord(word)) {
                continue;
            }

            wordFrequency[filename][word]++;

            uniqueWords.insert(word);
        }
    }

    // Store unique words into inverted index
    for (string word : uniqueWords) {

        invertedIndex[word].push_back(filename);
    }

    file.close();
}

void SearchEngine::search(string keyword) {

    keyword = toLowerCase(keyword);

    if (invertedIndex.find(keyword) == invertedIndex.end()) {

        cout << "\nNo results found.\n";
        return;
    }

    cout << "\nSearch Results:\n";

    for (string file : invertedIndex[keyword]) {

        int frequency = wordFrequency[file][keyword];

        cout << file
             << " | Frequency: "
             << frequency << endl;
    }
}

void SearchEngine::multiKeywordSearch(string query) {

    query = toLowerCase(query);
    query = removePunctuation(query);

    vector<string> keywords = tokenize(query);

    unordered_map<string, int> documentScores;

    for (string keyword : keywords) {

        keyword = stemWord(keyword);

        if (isStopWord(keyword)) {
            continue;
        }

        if (invertedIndex.find(keyword) == invertedIndex.end()) {
            continue;
        }

        for (string file : invertedIndex[keyword]) {

            documentScores[file] += wordFrequency[file][keyword];
        }
    }

    if (documentScores.empty()) {

        cout << "\nNo results found.\n";
        return;
    }

    vector<pair<string, int>> rankedResults;

    for (auto item : documentScores) {

        rankedResults.push_back(item);
    }

    sort(rankedResults.begin(), rankedResults.end(),

        [](pair<string, int> a, pair<string, int> b) {

            return a.second > b.second;
        }
    );

    cout << "\n========================\n";
    cout << "SEARCH RESULTS\n";
    cout << "========================\n";

    for (auto result : rankedResults) {

        cout << result.first
             << " | Score: "
             << result.second << endl;
    }

    cout << "\nResults Found: "
         << rankedResults.size() << endl;
}

void SearchEngine::booleanSearch(string query) {

    query = toLowerCase(query);
    query = removePunctuation(query);

    vector<string> tokens = tokenize(query);

    if (tokens.size() != 3) {

        cout << "\nInvalid Boolean Query Format.\n";
        cout << "Example: ai AND technology\n";

        return;
    }

    string word1 = stemWord(tokens[0]);
    string operation = tokens[1];
    string word2 = stemWord(tokens[2]);

    set<string> resultSet;

    set<string> set1;
    set<string> set2;

    // First word docs
    if (invertedIndex.find(word1) != invertedIndex.end()) {

        for (string file : invertedIndex[word1]) {

            set1.insert(file);
        }
    }

    // Second word docs
    if (invertedIndex.find(word2) != invertedIndex.end()) {

        for (string file : invertedIndex[word2]) {

            set2.insert(file);
        }
    }

    // AND operation
    if (operation == "and") {

        for (string file : set1) {

            if (set2.find(file) != set2.end()) {

                resultSet.insert(file);
            }
        }
    }

    // OR operation
    else if (operation == "or") {

        resultSet = set1;

        for (string file : set2) {

            resultSet.insert(file);
        }
    }

    else {

        cout << "\nOnly AND / OR supported.\n";
        return;
    }

    if (resultSet.empty()) {

        cout << "\nNo results found.\n";
        return;
    }

    cout << "\n========================\n";
    cout << "BOOLEAN SEARCH RESULTS\n";
    cout << "========================\n";

    for (string file : resultSet) {

        cout << file << endl;
    }

    cout << "\nResults Found: "
         << resultSet.size() << endl;
}
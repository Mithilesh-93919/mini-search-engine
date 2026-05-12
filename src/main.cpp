#include "search_engine.h"

#include <iostream>

using namespace std;

int main() {

    SearchEngine engine;
    cout << "====================================\n";
    cout << "       MINI SEARCH ENGINE\n";
    cout << "====================================\n";

    cout << "\nFeatures:\n";
    cout << "- Multi Keyword Search\n";
    cout << "- Boolean Queries (AND / OR)\n";
    cout << "- Relevance Ranking\n";
    cout << "- Stop Word Filtering\n";

    // Index documents
    engine.indexDocument("data/ai.txt");
    engine.indexDocument("data/tech.txt");
    engine.indexDocument("data/sports.txt");
    engine.indexDocument("data/travel.txt");

    string keyword;

    while (true) {

        cout << "\nSearch Query (type exit to quit): ";

        getline(cin, keyword);

 
        if (keyword.empty()) {
            cout<<"\nPlease enter a valid query.\n";
            continue;
        }

        // Boolean Search
        if (keyword.find("AND") != string::npos ||
            keyword.find("OR") != string::npos ||
            keyword.find("and") != string::npos ||
            keyword.find("or") != string::npos) {

            engine.booleanSearch(keyword);
        }

        // Normal Multi-Keyword Search
        else {

            engine.multiKeywordSearch(keyword);
        }
    }

    return 0;
}
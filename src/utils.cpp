#include "utils.h"

#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

string toLowerCase(string text) {

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    return text;
}

string removePunctuation(string text) {

    string cleaned = "";

    for (char ch : text) {

        if (isalnum(ch) || ch == ' ') {

            cleaned += ch;
        }
    }

    return cleaned;
}

vector<string> tokenize(string text) {

    vector<string> words;

    stringstream ss(text);

    string word;

    while (ss >> word) {

        words.push_back(word);
    }

    return words;
}

bool isStopWord(string word) {

    vector<string> stopWords = {

        "the", "is", "a", "an", "and",
        "to", "of", "in", "on", "for",
        "with", "by", "at"
    };

    for (string stopWord : stopWords) {

        if (word == stopWord) {

            return true;
        }
    }

    return false;
}

string stemWord(string word) {

    int length = word.length();

    // Remove 'ing'
    if (length > 4 && word.substr(length - 3) == "ing") {

        return word.substr(0, length - 3);
    }

    // Remove 'ed'
    if (length > 3 && word.substr(length - 2) == "ed") {

        return word.substr(0, length - 2);
    }

    // Remove plural 's'
    if (length > 2 && word[length - 1] == 's') {

        return word.substr(0, length - 1);
    }

    return word;
}
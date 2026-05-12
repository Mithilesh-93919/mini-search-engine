#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using namespace std;

string toLowerCase(string text);

string removePunctuation(string text);

vector<string> tokenize(string text);

bool isStopWord(string word);

string stemWord(string word);

#endif
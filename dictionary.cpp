#include "dictionary.h"
#include <iostream>
#include <algorithm>


Dictionary::Dictionary(std::istream &input) {
    importData(input);
}

Dictionary::~Dictionary() {
    words.clear();
}

void Dictionary::addToDictionary(const std::string &word) {
    if(words.find(word) == words.end())
        words[word] = 1;
    else words[word]++;
    count++;
}

std::string Dictionary::parse(std::istream &input) {
    std::string result;
    while(!input.eof()) {
        int chr = input.get();
        if(isalpha(chr))
            result += (char) tolower(chr);
        else break;
    }
    return result;
}

bool Dictionary::nextWord(std::istream &input) {
    std::string str = parse(input);
    if(!str.length())
        return false;
    addToDictionary(str);
    return true;
}

void Dictionary::importData(std::istream &input) {
    while(!input.eof())
        nextWord(input);
}

void Dictionary::copy(const Dictionary &other_dictionary) {
    for (auto &iter: other_dictionary.words) {
        if(words.find(iter.first) == words.end())
            words[iter.first] = iter.second;
        else words[iter.first] += iter.second;
    }
}

void Dictionary::exportData(std::ostream &output) const {
    auto *arr = new std::pair<std::string, int>[words.size()];
    std::copy(words.begin(), words.end(), arr);
    std::sort(arr, arr + words.size(),
              [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)->bool {
                  if(b.second < a.second) return true;
                  if(a.second < b.second) return false;
                  return a.first.compare(b.first) < 0;
    });
    for(int index = 0; index < words.size(); index++) {
        output.precision(0);
        output << arr[index].first << '\t' << arr[index].second << '\t';
        output.precision(2);
        output << 100. * arr[index].second / count << "%" << '\n';
    }
    delete[] arr;
}
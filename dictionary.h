#ifndef OLYMP_DICTIONARY_H
#define OLYMP_DICTIONARY_H

#include <map>

class Dictionary {
    std::map<std::string, int> words;

    static std::string parse(std::istream &input);
    void addToDictionary(const std::string &word);
public:
    Dictionary();
    explicit Dictionary(std::istream &input);

    ~Dictionary();

    bool nextWord(std::istream &input);
    void readAll(std::istream &input);
    void copy(const Dictionary &other_dictionary);
    void printAll(std::ostream &output) const;
};

#endif //OLYMP_DICTIONARY_H

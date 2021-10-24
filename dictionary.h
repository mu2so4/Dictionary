#ifndef OLYMP_DICTIONARY_H
#define OLYMP_DICTIONARY_H

#include <map>

class Dictionary {
    std::map<std::string, int> words;

    static std::string parse(std::istream &input);
    void addToDictionary(const std::string &word);
public:
    Dictionary() = default;
    explicit Dictionary(std::istream &input);

    ~Dictionary();

    bool nextWord(std::istream &input);
    void importData(std::istream &input);
    void copy(const Dictionary &other_dictionary);
    void exportData(std::ostream &output) const;
};

#endif //OLYMP_DICTIONARY_H

//
// Created by phuch on 5/15/2024.
//

#ifndef ASSETS_ASSETS_H
#define ASSETS_ASSETS_H
#include <string>
using namespace std;

class Assets {
public:
    Assets();
    Assets(const string& name);
    Assets(const Assets& other);
    ~Assets();
    const Assets &operator=(const Assets &other); // data members have a pointer, we need the rule of three
    void AddTag(const string &tag);
    string ToString() const;
private:
    string _name;
    size_t _numberOfTags;
    string* _tags;
};


#endif //ASSETS_ASSETS_H

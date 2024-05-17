//
// Created by phuch on 5/15/2024.
//

#include "Assets.h"
#include <sstream>

Assets::Assets() {
    _numberOfTags = 0;
    _tags = nullptr;
}

Assets::Assets(const string &name) {
    _name = name;
    _numberOfTags = 0;
    _tags = nullptr;
}

Assets::Assets(const Assets &other) {
    _name = other._name;
    _numberOfTags = other._numberOfTags;
    if (_numberOfTags > 0) {
        _tags = new string[_numberOfTags];
        for (size_t i = 0; i < _numberOfTags; i ++) {
            _tags[i] = other._tags[i];
        }
    }
    else {
        _tags = nullptr;
    }
}

Assets::~Assets() {
    delete[] _tags; // because use dynamic location, we should delete it, destructor only delete static location
}

const Assets &Assets::operator=(const Assets &other) {
    if (this != &other) {
        delete[] _tags;
        _name = other._name;
        _numberOfTags = other._numberOfTags;
        _tags = new string[_numberOfTags];
        for (size_t i = 0; i < _numberOfTags; i++) {
            _tags[i] = other._tags[i];
        }

    }
    else
        _tags = nullptr;
    return *this;
}

void Assets::AddTag(const string &tag) {
    _numberOfTags++;
    string* temp = new string[_numberOfTags];
    for(size_t i = 0; i < _numberOfTags - 1; i++) {
        temp[i] = _tags[i];
    }
    temp[_numberOfTags-1] = tag;
    delete[] _tags;
    _tags = new string[_numberOfTags];
    for (size_t i = 0; i < _numberOfTags; i++) {
        _tags[i] = temp[i];
    }
    delete[] temp;
}

string Assets::ToString() const {
    stringstream sstrm;
    sstrm << "{\"name\":\"" << _name << "\", "
            << "\"numberofTags\":\"" << _numberOfTags << "\","
            << "\"Tags\":";
    for (size_t i = 0; i < _numberOfTags; i++) {
        sstrm << _tags[i] << ";";
    }
    sstrm << "}";
    return sstrm.str();
}





//
// Created by Kaitlyn Archambault on 2023-01-14.
//

#ifndef ASSIGN1_CPPTOHTML_H
#define ASSIGN1_CPPTOHTML_H

#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

void convertFile(string, string);
bool fileValidation(string);

struct MyFileValidationException : public exception {
public:
    const string what() {
        return "Failed file format validation.";
    }
};

#endif //ASSIGN1_CPPTOHTML_H

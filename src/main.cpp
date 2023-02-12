//
// Created by Kaitlyn Archambault on 2023-02-02.
//

#include "../inc/cpptohtml.h"

int main() {

    string cppFileName;
    string htmlFileName;
    bool validFile;

    cout << "Welcome to .cpp to HTML Converter!\n" << endl;

    cout << "The source .cpp file is OriginalCPP.cpp" << endl;
    cppFileName = "../OriginalCPP.cpp";

    //ideally I wouldn't wrap the do while loop in a try catch,
    //but I wasn't sure where else to implement my custom exception
    try {

        do {

            cout
            << "Enter the desired name for the converted .html file using the following format: fullpath/your_filename.html"
            << endl;
            cin >> htmlFileName;
            //validate file format
            if (fileValidation(htmlFileName)) {

                validFile = true;
            } else {

                throw MyFileValidationException();
            }

        } while (!validFile);

    } catch (MyFileValidationException &e) {

        cout << e.what();
    }
    //if a valid format, proceed, else prompt again

    try {

        convertFile(cppFileName, htmlFileName);

    } catch (exception &e) {

        cout << e.what() << endl;
    }
    return 0;
}
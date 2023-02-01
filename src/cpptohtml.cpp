//created by Kaitlyn Archambault
//Jan 14 2023

#include "../inc/cpptohtml.h"

int main() {

    string cppFileName;
    string htmlFileName;
    bool validFile;

    cout << "Welcome to .cpp to HTML Converter!\n" << endl;

    do {
        cout << "Enter a .cpp source file to convert using the following format: drive:fullpath/filename.cpp" << endl;
        //add validation
        cin >> cppFileName;

        //validate file format
        if (fileValidation(cppFileName)) {
            validFile = fileValidation(cppFileName); //or = true
        } else {
            cout << "Invalid entry, follow the provided format.";
        }
    } while (!validFile);
    //if a valid format, proceed, else prompt again

    cout << "Enter the desired name for the converted .txt file using the following format: fullpath/your_filename.txt" << endl;
    cin >> htmlFileName;
    //validate file name

    convertFile(cppFileName, htmlFileName);

    cout << "Conversion Finished" << endl;

    return 0;
}

//validation method for entered file name
bool fileValidation(string fileName) {

    //rename:
    //change to be relative file path since you're on a mac and your life is harder
    regex filePath("[a-zA-Z]:[\\\/](?:[a-zA-Z0-9]+[\\\/])*([a-zA-Z0-9]+\.txt)");

    //below regex found at: https://stackoverflow.com/questions/37747139/regex-for-windows-path by user dryairship
    return ( regex_match(fileName, filePath) );
}

//method to open file for reading
void convertFile(string cppFileName, string htmlFileName) {

    string line;
    //char ch; //for writing file

    //create ifstream object
    ifstream cpp_file {
            cppFileName
    };

    //ofstream will create the file as well as the ofstream object
    ofstream html_file {
            htmlFileName
    };

    if (cpp_file && html_file) {

        //add tag to beginning of file
        html_file << "<PRE>";
        //check contents of original cpp file line by line to preserve newlines,
        //then char by char to convert special characters (<,>)
        while (getline(cpp_file, line)) {

            for (char ch : line) {
                if (ch == '<') {
                    html_file << "&lt;";
                } else if  (ch == '>') {
                    html_file << "&gt;";
                } else {
                    html_file << ch;
                }
            }
            //move to the next line
            html_file << endl;
        }

        //add tag to end of file
        html_file << "</PRE>";

    } else {

        printf("Error converting file");
    }
}
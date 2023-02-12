//created by Kaitlyn Archambault
//Jan 14 2023

#include "../inc/cpptohtml.h"

//validation method for entered file name
bool fileValidation(string fileName) {

    //this is a relative file path because I'm writing and testing on a mac
    regex filePath(R"(\/?\~?\/?([a-zA-Z0-9_-]+[\/])+([a-zA-Z0-9_-])+\.html)");

    return (regex_match(fileName, filePath));
}

//method to open file for reading
void convertFile(string cppFileName, string htmlFileName) {

    string line;

    ifstream cpp_file;
    ofstream html_file;

    //the below code defines how the ifstream object will behave with exceptions:
    //failbit will indicate a logical error opening the file, badbit will indicate a read/write error
    //cpp_file.exceptions(ifstream::failbit | ifstream::badbit);
    //html_file.exceptions(ofstream::failbit | ofstream::badbit);

    try {

        cpp_file.open(cppFileName);
        html_file.open(htmlFileName);

        if (cpp_file.fail()) {

            cout << "Could not open cpp file.";
        } else if (html_file.fail()) {

            cout << "Could not open destination file.";
        } else {

            //add tag to beginning of file
            html_file << "<PRE>" << endl;

            //check contents of original cpp file line by line to preserve newlines,
            //then char by char to convert special characters (<,>)
            while (getline(cpp_file, line)) {

                for (char ch: line) {
                    if (ch == '<') {
                        html_file << "&lt;";
                    } else if (ch == '>') {
                        html_file << "&gt;";
                    } else {
                        html_file << ch;
                    }
                }

                //move to the next line
                html_file << endl;
            }
            cpp_file.close();

            //add tag to end of file
            html_file << "</PRE>";

            html_file.close();
            cout << "Conversion Finished" << endl;
        }

    } catch (ifstream::failure &e) {

        cout<<"Exception opening/closing/reading source cpp file"<<endl;

    } catch (ofstream::failure &e) {

        cout<<"Exception opening/closing/writing html file"<<endl;

    } catch (exception &e) {

        e.what();
    }
}
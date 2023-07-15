#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> conversions = {
    {"int main()", "int main() // Main Function"},
    {"#include", "Include Header "},
    {"using", "Use"},
    {";", "."},
    {"<<", " "},
    {">>", " "},
    {"[", " as array of "},
    {"]", " elements"},
    {"int ","Set Integer "},
    {"long long "," Set Long Long "},
    {"float "," Set Floating point "},
    {"double ","Set Double Floating point "},
    {"bool ","Set Boolean "},
    {"char ","Set Character "},
    {"string ","Set String "},
    {"<int>"," of Type Integer"},
    {"<long long>","of Type Long Long"},
    {"<float>"," of Type Floating point"},
    {"<double>","of Type Double Floating point"},
    {"<bool>","of Type Boolean"},
    {"<char>","of Type Character"},
    {"<string>","of Type String"},
    {"void","Void"},
    {"for", "For"},
    {"while", "While"},
    {"=", " Equal to "},
    {"+", " Plus "},
    {"-", " Minus "},
    {"*", " Multiplied to "},
    {"/", " Divided by "},
    {"==", " Equals "},
    {"'\n'"," and go to next line "},
    {"class", "Define Class "},
    {"if", "If "},
    {"else:", "Else "},
    {"else if", "ElseIf "},
    {"try:", "Try "},
    {"catch", "Catch"},
    {"throw", "Throw"},
    {"switch", "Switch "},
    {"case", "Case "},
    {"default", "Default Case "},
    {"continue", "Continue"},
    {"break", "Break"},
    {"do", "Do"},
    {"typedef", "Define"},
    {"struct", "Define Struct"},
    {"enum", "Define Enum"},
    {"const", "Constant"},
    {"static", "Static"},
    {"virtual", "Virtual"},
    {"namespace", "Namespace"},
    {"template", "Template"},
    {"typename", "Typename"},
    {"public", "Public"},
    {"private", "Private"},
    {"protected", "Protected"},
    {"sizeof", "Sizeof"},
    {"new", "New"},
    {"delete", "Delete"},
    {"nullptr", "Null"},
    {"this", "This"},
    {"friend", "Friend"},
    {"inline", "Inline"},
    {"operator", "Operator"},
    {"explicit", "Explicit"},
    {"volatile", "Volatile"},
    {"mutable", "Mutable"},
    {"throw", "Throw"},
    {"typeid", "Typeid"},
    {"reinterpret_cast", "Reinterpret Cast"},
    {"dynamic_cast", "Dynamic Cast"},
    {"static_cast", "Static Cast"},
    {"const_cast", "Const Cast"},
    {"cout", "Print"},
    {"cin", "Input"},
    {"endl", "End Line"},
    {"cerr", "Error Print"}
};

set<string> variables;

string convertToPseudocode(const string& cppCode)
{
    stringstream ss(cppCode);
    string line;
    vector<string> convertedLines;

    while (getline(ss, line))
    {
        string convertedLine = line;

        for (const auto& rule : conversions)
        {
            size_t pos = convertedLine.find(rule.first);
            while (pos != string::npos)
            {
                convertedLine.replace(pos, rule.first.length(), rule.second);
                pos = convertedLine.find(rule.first, pos + rule.second.length());
            }
        }

        convertedLines.push_back(convertedLine);
    }

    string pseudocode = accumulate(convertedLines.begin(), convertedLines.end(), string{},
        [](const string& a, const string& b) {
            return a.empty() ? b : a + "\n" + b;
        });

    return pseudocode;
}


int main()
{
    string cppFilename = "input.cpp";     // Name of the input C++ file
    string outputFilename = "output.txt"; // Name of the output file

    ifstream inputFile(cppFilename);
    if (!inputFile)
    {
        cerr << "Failed to open input file: " << cppFilename << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string cppCode = buffer.str();

    string pseudocode = convertToPseudocode(cppCode);

    ofstream outputFile(outputFilename);
    if (!outputFile)
    {
        cerr << "Failed to open output file: " << outputFilename << endl;
        return 1;
    }

    outputFile << pseudocode;
    outputFile.close();

    cout << "Conversion complete. Pseudocode written to " << outputFilename << endl;

    return 0;
}
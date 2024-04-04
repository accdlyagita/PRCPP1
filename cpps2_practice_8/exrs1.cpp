#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string values;
    getline(cin, values);

    string templateStr;
    getline(cin, templateStr);

    unordered_map<string, string> valueMap;
    size_t pos = 0;
    while (pos < values.length()) {
        size_t delimPos = values.find(',', pos);
        string pair = values.substr(pos, delimPos - pos);
        size_t equalPos = pair.find('=');
        if (equalPos != string::npos) {
            string name = pair.substr(0, equalPos);
            string value = pair.substr(equalPos + 1);
            valueMap[name] = value;
        }
        pos = delimPos != string::npos ? delimPos + 1 : values.length();
    }

    pos = 0;
    while (pos < templateStr.length()) {
        size_t openBracket = templateStr.find('[', pos);
        if (openBracket == string::npos) {
            break;
        }
        size_t closeBracket = templateStr.find(']', openBracket);
        if (closeBracket == string::npos) {
            break;
        }
        string placeholder = templateStr.substr(openBracket + 1, closeBracket - openBracket - 1);
        auto it = valueMap.find(placeholder);
        if (it != valueMap.end()) {
            templateStr.replace(openBracket, closeBracket - openBracket + 1, it->second);
        }
        pos = closeBracket + 1;
    }

    cout << templateStr << endl;

    return 0;
}

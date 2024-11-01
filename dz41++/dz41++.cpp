#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void addWord(map<string, string>& dictionary) {
    string word, definition;
    cout << "Enter a word: ";
    cin >> word;
    cout << "Enter a definition: ";
    cin.ignore();
    getline(cin, definition);
    dictionary[word] = definition;
    cout << "The word has been added\n";
}

void searchWord(const map<string, string>& dictionary) {
    string word;
    cout << "Enter a search word: ";
    cin >> word;
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        cout << "Found: " << word << " - " << it->second << endl;
    }
    else {
        cout << "Word not found\n";
    }
}

void deleteWord(map<string, string>& dictionary) {
    string word;
    cout << "Enter the word to delete: ";
    cin >> word;
    if (dictionary.erase(word)) {
        cout << "Word deleted\n";
    }
    else {
        cout << "Word not found\n";
    }
}

void saveToFile(const map<string, string>& dictionary) {
    ofstream file("dictionary.txt");
    for (const auto& entry : dictionary) {
        file << entry.first << ":" << entry.second << endl;
    }
    cout << "The dictionary is saved to a file 'dictionary.txt'.\n";
}

void loadFromFile(map<string, string>& dictionary) {
    ifstream file("dictionary.txt");
    dictionary.clear();
    string line;
    while (getline(file, line)) {
        size_t delimiterPos = line.find(":");
        if (delimiterPos != string::npos) {
            string word = line.substr(0, delimiterPos);
            string definition = line.substr(delimiterPos + 1);
            dictionary[word] = definition;
        }
    }
    cout << "The dictionary is loaded from the file 'dictionary.txt'.\n";
}

int main() {
    map<string, string> dictionary;
    int choice;

    while (true) {
        cout << "\n1. Add a word\n2. Search for a word\n3. Delete the word\n4. Save to file\n5. Download from file\n0. Exit\n";
        cout << "Select the option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addWord(dictionary);
            break;
        case 2:
            searchWord(dictionary);
            break;
        case 3:
            deleteWord(dictionary);
            break;
        case 4:
            saveToFile(dictionary);
            break;
        case 5:
            loadFromFile(dictionary);
            break;
        case 0:
            cout << "Exit the program\n";
            return 0;
        default:
            cout << "Wrong choice\n";
        }
    }
}

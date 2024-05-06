/*The dictionary file consists of a list of more than 100 correctly spelt lowercase
words,separated by whitespace. The words are inserted into the hash table. Handle
collision using separate chaining. After the reading of the dictionary file is
complete, the program prompts the user for input. After input is obtained, each word
that the user enters into the program is looked up within the hash table to see if
it exists. If the entered word exists within the hash table, then that word is spelt
correctly. */

#include <bits/stdc++.h>
using namespace std;
const int SIZE = 26;

int hashfunction(const string &key)
{
    char firstchar = key[0];
    if (firstchar >= 'a' && firstchar <= 'z')
        return (firstchar - 'a');
    return -1;
}

void insert(vector<vector<pair<string, bool>>> &table, string &key)
{
    int index = hashfunction(key);
    if (index != -1)
        table[index].push_back({key, true});
    else
        cout << "invalid word " << key << endl;
}

bool search(vector<vector<pair<string, bool>>> &table, string &key)
{
    int index = hashfunction(key);
    if (index != -1)
    {
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->first == key)
            {
                cout << "Word found" << endl;
                return true;
            }
        }
    }
    cout << "No such word !!" << endl;
    return false;
}

void display(vector<vector<pair<string, bool>>> &table)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Bucket " << static_cast<char>(i + 'a') << " : ";
        
        for (auto it = table[i].begin(); it != table[i].end(); ++it)
        {
            cout << it->first << " "; // Access the word (first element of the pair)
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<pair<string, bool>>> table(SIZE);
    ifstream file("dict.txt");
    if (!file)
    {
        cerr << "error opening file" << endl;
    }
    string word;
    while (file >> word)
    {
        insert(table, word);
    }
    int choice;
    string userInput;
    while (choice != 3)
    {
        cout << "\nMenu:\n";
        cout << "1. Check Spelling\n";
        cout << "2. Display Hash Table\n";
        cout << "3. Exit\n";
        cout << "4. Insert word\n";
        cout << "5. Search word\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter word to check spelling: ";
            cin >> userInput;
            if (search(table, userInput))
            {
                cout << "Correct spelling.\n";
            }
            else
            {
                cout << "Incorrect spelling.\n";
            }
            break;
        case 2:
            cout << "Hash Table:\n";
            display(table);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        case 4:
            cout << "Enter word to insert: ";
            cin >> userInput;
            insert(table, userInput); // Call the insert function
            break;
        case 5:
            cout << "Enter word to search: ";
            cin >> userInput;
            search(table, userInput); // Call the insert function
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
    return 0;
}
/*
Will Garlington
CPSC 121. April 14, 2022
*/

#include "decoder.h"

/*
input: N/A
return; N/A
*/
void encrypt1(){
    vector<vector<char>> reverso {{'a','2'},{'b','-'},{'c','/'},{'d','3'},{'e','8'},{'f','1'},{'g','p'},
                                    {'h','9'},{'i','7'},{'j','5'},{'k','j'},{'l','v'},{'m','b'},{'n','.'},
                                    {'o','&'},{'p','x'},{'q','4'},{'r','n'},{'s','f'},{'t','6'},{'u',','},
                                    {'v','a'},{'w','o'},{'x','c'},{'y','?'},{'z','#'},{'0','h'},{'1','e'},
                                    {'2',';'},{'3','z'},{'4',' '},{'5',':'},{'6','"'},{'7','$'},{'8','g'},
                                    {'9','k'},{'!','m'},{'?','\''},{'.','0'},{',','q'},{'-','w'},{'/','i'},
                                    {'(','l'},{')','!'},{'#',')'},{'$','s'},{'"','t'},{' ','u'},{'&','y'},
                                    {';','r'},{':','('},{'\'','d'}
                                    };
    char inChar;
    int ticker = 0;
    string inLine;
    ifstream inFile;
    ofstream outFile;
    string fileName;
    
    cout << "Please input filename (ex. file.txt):" << endl;
    cin >> fileName;
    
    inFile.open(fileName);
    outFile.open("PA8encrypted1.txt");
    
    while (getline(inFile, inLine)){
        for (char character : inLine){
            character = tolower(character);
            for (int i = 0; i < reverso.size(); i++){
                if (reverso[i][0] == character){
                    character = reverso[i][1];
                    outFile << character;
                    break;
                }
            }
        }
        outFile << endl;
    }
    inFile.close();
    outFile.close();
}

/*
input: N/A
return: N/A
*/
void decrypt1(){
    vector<vector<char>> reverso {{'a','2'},{'b','-'},{'c','/'},{'d','3'},{'e','8'},{'f','1'},{'g','p'},
                                    {'h','9'},{'i','7'},{'j','5'},{'k','j'},{'l','v'},{'m','b'},{'n','.'},
                                    {'o','&'},{'p','x'},{'q','4'},{'r','n'},{'s','f'},{'t','6'},{'u',','},
                                    {'v','a'},{'w','o'},{'x','c'},{'y','?'},{'z','#'},{'0','h'},{'1','e'},
                                    {'2',';'},{'3','z'},{'4',' '},{'5',':'},{'6','"'},{'7','$'},{'8','g'},
                                    {'9','k'},{'!','m'},{'?','\''},{'.','0'},{',','q'},{'-','w'},{'/','i'},
                                    {'(','l'},{')','!'},{'#',')'},{'$','s'},{'"','t'},{' ','u'},{'&','y'},
                                    {';','r'},{':','('},{'\'','d'}
                                    };
    char inChar;
    int ticker = 0;
    string inLine;
    ifstream inFile;
    ofstream outFile;
    
    cout << "decrypting" << endl;
   
    inFile.open("PA8encrypted1.txt");
    outFile.open("PA8decrypted1.txt");
    
    while (getline(inFile, inLine)){
        for (char character : inLine){
            character = tolower(character);
            for (int i = 0; i < reverso.size(); i++){
                if (reverso[i][1] == character){
                    character = reverso[i][0];
                    outFile << character;
                    break;
                }
            }
        }
        outFile << endl;
    }
    inFile.close();
    outFile.close();
}

/*
input: N/A
return: N/A
*/
void encrypt2(){
    vector<vector<char>> A1 {{'a','b','c','d','e','f'},
                            {'g','h','i','j','k','l'},
                            {'m','n','o','p','q','r'},
                            {'s','t','u','v','w','x'},
                            {'y','z','!','?','.',','},
                            {'(',')','"','/',':',' '}};
    vector<vector<char>> A2 {{'h','q','/','n','k','r'},
                            {'a','c','u','o','"','t'},
                            {'s','l','f','b','(','v'},
                            {'p','x',':','m','g','?'},
                            {'i','!','z','j','e','y'},
                            {'d',' ',',','w',')','.'}};
    vector<vector<char>> B1 {{'h','q','/','n','k','r'},
                            {'a','c','u','o','"','t'},
                            {'s','l','f','b','(','v'},
                            {'p','x',':','m','g','?'},
                            {'i','!','z','j','e','y'},
                            {'d',' ',',','w',')','.'}};
    vector<vector<char>> B2 {{'a','b','c','d','e','f'},
                            {'g','h','i','j','k','l'},
                            {'m','n','o','p','q','r'},
                            {'s','t','u','v','w','x'},
                            {'y','z','!','?','.',','},
                            {'(',')','"','/',':',' '}};
    ifstream inFile;
    ofstream outFile;
    vector<char> inStore;
    string inLine;
    int row1 = 0; int row2 = 0; 
    int col1 = 0; int col2 = 0; 
    int err1 = 0; int err2 = 0;
    int ticker;
    int halfLine;
    string fileName;
    
    cout << "Please input filename (ex. file.txt):" << endl;
    cin >> fileName;
    
    inFile.open(fileName);
    outFile.open("PA8encrypted2.txt");
    
    while (getline(inFile, inLine)){
        ticker = 0;
        inStore.clear();
        for (char character : inLine){
            character = tolower(character);
            inStore.push_back(character);
        }
        if (inStore.size() % 2 != 0){
            inStore.push_back(' ');
        }
        halfLine = inStore.size() / 2;
        for (int i = 0; i < halfLine; i++){
            err1 = 1; err2 = 1;
            for (int j = 0; j < 6; j++){
                for (int k = 0; k < 6; k++){
                    if (inStore[ticker] == A1[j][k]){
                        row1 = j;
                        col2 = k;
                        err1 = 0;
                        break;
                    }
                    if (err1 == 0){
                        break;
                    }
                }
            }
            ticker++;
            for (int j = 0; j < 6; j++){
                for (int k = 0; k < 6; k++){
                    if (inStore[ticker] == B2[j][k]){
                        row2 = j;
                        col1 = k;
                        err2 = 0;
                        break;
                    }
                    if (err2 == 0){
                        break;
                    }
                }
            }
            ticker++;
            if (err1 == 0){
                outFile << A2[row1][col1];
            }
            else {
                outFile << '#';
            }
            if (err2 == 0){
                outFile << B1[row2][col2];
            }
            else {
                outFile << '#';
            }
        }
        outFile << endl;
    }
    outFile.close();
    inFile.close();
}

/*
input: N/A
return: N/A
*/
void decrypt2(){
    vector<vector<char>> A1 {{'a','b','c','d','e','f'},
                            {'g','h','i','j','k','l'},
                            {'m','n','o','p','q','r'},
                            {'s','t','u','v','w','x'},
                            {'y','z','!','?','.',','},
                            {'(',')','"','/',':',' '}};
    vector<vector<char>> A2 {{'h','q','/','n','k','r'},
                            {'a','c','u','o','"','t'},
                            {'s','l','f','b','(','v'},
                            {'p','x',':','m','g','?'},
                            {'i','!','z','j','e','y'},
                            {'d',' ',',','w',')','.'}};
    vector<vector<char>> B1 {{'h','q','/','n','k','r'},
                            {'a','c','u','o','"','t'},
                            {'s','l','f','b','(','v'},
                            {'p','x',':','m','g','?'},
                            {'i','!','z','j','e','y'},
                            {'d',' ',',','w',')','.'}};
    vector<vector<char>> B2 {{'a','b','c','d','e','f'},
                            {'g','h','i','j','k','l'},
                            {'m','n','o','p','q','r'},
                            {'s','t','u','v','w','x'},
                            {'y','z','!','?','.',','},
                            {'(',')','"','/',':',' '}};
    ifstream inFile;
    ofstream outFile;
    vector<char> inStore;
    string inLine;
    int row1 = 0; int row2 = 0;
    int col1 = 0; int col2 = 0;
    int err1 = 0; int err2 = 0;
    int ticker;
    int halfLine;
    
    inFile.open("PA8encrypted2.txt");
    outFile.open("PA8decrypted2.txt");
    
    while (getline(inFile, inLine)){
        ticker = 0;
        inStore.clear();
        for (char character : inLine){
            character = tolower(character);
            inStore.push_back(character);
        }
        if (inStore.size() % 2 != 0){
            inStore.push_back(' ');
        }
        halfLine = inStore.size() / 2;

        for (int i = 0; i < halfLine; i++){
            err1 = 1; err2 = 1;
            for (int j = 0; j < 6; j++){
                for (int k = 0; k < 6; k++){
                    if (inStore[ticker] == A2[j][k]){
                        row1 = j;
                        col2 = k;
                        err1 = 0;
                        break;
                    }
                    if (err1 == 0){
                        break;
                    }
                }
            }
            ticker++;
            for (int j = 0; j < 6; j++){
                for (int k = 0; k < 6; k++){
                    if (inStore[ticker] == B1[j][k]){
                        row2 = j;
                        col1 = k;
                        err2 = 0;
                        break;
                    }
                    if (err2 == 0){
                        break;
                    }
                }
            }
            ticker++;
            if (err1 == 0){
                outFile << A1[row1][col1];
            }
            else {
                outFile << '#';
            }
            if (err2 == 0){
                outFile << B2[row2][col2];
            }
            else {
                outFile << '#';
            }
        }
        outFile << endl;
    }
    outFile.close();
    inFile.close();
}

/*
input: vector of vectors of chars
return: N/A
*/
void printVec(vector<vector<char>> inVec){
    for (int i = 0; i < inVec.size(); i++){
        for (int j = 0; j < inVec[i].size(); j++){
            cout << inVec[i][j];
        }
        cout << "|";
    }
    cout << endl;
}

/*
input: vector of chars
return: N/A
*/
void printVec(vector<char> inVec){
    for (int i = 0; i < inVec.size(); i++){
        cout << inVec[i] << " ";
    }
    cout << endl;
}
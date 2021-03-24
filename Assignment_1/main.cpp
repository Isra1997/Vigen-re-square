//
//  main.cpp
//  Assignment_1
//
//  Created by Isra Ragheb on 3/23/21.
//

#include <iostream>
using namespace std;


int EncryptionIndex(char OrignalText, char Key){
    int start_small = 98;
    int start_Capital = 64;
    
    int indexOriginal = int(OrignalText) - start_small;
    int indexKey = int(Key)- start_Capital;
    
    int encryptIndex = start_Capital+((indexOriginal+indexKey) % 26)+1;
    
    return encryptIndex;
}

int main() {
    string originalText;
    string Key;
    string encryptedText;
    // index to access the key
    int j=-1;
    
    //get the original text frm the user
    cout << "Please enter the orignal text from (a-z)";
    if(!(getline(cin,originalText))){
        cerr << "Incorrect Input";
        exit(1);
    }
    
    //get the key from the user
    cout << "Please enter the Key from (A-Z)";
    if(!(cin>>Key)){
        cerr << "Incorrect Input";
        exit(1);
    }

 
    cin.get();
    cin.sync();
    //loop on each character and encrypt it
    for(int i=0; i<originalText.length();i++){
        if(originalText[i]==' '){
            j=0;
            continue;
        }else if(i==Key.length()-1){
            j=0;
        }else{
            j++;
        }
        char x = originalText[i];
        char y = Key[j];
    
        cout << (char)EncryptionIndex(x, y);
    }
    
    return 0;
}


#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define MIN 15
#define MAX 18

int searchFile(std::string website, std::string username){
    std::ifstream fileInput;
    std::string line;
    fileInput.open("saved.txt");

    unsigned int lineNumber = 0;
    while(getline(fileInput, line)) { 
        lineNumber++;
        if (line.find(website, 0) != std::string::npos) {
            std::cout << "found: " << website << "line: " << lineNumber << std::endl;
            std::cout<<line;
            return lineNumber;
        }
    }
    return -1;
}

void savePassword(std::string website,std::string username, std::string password) {
    std::fstream myfile;
    std::ifstream fileInput;
    std::string line;
    std::vector<std::string> fileVector;
    fileInput.open("saved.txt");

    while(!fileInput.eof()){
        std::getline(fileInput, line);
        fileVector.push_back(line);
    }

    for( auto fileLine : fileVector){
        std::cout<<fileLine <<"\n";
    }

   /* unsigned int lineNumber = 0;
    while(getline(fileInput, line)) { 
        lineNumber++;
        if (line.find(website, 0) != std::string::npos) {
            std::cout << "found: " << website << "line: " << lineNumber << std::endl;
        }
    }
    if (lineNumber == -1) {
        myfile.open("saved.txt" ,std::ios::app);
        myfile << website << "\t{\n" <<  username << ":" << password << "\n}\n" << std::endl;
        myfile.close();
        std::cout<<"Saving Password";
        return ;
    }
    else {
        myfile.open("saved.txt", std::ios::app);
        myfile.seekp(--lineNumber); 
        myfile.(username);
        myfile.close();
    }
    */
}


std::string generatePassword() {
    std::string password;
    srand(std::time(0));

    std::string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string small = "abcdefghijklmnopqrstuvwxyz";
    std::string nums = "1234567890";
    std::string sc = "!@#$%^&*";

    int length = rand() % (MAX - MIN + 1) + MIN; 

    for(int i = 0; i<length ; i++ ) {
        int selectSet = rand() % 5 + 1;
        switch (selectSet) {
            case 1 : {
                         int selectIndex  = rand() % 26 + 1;
                         password.push_back(caps[selectIndex]);
                         break;
                     }
            case 2 : { 
                         int selectIndex  = rand() % 26 + 1;
                         password.push_back(small[selectIndex]);
                         break;
                     }
            case 3 : { 
                         int selectIndex = rand() % 10 + 1;
                         password.push_back(nums[selectIndex]);
                         break;
                     }
            case 4 : {
                         int selectIndex  = rand() % 8 + 1;
                         password.push_back(sc[selectIndex]);
                         break;
                     }
        }
    }

    return password;
}

void newPassword() {
    std::string website;
    std::string username;
    std::string option;
    std::string password;

    std::cout<<"What website are you creating an account in? ";
    std::cin>>website;
    std::cout<<"Username/Email-id : ";
    std::cin>>username;
    std::cout<<"Do you generate password ? [y/n] \n";
    std::cin >> option;
    if ( option == "n" ) {
        std::cout<<"Enter the password to be saved : \n";
        std::cin>>password;
        savePassword(website, username, password);
    }
    else if(option == "y"){
        password = generatePassword();
        std::cout<<"The Generated Password is : " + password + "\n";
        savePassword(website, username, password);
    }  
    else
        std::cout<<"Incorrect Option \n";
}

void showLoginDetails(std::string website, std::string username){
    std::cout<<"Showing Login Details for:" + username + "in" + website;
    searchFile(website, username);
}

void help(){
    std::cout<<"Helping";
}

int main(int argc,char *argv[]){
    for (int i = 1 ; i < argc; i++) {
        /*switch(argv[1]) {
            case "n" : newPassword();
                       break;
            case "leg" : showLoginDetails(argv[2], argv[3]);
                       break;
            default : help();
                      break;
        }*/
        if(strcmp(argv[1], "-n") == 0){
            newPassword();
            break;
        }
        else if(strcmp(argv[1], "-l") == 0) {
            showLoginDetails(argv[2],argv[3]);
            break;
        }
        else {
            help();
            break;
        }
    }
    std::cout<<"Hello World";
    return 0;
}

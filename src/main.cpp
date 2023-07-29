#include <cctype>
#include <iostream>
#include <string>

void savePassword(std::string password) {
    std::cout<<"Saving Password";
}

std::string generatePassword() {
    return "This";
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
        savePassword(password);
    }
    else if(option == "y")
        std::cout<<"The Generated Password is : " + generatePassword();
        
    else
        std::cout<<"Incorrect Option \n";
}

void showLoginDetails(){
    std::cout<<"Showing Loign Details for:";
}

void help(){
    std::cout<<"Helping";
}

int main(int argc,char *argv[]){
    for (int i = 1 ; i < argc; i++) {
        switch(*argv[i]) {
            case 'n' : newPassword();
                       break;
            case 'l' : showLoginDetails();
                       break;
            default : help();
                      break;
        }
    }
    std::cout<<"Hello World";
    return 0;
}

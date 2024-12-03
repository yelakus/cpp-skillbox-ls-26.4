#include <iostream>
#include <vector>
#include <string>
#include <limits> 

class Contact{
    public:
    std::string name;
    std::string number;

    Contact(const std::string& name, const std::string& number)
    : name(name), number(number) {}
};

class Phone{
    std::vector<Contact> contacts;

    public:

    void addContact(){
        std::string name, number;
        std::cout << "Enter contact's name:" << std::endl;
        std::cin >> name;
        std::cout << "Enter contact's number \"+7(10nums)\":" << std::endl;
        std::cin >> number;
        contacts.push_back(Contact(name, number));
        std::cout << "The contact added!" << std::endl;
    }

    void call(){
        std::string search, name, number;
        std::cout << "What do you want to enter name or phone?(n/p):" << std::endl;
        std::cin >> search;
        if (search == "n"){
            std::cout << "Enter contact's name for searching and calling:" << std::endl;
            std::cin >> name;
            for(const auto& i : contacts)
            {
                if(i.name != name) continue;
                std::cout << "CALL to " << i.number << std::endl;
                break;
            }
        } else if (search == "p"){
            std::cout << "Enter number for calling \"+7(10nums)\":" << std::endl;
            std::cin >> number;
            std::cout << "CALL to " << number << std::endl;
        } 
    }

    void sms(){
        std::string search, name, number, message;
        std::cout << "What do you want to enter name or phone?(n/p):" << std::endl;
        std::cin >> search;
        if (search == "n"){
            std::cout << "Enter contact's name for searching and send SMS:" << std::endl;
            std::cin >> name;
            for(const auto& i : contacts)
            {
                if(i.name != name) continue;
                std::cout << "SMS to " << i.number << std::endl;
                std::cout << "Enter message:" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, message);
                std::cout << "The message has been sent"<< std::endl;
                std::cout << "Your text:"<< std::endl << message << std::endl;
                break;
            }
        } else if (search == "p"){
            std::cout << "Enter number for SMS \"+7(10nums)\":" << std::endl;
            std::cin >> number;
            std::cout << "SMS to " << number << std::endl;
            std::cout << "Enter message:" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, message);
            std::cout << "The message has been sent" << std::endl;
            std::cout << "Your text:"<< std::endl << message << std::endl;
        } 
    }

};

int main()
{
    Phone* phone = new Phone();

    std::string inputComand;

    while(true)
    {
        std::cout << "Enter comand(add, call, sms or exit):" << std::endl;
        std::cin >> inputComand;

        if (inputComand == "add") phone->addContact();
        else if (inputComand == "call") phone->call();
        else if (inputComand == "sms") phone->sms();
        else if (inputComand == "exit") break;
        else std::cout << "Unknown command. Try again.\n";
    }

    delete phone;
}
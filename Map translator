#include <iostream>
#include <map>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int What;
    int What_lang;
    std::string pars_en;
    std::string pars_ru;
    std::map <std::string, std::string> dictionary;

    dictionary["aboba"] = "абоба";
    dictionary["milk"] = "молоко";
    dictionary["apple"] = "яблоко";
    dictionary["абоба"] = "aboba";
    dictionary["молоко"] = "milk";
    dictionary["яблоко"] = "apple";

    std::cout << "What you do? If you wanna translate enter 1/If you wanna add new word enter 2" << std::endl;
    std::cin >> What;
    if (What == 1) {
        std::cout << "What language do you want to translate from? Enter 1 to en/2 to ru " << std::endl;
        std::cin >> What_lang;
        if (What_lang == 1) {
            std::cout << "Enter word: " << std::endl;
            std::cin >> pars_en;
            std::cout << pars_en << " - " << dictionary[pars_en] << std::endl;
        }
        else if (What_lang == 2) {
            std::cout << "Введите слово: " << std::endl;
            std::cin >> pars_ru;
            std::cout << pars_ru << " - " << dictionary[pars_ru] << std::endl;
        }
        else {
            std::cout << "incorrect";
        }
    }
    else if (What == 2) {

        std::fstream logs;
        logs.open("logs.txt", std::ios::app);

        std::map<std::string, std::string> dictionary_user;
        std::string en_word;
        std::string ru_word;
      std::cout << "Напишите слово на английском: "; 
      std::cin >> en_word;
      std::cout << "Напишите слово на русском: "; 
      std::cin >> ru_word;
      dictionary_user[en_word] = ru_word;
      dictionary_user[ru_word] = en_word;

      logs << en_word << " " << ru_word << std::endl;

      std::cout << en_word << " - " << ru_word << std::endl;
    }
    else
    {
        std::cout << "incorrect";
    }
}

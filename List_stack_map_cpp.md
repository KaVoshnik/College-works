# List, stack, map c++
## List
### Синтаксис:
    - std::list<int> arr;                               | Пустой лист
    - std::list<int> arr(5);                            | Лист в 5 элементов
    - std::list<int> arr(5, 2);                         | Лист в 5 двоек
    - std::list<int> arr{1,2,4,5}; или arr = {1,2,3,5}; | Лист с 1, 2, 3, 5     
    - std::list<int> arr2 = arr;                        | Копия arr
### Методы
    - front() и back() | Первый и последний эл.
    - for (auto iter = numbers.begin(); iter != numbers.end(); iter++) | Пример итерации
    - size() | Кол-во элементов
    - resize(n) | Оставляет в списке n первых элементов
    - assign(arr) | заменяет содержимое контейнера элементами из списка инициализации arr
    - assign(n, value) | заменяет содержимое контейнера n элементами, которые имеют значение value
    - swap() | обменивает значениями два списка
    - push_back(val) | добавляет значение val в конец списка
    - push_front(val) | добавляет значение val в начало списка
    - empty() | возвращает true если пустой
## Stack
### Синтаксис
    Буквально синтаксис list
### Методы
- top() | возвращает последний добавленный элемент
- push()| добавляет элемент
- pop() | удаляет элемент из стека
- empty() | возвращает true если пустой
    
        //а так же стек можно инициализировать другим стеком или деком;
        std::deque<std::string> users{"Tom", "Sam", "Bob"};
        std::stack<std::string> stack {users};
## Map
Это массив или контейнер, где вместо индекса используются слова или другие значения
### Синтаксис
    std::map<std::string, unsigned> products; | обьявление map
    products["bread"] = 30; | установка значения по ключу
### Методы 
- erase() | удаляет ключ и значение ключа
- empty() | возвращает true если пустой
- count() и contains() | поиск ключа, возвращают int и bool соотв.
- cbegin() и cend() | возвращают начало и конец map соответственно

        //итерирование
        for(auto iter{phoneBook.cbegin()}; iter != phoneBook.cend(); iter++){
            std::cout << iter->first << "\t" << iter->second << std::endl;
        }

    
    
    
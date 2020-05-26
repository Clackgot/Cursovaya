#include <iostream> //стандартный ввод-вывод (сin cout endl)
#include <regex> //регулярные выражения (regex, regex_match, regex_replace)
#include <conio.h> //заголовочный файл для работы с консольным вводом-выводом
#include <Windows.h>// WinAPI, здесь используется для установки кодировки ( SetConsoleCP(1251) SetConsoleOutputCP(1251) ) Windows-1251
#include <fstream>// файловый ввод-вывод
#include <sstream>//работа со потоком строк (stringstream inp)
using namespace std;//Пространство имён std
///<summary>
/// Функция преобразующая строку из закодированного вида в обычный
///</summary>
///<example>
/// "Hello_world" -> "Hello world"
///</example>
///<param name = "str">Строка для преобразования</param>
std::string parseStringToSpace(std::string str)
{
    for (auto& it : str)
    {
        if (it == '_') it = ' ';
        if (it == '~') it = ',';
    }
    return str;
}
///<summary>
/// Функция кодирующая строку в вид, допустимый для сохранения в файл
///</summary>
///<example>
/// "Hello world" -> "Hello_world"
///</example>
///<param name = "str">Строка для преобразования</param>
std::string parseStringToUnderline(std::string str)
{
    for (auto& it : str)
    {
        if (it == ' ') it = '_';
        if (it == ',') it = '~';
    }
    return str;
}
///<summary>
/// Запрос от пользователя целого числа в промежутке (min;max) и вывод сообщения msg
///</summary>
int value(string msg, int min, int max)
{
    int x = -1;
    while (x < min || x > max)
    {
        x = _getch() - 48; //От кода клавиши отнимаем 48 и получаем нажатую цифру
    }
    return x;
}
///<summary>
///Запрос от пользователя строки и вывод сообщения msg
///</summary>
string readText(string msg)
{
    string temp = "";
    cout << msg << ":";
    while (true)
    {
        while (temp == "")getline(cin, temp);
        if (temp == "")
        {
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        else
        {
            return temp;
        }
    }
}
///<summary>
/// Запрос от пользователя целого числа и вывод сообщения msg
///</summary>
int readValue(string msg)
{
    while (true)
    {
        cout << msg << ":";
        int a;
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            system("cls");
        }
        else
        {
            return a;
        }
    }
}
///<summary>
/// Класс описывающий автомобиль
///</summary>
class Car
{
private:
   
    int _id;///<summary>ID автомобиля</summary>
    string _model;///<summary>Модель автомобиля</summary>
    string _stateNumber;///<summary>Гос.номер автомобиля</summary>
    int _seatsCount;///<summary>Пассажирские места автомобиля</summary>
    int _daysRentalPeriod;///<summary>Время аренды автомобиля</summary>
public:
    ///<summary>Базовый конструктор класса автомобиля</summary>
    Car()
    {
        setId(0);
        setModel("None");
        _stateNumber = "None";
        setSeatsCount(0);
        setDaysRentalPeriod(0);
    }
    ///<summary>Конструктор класса автомобиля</summary>
    ///<param name="id">ID автомобиля</param>
    ///<param name="model">Модель автомобиля</param>
    ///<param name="stateNumber">Гос.номер автомобиля</param>
    ///<param name="seatsCount">Кол-во мест автомобиля</param>
    ///<param name="daysRentalPeriod">Время аренды автомобиля</param>
    Car(int id, string model, string stateNumber, unsigned int seatsCount, unsigned int daysRentalPeriod)
    {
        setId(id);
        setModel(model);
        setStateNumber(stateNumber);
        setSeatsCount(seatsCount);
        setDaysRentalPeriod(daysRentalPeriod);
    }
    
    ///<summary>Возвращает ID автомобиля</summary>
    int getId()
    {
        return this->_id;
    }
    ///<summary>Возвращает модель автомобиля</summary>
    string getModel()
    {
        return this->_model;
    }
    ///<summary>Возвращает гос.номер автомобиля</summary>
    string getStateNumber()
    {
        return this->_stateNumber;
    }
    ///<summary>Возвращает кол-во пассажирских мест автомобиля</summary>
    int getSeatsCount()
    {
        return this->_seatsCount;
    }
    ///<summary>Возвращает время аренды автомобиля</summary>
    int getDaysRentalPeriod()
    {
        return this->_daysRentalPeriod;
    }
    ///<summary>Устанавливает ID автомобиля</summary>
    void setId(int id)
    {
        this->_id = id;
    }
    ///<summary>Устанавливает модель автомобиля</summary>
    void setModel(string model)
    {
        this->_model = model;
    }
    ///<summary>Устанавливает гос.номер автомобиля</summary>
    void setStateNumber(string stateNumber)
    {
        if(checkNumber(stateNumber))this->_stateNumber = stateNumber;
        else
        {
            throw new exception("Гос.номер автомобиля не соответсвует шаблону");
        }
    }
    ///<summary>Устанавливает кол-во пассажирских мест автомобиля</summary>
    void setSeatsCount(unsigned int seatsCount)
    {
        this->_seatsCount = seatsCount;
    }
    ///<summary>Устанавливает время аренды автомобиля</summary>
    void setDaysRentalPeriod(unsigned int daysRentalPeriod)
    {
        this->_daysRentalPeriod = daysRentalPeriod;
    }
    ///<summary>Проверяет валидность гос.номера автомобиля</summary>
    static bool checkNumber(string number)
    {
        regex rg("[АВЕКМНОРСТУХABEKMHOPCTYX][0-9]{3}[АВЕКМНОРСТУХABEKMHOPCTYX]{2}[0-9]{2,3}");
        return regex_match(number, rg);
    }
    ///<summary>Выводит информацию об автомобиле в консоль</summary>
    void print()
    {
        cout << getSeatsCount() << "-х местный автомобиль марки " << getModel() << " с гос.номером " << getFormatedStateNumber() << endl;
    }
    ///<summary>Возвращает гос.номер в форматированном виде</summary>
    string getFormatedStateNumber()
    {
        string temp = _stateNumber;
        temp.insert(temp.begin() + 6, ' ');
        temp += " регион";
        return temp;
    }
};
///<summary>
/// Класс описывающий клиента
///</summary>
class Client
{
private:
    int _id;///<summary>ID клиента</summary>
    string _name;///<summary>Имя клиента</summary>
    string _surname;///<summary>Фамилия клиента</summary>
    string _passportNumber;///<summary>Номер паспорта клиента</summary>
public:
    ///<summary>Базовый конструктор класса клиента</summary>
    Client()
    {
        setId(0);
        setName("None");
        setSurname("None");
        _passportNumber = "None";
    }
    ///<summary>Конструктор класса клиента</summary>
    ///<param name="id">ID клиента</param>
    ///<param name="name">Имя клиента</param>
    ///<param name="surname">Фамилия клиента</param>
    ///<param name="passportNumber">Номер паспота клиента</param>
    Client(int id, string name, string surname, string passportNumber)
    {
        setId(id);
        setName(name);
        setSurname(surname);
        setPassportNumber(passportNumber);
    }
    ///<summary>Возвращает ID клиента</summary>
    int getId()
    {
        return this->_id;
    }
    ///<summary>Возвращает имя клиента</summary>
    string getName()
    {
        return this->_name;
    }
    ///<summary>Возвращает фамилию клиента</summary>
    string getSurname()
    {
        return this->_surname;
    }
    ///<summary>Возвращает номер паспорта клиента</summary>
    string getPassportNumber()
    {
        return this->_passportNumber;
    }
    ///<summary>Устанавливает ID клиента</summary>
    void setId(int id)
    {
        this->_id = id;
    }
    ///<summary>Устанавливает имя клиента</summary>
    void setName(string name)
    {
        this->_name = name;
    }
    ///<summary>Устанавливает фамилию клиента</summary>
    void setSurname(string surname)
    {
        this->_surname = surname;
    }
    ///<summary>Устанавливает номер паспорта клиента</summary>
    void setPassportNumber(string passportNumber)
    {
        if (checkPassportNumber(passportNumber))this->_passportNumber = passportNumber;
        else throw new exception("Номер паспорта не соответсвует шаблону");
    }
    ///<summary>Проверяет валидность номера паспорта клиента</summary>
    static bool checkPassportNumber(string passportNumber)
    {
        return regex_match(passportNumber, regex("[0-9]{10}"));
    }
    ///<summary>Возвращает номер паспорта в форматированном виде</summary>
    string getFormatePassportNumber()
    {
        string temp = _passportNumber;
        temp.insert(temp.begin() + 4, ' ');
        return temp;
    }
    ///<summary>Выводит информацию о клиенте в консоль</summary>
    void print()
    {
        cout << this->getSurname() << " " << this->getName() << " с паспортными данными " << this->getFormatePassportNumber() << endl;
    }
};
class Company
{
private:
    vector<Car> _cars;///<summary>Вектор экземпляров класса Car</summary>
    vector<Client> _clients;///<summary>Вектор экземпляров класса Client</summary>
    vector<pair<int, vector<int>>> currentCarsByClient;///<summary>Вектор пар состоящих из текущих ID клиента и ID его арендованных авто</summary>
    vector<pair<int, vector<int>>> currentClientsByCar;///<summary>Вектор пар состоящих из текущих ID авто и ID клеинта, которым арендовано</summary>
    vector<pair<int, vector<int>>> historyCarsByClient;///<summary>История аренды в виде вектора пар состоящих из ID клиента и ID его арендованных авто</summary>
    vector<pair<int, vector<int>>> historyClientsByCar;///<summary>История аренды в виде вектора пар состоящих из ID авто и ID клеинта, которым арендовано</summary>
    ///<example>
    /// <1, 2 3>
    /// <2, 4 5 6>
    ///</example>
public:
    ///<summary>Указатель на элемент вектора экземпляров класса Car - _cars</summary>
    Car* getCarById(int id)
    {
        for (auto &item : _cars)
        {
            if (item.getId() == id)
            {
                return &item;
            }
        }
        return new Car();
    }
    ///<summary>Указатель на элемент вектора экземпляров класса Client - _clients</summary>
    Client* getClientById(int id)
    {
        for (auto &item : _clients)
        {
            if (item.getId() == id)
            {
                return &item;
            }
        }
        return new Client();
    }
    ///<summary>Вектор указателей на экземпляры вектора _cars с заданным id</summary>
    vector<Car*> getCarsByClient(int clientId)
    {
        vector<Car*> tempCars;
        for (auto it : currentCarsByClient)
        {
            if (it.first == clientId)
            {
                for (auto item : it.second)
                {
                    tempCars.push_back(getCarById(item));
                }
            }
        }
        return tempCars;
    }
    ///<summary>Вектор указателей на экземпляры вектора _clients с заданным id</summary>
    vector<Client*> getClientsByCar(int carId)
    {
        vector<Client*> tempClients;
        for (auto it : currentClientsByCar)
        {
            if (it.first == carId)
            {
                for (auto item : it.second)
                {
                    tempClients.push_back(getClientById(item));
                }
            }
        }
        return tempClients;
    }
    ///<summary>Вектор указателей на экземпляры вектора historyCarsByClient с заданным id</summary>
    vector<Car*> getHistoryCarsByClient(int clientId)
    {
        vector<Car*> tempCars;
        for (auto it : historyCarsByClient)
        {
            if (it.first == clientId)
            {
                for (auto item : it.second)
                {
                    tempCars.push_back(getCarById(item));
                }
            }
        }
        return tempCars;
    }
    ///<summary>Вектор указателей на экземпляры вектора historyClientsByCar с заданным id</summary>
    vector<Client*> getHistoryClientsByCar(int carId)
    {
        vector<Client*> tempClients;
        for (auto it : historyClientsByCar)
        {
            if (it.first == carId)
            {
                for (auto item : it.second)
                {
                    tempClients.push_back(getClientById(item));
                }
            }
        }
        return tempClients;
    }
    ///<summary>Добавляет авто в вектор _cars</summary>
    void addCar(Car car)
    {
        _cars.push_back(car);
        pair<int, vector<int>> ids;
        ids.first = car.getId();
        currentClientsByCar.push_back(ids);
    }
    ///<summary>Добавляет клиента в вектор _clients</summary>
    void addClient(Client client)
    {
        _clients.push_back(client);
        pair<int, vector<int>> ids;
        ids.first = client.getId();
        currentCarsByClient.push_back(ids);
    }
    ///<summary>Арендует авто с ID carId на имя клиента с ID clientId</summary>
    void rent(int carId, int clientId)
    {
        if (checkCarRent(carId)) return;
        for (auto& it : currentCarsByClient)
        {
            if (it.first == clientId)
            {
                bool ex = false;
                for (auto i : it.second)
                {
                    if (i == carId) ex = true;
                }
                if (getCarById(carId)->getId() == 0) ex = true;
                if (!ex) it.second.push_back(carId);
            }
        }
        for (auto& it : currentClientsByCar)
        {
            if (it.first == carId)
            {
                bool ex = false;
                for (auto i : it.second)
                {
                    if (i == clientId) ex = true;
                }
                if (getClientById(clientId)->getId() == 0) ex = true;
                if (!ex) it.second.push_back(clientId);
            }
        }
    }
    ///<summary>Обнуляет аренду авто с ID carId на имя клиента с ID clientId</summary>
    void unrent(int carId, int clientId)
    {
        auto car = getCarById(carId);
        auto client = getClientById(clientId);
        if (car->getId() == 0 || client->getId() == 0)return;
        for (auto& it : currentCarsByClient)
        {
            if (it.first == clientId)
            {
                historyCarsByClient.push_back(it);
                it.second.erase(find(it.second.begin(),it.second.end(),carId), it.second.end());
            }
        }
        for (auto& it : currentClientsByCar)
        {
            if (it.first == carId)
            {
                historyClientsByCar.push_back(it);
                it.second.erase(find(it.second.begin(), it.second.end(), clientId), it.second.end());
            }
        }
    }
    ///<summary>Обнуляет аренду список арендованных авто клиента с ID clientId</summary>
    void unrentClient(int clientId)
    {
        for (auto& item : currentCarsByClient)
        {
            for (auto it : item.second)
            {
                if(item.first == clientId)
                {
                    unrent(it,clientId);
                }
            }
        }
    }
    ///<summary>Обнуляет аренду авто с ID carId</summary>
    void unrentCar(int carId)
    {
        for (auto& item : currentClientsByCar)
        {
            for (auto it : item.second)
            {
                if (item.first == carId)
                {
                    unrent(carId, it);
                }
            }
        }
    }
    ///<summary>Выводит автомобиль с carId в консоль</summary>
    void printCar(int carId)
    {
        auto car = getCarById(carId);
        auto clients = getClientsByCar(carId);
        auto historyClients = getHistoryClientsByCar(carId);
        if (car->getId() == 0)return;
        printf("||||||||||||||||||||||||||АВТО#%04d|||||||||||||||||||||||||\n", carId);
        printf("----------------------Информация об авто--------------------\n");
        car->print();
        if (checkCarRent(car->getId())) cout << "Арендован на " << car->getDaysRentalPeriod() << " дней." << endl;
        if (!clients.empty())
        {
            printf("-------------------------Арендаторы-------------------------\n");
            for (auto it : clients)
            {
                it->print();
            }
        }
        else
        {
            printf("----------------------Автомобиль свободен-------------------\n");
        }
        if (!historyClients.empty())
        {
            printf("-------------------------История аренды---------------------\n");
            for (auto it : historyClients)
            {
                if (carExist(it->getId()))it->print();
            }
        }
        else
        {
            printf("---------------------История аренды пуста-------------------\n");
        }
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        cout << endl << endl;
    }
    ///<summary>Выводит клиента с clientId в консоль</summary>
    void printClient(int clientId)
    {
        auto client = getClientById(clientId);
        auto cars = getCarsByClient(clientId);
        auto histotyCars = getHistoryCarsByClient(clientId);
        if (client->getId() == 0)return;
        printf("|||||||||||||||||||||||||КЛИЕНТ#%04d||||||||||||||||||||||||\n", clientId);
        printf("---------------------Информация о клиенте-------------------\n");
        client->print();
        if (!cars.empty())
        {
            printf("-----------------------Арендованные авто--------------------\n");
            for (auto it : cars)
            {
                it->print();
            }
        }
        else
        {
            printf("--------------------Арендованных авто нет-------------------\n");
        }
        if (!histotyCars.empty())
        {
            printf("----------------------История аренды------------------------\n");
            for (auto it : histotyCars)
            {
                if(clientExist(it->getId()))it->print();
            }
        }
        else
        {
            printf("----------------------История аренды пуста------------------\n");
        }
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        cout << endl << endl;
    }
    ///<summary>Выводит список всех авто в консоль</summary>
    void printCars()
    {
        for (auto it : _cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит список всех клиентов в консоль</summary>
    void printClients()
    {
        for (auto it : _clients)
        {
            printClient(it.getId());
        }
    }
    ///<summary>Проверяет авто на наличие аренды</summary>
    bool checkCarRent(int carId)
    {
        for (auto item : currentCarsByClient)
        {
            for (auto it : item.second)
            {
                if (it == carId) return true;
            }
        }
        return false;
    }
    ///<summary>Проверяет существование авто с заданным carId</summary>
    bool carExist(int carId )
    {
        for (auto item : _cars)
        {
            if (item.getId() == carId)
            {
                return true;
            }
        }
        return false;
    }
    ///<summary>Проверяет существование клиента с заданным clientId</summary>
    bool clientExist(int clientId)
    {
        for (auto item : _clients)
        {
            if (item.getId() == clientId)
            {
                return true;
            }
        }
        return false;
    }
    ///<summary>Удаляет авто с заданным id</summary>
    void removeCar(int id)
    {
        unrentCar(id);
        vector<Car> cars;
        for (auto it : _cars)
        {
            if (it.getId() != id)cars.push_back(it);
        }
        _cars.clear();
        _cars = cars;
    }
    ///<summary>Удаляет клиента с заданным id</summary>
    void removeClient(int id)
    {
        unrentClient(id);
        vector<Client> clients;
        for (auto it : _clients)
        {
            if (it.getId() != id)clients.push_back(it);
        }
        _clients.clear();
        _clients = clients;
    }
    ///<summary>Возвращает текущий максимальный id из вектора _cars</summary>
    int getMaxCarsId()
    {
        int max = 0;
        for (auto it : _cars)
        {
            if (it.getId() > max) max = it.getId();
        }
        return max;
    }
    ///<summary>Возвращает текущий максимальный id из вектора _clients</summary>
    int getMaxClientId()
    {
        int max = 0;
        for (auto it : _clients)
        {
            if (it.getId() > max) max = it.getId();
        }
        return max;
    }
    ///<summary>Выводит отсортированный список автомобилей по модели</summary>
    void printSortCarByModel(bool direction)
    {
        auto cars = _cars;
        if(direction)sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getModel() < b.getModel(); });
        else sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getModel() > b.getModel(); });
        for(auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит отсортированный список автомобилей по гос.номеру</summary>
    void printSortCarByStateNumber(bool direction)
    {
        auto cars = _cars;
        if (direction)sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getStateNumber() < b.getStateNumber(); });
        else sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getStateNumber() > b.getStateNumber(); });
        for (auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит отсортированный список автомобилей по кол-ву пассажирских мест</summary>
    void printSortCarBySeatsCount(bool direction)
    {
        auto cars = _cars;
        if (direction)sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getSeatsCount() < b.getSeatsCount(); });
        else sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getSeatsCount() > b.getSeatsCount(); });
        for (auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит отсортированный список автомобилей по сроку аренды</summary>
    void printSortCarByDaysRentalPeriod(bool direction)
    {
        auto cars = _cars;
        if (direction)sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getDaysRentalPeriod() < b.getDaysRentalPeriod(); });
        else sort(cars.begin(), cars.end(), [](Car a, Car b) { return a.getDaysRentalPeriod() > b.getDaysRentalPeriod(); });
        for (auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит отсортированный список клиентов по имени</summary>
    void printSortCleintByName(bool direction)
    {
        auto clients = _clients;
        if (direction)sort(clients.begin(), clients.end(), [](Client a, Client b) { return a.getName() < b.getName(); });
        else sort(clients.begin(), clients.end(), [](Client a, Client b) { return a.getName() > b.getName(); });
        for (auto it : clients)
        {
            printClient(it.getId());
        }
    }
    ///<summary>Выводит отсортированный список клиентов по фамилии</summary>
    void printSortCleintBySurname(bool direction)
    {
        auto clients = _clients;
        if (direction)sort(clients.begin(), clients.end(), [](Client a, Client b) { return a.getSurname() < b.getSurname(); });
        else sort(clients.begin(), clients.end(), [](Client a, Client b) { return a.getSurname() > b.getSurname(); });
        for (auto it : clients)
        {
            printClient(it.getId());
        }
    }
    ///<summary>Выводит отсортированный список клиентов по номеру паспорта</summary>
    void printSortCleintByPassportNumber(bool direction)
    {
        auto clients = _clients;
        if (direction)sort(clients.begin(), clients.end(), [](Client a, Client b) { return a.getFormatePassportNumber() < b.getFormatePassportNumber(); });
        else sort(clients.begin(), clients.end(), [](Client a, Client b) { return a.getFormatePassportNumber() > b.getFormatePassportNumber(); });
        for (auto it : clients)
        {
            printClient(it.getId());
        }
    }
    ///<summary>Выводит список найденных автомобилей с заданной моделью model</summary>
    void printFindCarByModel(string model)
    {
        vector<Car> cars;
        for (auto it : _cars)
        {
            if (it.getModel() == model) cars.push_back(it);
        }
        for (auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит список найденных автомобилей с заданным гос.номером stateNumber</summary>
    void printFindCarByStateNumber(string stateNumber)
    {
        vector<Car> cars;
        for (auto it : _cars)
        {
            if (it.getStateNumber() == stateNumber) cars.push_back(it);
        }
        for (auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит список найденных автомобилей с заданным сроком аренды daysRentalPeriod</summary>
    void printFindCarByDaysRentalPeriod(int daysRentalPeriod)
    {
        vector<Car> cars;
        for (auto it : _cars)
        {
            if (it.getDaysRentalPeriod() == daysRentalPeriod) cars.push_back(it);
        }
        for (auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит список найденных автомобилей с заданным кол-вом seatsCount</summary>
    void printFindCarBySeatsCount(int seatsCount)
    {
        vector<Car> cars;
        for (auto it : _cars)
        {
            if (it.getSeatsCount() == seatsCount) cars.push_back(it);
        }
        for (auto it : cars)
        {
            printCar(it.getId());
        }
    }
    ///<summary>Выводит список найденных клиентов с заданным именем</summary>
    void printFindClientByName(string name)
    {
        vector<Client> clients;
       
        for (auto it : _clients)
        {
            if (it.getName() == name)
            {
                clients.push_back(it);
            }
        }
        for (auto it : clients)
        {
            printClient(it.getId());
        }
    }
    ///<summary>Выводит список найденных клиентов с заданной фамилией</summary>
    void printFindClientBySurname(string surname)
    {
        vector<Client> clients;
        for (auto it : _clients)
        {
            if (it.getSurname() == surname) clients.push_back(it);
        }
        for (auto it : clients)
        {
            printClient(it.getId());
        }
    }
    ///<summary>Выводит список найденных клиентов с заданным номером паспорта</summary>
    void printFindClientByPassportNumber(string passportNumber)
    {
        vector<Client> clients;
        for (auto it : _clients)
        {
            if (it.getPassportNumber() == passportNumber) clients.push_back(it);
        }
        for (auto it : clients)
        {
            printClient(it.getId());
        }
    }
    ///<summary>Сохраняет вектор клиентов _clients в файл cars.txt</summary>
    void saveCars()
    {
        std::ofstream fp;
        fp.open(".\\cars.txt", std::ios_base::trunc | std::ios::out);
        for (auto it : _cars)
        {
            fp << it.getId() << " ";
            fp << parseStringToUnderline(it.getModel()) << " ";
            fp << it.getStateNumber() << " ";
            fp << it.getSeatsCount() << " ";
            fp << it.getDaysRentalPeriod() << endl;
        }
        fp.close();
    }
    ///<summary>Сохраняет вектор клиентов _clients в файл clients.txt</summary>
    void saveClients()
    {
        std::ofstream fp;
        fp.open(".\\clients.txt", std::ios_base::trunc | std::ios::out);
        for (auto it : _clients)
        {
            fp << it.getId() << " ";
            fp << parseStringToUnderline(it.getName()) << " ";
            fp << parseStringToUnderline(it.getSurname()) << " ";
            fp << it.getPassportNumber() << endl;
        }
        fp.close();
    }
    ///<summary>Загружает вектор клиентов _clients из файла cars.txt</summary>
    void loadCars()
    {
        std::ifstream fp;
        fp.open(".\\cars.txt");
        while (!fp.eof())
        {
            int id;
            string model;
            string stateNumber;
            int seatsCount;
            int daysRentalPeriod;

            fp >> id;
            fp >> model;
            fp >> stateNumber;
            fp >> seatsCount;
            fp >> daysRentalPeriod;

            if(model != "")addCar(Car(id, parseStringToSpace(model), stateNumber, seatsCount, daysRentalPeriod));

            }
    }
    ///<summary>Загружает вектор клиентов _clients из файла clients.txt</summary>
    void loadClients()
    {
        std::ifstream fp;
        fp.open(".\\clients.txt");
        while (!fp.eof())
        {
            int id;
            string name;
            string surname;
            string passportNumber;

            fp >> id;
            fp >> name;
            fp >> surname;
            fp >> passportNumber;

            if(name != "")addClient(Client(id, parseStringToSpace(name), parseStringToSpace(surname), passportNumber));
        }
    }
    ///<summary>Сохраняет вектор currentClientsByCar в файл currentClientsByCar.txt</summary>
    void saveCurrentClientsByCar()
    {
        std::ofstream fp;
        fp.open(".\\currentClientsByCar.txt", ios_base::trunc | ios::out);
        for (auto item : currentClientsByCar)
        {
            fp << item.first << " ";
            for (auto it : item.second)
            {
                fp << it << " ";
            }
            fp << endl;
        }
        fp.close();
    }
    ///<summary>Загружает вектор currentClientsByCar из файал currentClientsByCar.txt</summary>
    void loadCurrentClientsByCar()
    {
        ifstream fp;
        fp.open(".\\currentClientsByCar.txt");
        string s;
        stringstream inp;

        while(!fp.eof())
        {
            int a;
            int b;
            fp >> a;
            fp >> b;
            rent(a, b);
        }
    }
    ///<summary>Сохраняет вектор historyClientsByCar в файл historyClientsByCar.txt</summary>
    void saveHistoryClientsByCar()
    {
        std::ofstream fp;
        fp.open(".\\historyClientsByCar.txt", std::ios_base::trunc | std::ios::out);
        for (auto item : historyClientsByCar)
        {
            fp << item.first << " ";
            for (auto it : item.second)
            {
                fp << it << " ";
            }
            fp << endl;
        }
        fp.close();
    }
    ///<summary>Загружает вектор historyClientsByCar из файал historyClientsByCar.txt</summary>
    void loadHistoryClientsByCar()
    {
        ifstream fp;
        fp.open(".\\historyClientsByCar.txt");
        string s;
        stringstream inp;
        while (!fp.eof())
        {
            int a;
            int b;
            fp >> a;
            fp >> b;
            unrent(a, b);
        }
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto comp = Company();
    comp.loadCars();
    comp.loadClients();
    comp.loadCurrentClientsByCar();
    comp.loadHistoryClientsByCar();
    int menu = -1;
    while (menu != 0)
    {
        system("cls");
        cout << "1.Автомобили" << endl;
        cout << "2.Клиенты" << endl;
        cout << "3.Аренда" << endl;
        cout << "0.Выход" << endl;
        menu = value("", 0, 3);
        switch (menu)
        {
        case 1:
            while (menu != 0)
            {
                system("cls");
                cout << "1.Просмотр всех авто" << endl;
                cout << "2.Добавить" << endl;
                cout << "3.Редактировать" << endl;
                cout << "4.Удалить" << endl;
                cout << "5.Сортировка" << endl;
                cout << "6.Поиск" << endl;
                cout << "0.Назад" << endl;
                menu = value("", 0, 6);
                int id;
                string model = "";
                string stateNumber = "";
                int seatsCount = 0;
                int daysRentalPeriod = 0;
                bool dir = true;
                switch (menu)
                {
                case 1:
                    system("cls");
                    comp.printCars();
                    system("pause");
                    menu = -1;
                    break;
                case 2:
                    system("cls");
                    id = comp.getMaxCarsId() + 1;
                    while(model == "")model = readText("Модель");
                    while(!Car::checkNumber(stateNumber))stateNumber = readText("Гос.номер");;
                    while (seatsCount <= 0)seatsCount = readValue("Количество мест");
                    while (daysRentalPeriod <= 0)daysRentalPeriod = readValue("Время аренды(дней)");
                    comp.addCar(Car(id, model, stateNumber, seatsCount, daysRentalPeriod));
                    
                    system("pause");
                    menu = -1;
                    break;
                case 3:
                    system("cls");
                    id = readValue("ID автомобиля");
                    if (comp.carExist(id))
                    {
                        comp.removeCar(id);
                        while (model == "")model = readText("Модель");
                        while (!Car::checkNumber(stateNumber))stateNumber = readText("Гос.номер");;
                        while (seatsCount <= 0)seatsCount = readValue("Количество мест");
                        while (daysRentalPeriod <= 0)daysRentalPeriod = readValue("Время аренды(дней)");                  
                        comp.addCar(Car(id, model, stateNumber, seatsCount, daysRentalPeriod));
                    }
                    else
                    {
                        cout << "Автомобиля с " << id << " не существует." << endl;
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 4:
                    system("cls");
                    id = readValue("ID автомобиля");
                    if (comp.carExist(id))
                    {
                        cout << "Автомобиль с " << id << " удалён." << endl;
                        comp.removeCar(id);
                    }
                    else
                    {
                        cout << "Автомобиля с " << id << " не существует." << endl;
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 5:
                    while (menu != 0)
                    {
                        system("cls");
                        cout << "1.Модель" << endl;
                        cout << "2.Гос.номер" << endl;
                        cout << "3.Время аренды" << endl;
                        cout << "4.Посадочные места" << endl;
                        cout << "0.Назад" << endl;
                        menu = value("", 0, 4);
                        switch (menu)
                        {
                        case 1:
                            system("cls");
                            comp.printSortCarByModel(dir);
                            system("pause");
                            menu = -1;
                            dir = !dir;
                            break;
                        case 2:
                            system("cls");
                            comp.printSortCarByStateNumber(dir);
                            system("pause");
                            menu = -1;
                            dir = !dir;
                            break;
                        case 3:
                            system("cls");
                            comp.printSortCarByDaysRentalPeriod(dir);
                            system("pause");
                            menu = -1;
                            dir = !dir;
                            break;
                        case 4:
                            system("cls");
                            comp.printSortCarBySeatsCount(dir);
                            system("pause");
                            menu = -1;
                            dir = !dir;
                            break;
                        case 0:
                            break;
                        }
                    }
                    menu = -1;
                    break;
                case 6:
                    system("cls");
                    while (menu != 0)
                    {
                        system("cls");
                        cout << "1.Модель" << endl;
                        cout << "2.Гос.номер" << endl;
                        cout << "3.Время аренды" << endl;
                        cout << "4.Посадочные места" << endl;
                        cout << "0.Назад" << endl;
                        menu = value("", 0, 4);
                        switch (menu)
                        {
                        case 1:
                            system("cls");
                            model = readText("Модель");
                            comp.printFindCarByModel(model);
                            system("pause");
                            menu = -1;
                            break;
                        case 2:
                            system("cls");
                            stateNumber = readText("Гос.номер");
                            comp.printFindCarByStateNumber(stateNumber);
                            system("pause");
                            menu = -1;
                            break;
                        case 3:
                            system("cls");
                            daysRentalPeriod = readValue("Время аренды(дней)");
                            comp.printFindCarByDaysRentalPeriod(daysRentalPeriod);
                            system("pause");
                            menu = -1;
                            break;
                        case 4:
                            system("cls");
                            seatsCount = readValue("Посадочных мест");
                            comp.printFindCarBySeatsCount(seatsCount);
                            system("pause");
                            menu = -1;
                            break;
                        case 0:
                            break;
                        }
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 0:
                    break;
                }
            }
            menu = -1;
            break;
        case 2:
            while (menu != 0)
            {
                system("cls");
                cout << "1.Просмотр всех клиентов" << endl;
                cout << "2.Добавить" << endl;
                cout << "3.Редактировать" << endl;
                cout << "4.Удалить" << endl;
                cout << "5.Сортировка" << endl;
                cout << "6.Поиск" << endl;
                cout << "0.Назад" << endl;
                int id;
                string name;
                string surname;
                string passportNumber;
                bool dir = true;
                menu = value("", 0, 6);
                switch (menu)
                {
                case 1:
                    system("cls");
                    comp.printClients();
                    system("pause");
                    menu = -1;
                    break;
                case 2:
                    system("cls");
                    id = comp.getMaxClientId() + 1;
                    while (name == "")name = readText("Имя");
                    while (surname == "")surname = readText("Фамилия");
                    while (!Client::checkPassportNumber(passportNumber))passportNumber = readText("Номер паспорта");;
                    comp.addClient(Client(id, name, surname, passportNumber));
                    system("pause");
                    menu = -1;
                    break;
                case 3:
                    system("cls");
                    id = readValue("ID клиента");
                    if (comp.clientExist(id))
                    {
                        comp.removeClient(id);
                        while (name == "")name = readText("Имя");
                        while (surname == "")surname = readText("Фамилия");
                        while (!Client::checkPassportNumber(passportNumber))passportNumber = readText("Номер паспорта");;
                        comp.addClient(Client(id, name, surname, passportNumber));
                    }
                    else
                    {
                        cout << "Клиента с " << id << " не существует." << endl;
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 4:
                    system("cls");
                    id = readValue("ID клиента");
                    if (comp.clientExist(id))
                    {
                        cout << "Клиент с " << id << " удалён." << endl;
                        comp.removeClient(id);
                    }
                    else
                    {
                        cout << "Клиента с " << id << " не существует." << endl;
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 5:
                    while (menu != 0)
                    {
                        system("cls");
                        cout << "1.Имя" << endl;
                        cout << "2.Фамилия" << endl;
                        cout << "3.Номер паспорта" << endl;
                        cout << "0.Назад" << endl;
                        menu = value("", 0, 3);
                        switch (menu)
                        {
                        case 1:
                            system("cls");
                            comp.printSortCleintByName(dir);
                            dir = !dir;
                            system("pause");
                            menu = -1;
                            break;
                        case 2:
                            system("cls");
                            comp.printSortCleintBySurname(dir);
                            dir = !dir;
                            system("pause");
                            menu = -1;
                            break;
                        case 3:
                            system("cls");
                            comp.printSortCleintByPassportNumber(dir);
                            dir = !dir;
                            system("pause");
                            menu = -1;
                            break;
                        case 0:
                            break;
                        }
                    }
                    menu = -1;
                    break;
                case 6:
                    while (menu != 0)
                    {
                        system("cls");
                        cout << "1.Имя" << endl;
                        cout << "2.Фамилия" << endl;
                        cout << "3.Номер паспорта" << endl;
                        cout << "0.Назад" << endl;
                        menu = value("", 0, 3);
                        switch (menu)
                        {
                        case 1:
                            system("cls");
                            name = readText("Имя");
                            comp.printFindClientByName(name);
                            system("pause");
                            menu = -1;
                            break;
                        case 2:
                            system("cls");
                            surname = readText("Фамилия");
                            comp.printFindClientBySurname(surname);
                            system("pause");
                            menu = -1;
                            break;
                        case 3:
                            system("cls");
                            passportNumber = readText("Номер паспорта");
                            comp.printFindClientByPassportNumber(passportNumber);
                            system("pause");
                            menu = -1;
                            break;
                        case 0:
                            break;
                        }
                    }
                    menu = -1;
                    break;
                case 0:
                    break;
                }
            }
            menu = -1;
            break;
        case 3:
            while (menu != 0)
            {
                system("cls");
                cout << "1.Арендовать" << endl;
                cout << "2.Снять аренду с авто" << endl;
                cout << "3.Отменить всю аренду клиента" << endl;
                cout << "0.Назад" << endl;
                menu = value("", 0, 3);
                switch (menu)
                {
                case 1:
                    system("cls");
                    int carId, clientId;
                    carId = readValue("ID автомобиля");
                    clientId = readValue("ID клиента");
                    
                    if (!comp.carExist(carId) || !comp.clientExist(clientId))
                    {
                        if(!comp.carExist(carId))cout << "Автомобиля с таким ID не существует" << endl;
                        if(!comp.clientExist(clientId)) cout << "Клиента с таким ID не существует" << endl;
                    }
                    else if (comp.checkCarRent(carId))
                    {
                        
                        cout << "Автомобиль с гос.номером " << comp.getCarById(carId)->getFormatedStateNumber()
                            << " уже арендован на имя " << comp.getClientsByCar(carId)[0]->getSurname() << endl;
                    }
                    else
                    {
                        comp.rent(carId, clientId);
                        cout << "Автомобиль с гос.номером " << comp.getCarById(carId)->getFormatedStateNumber()
                            << " успешно арендован на имя " << comp.getClientById(clientId)->getSurname() << endl;
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 2:
                    system("cls");
                    carId = 0;
                    carId = readValue("ID автомобиля");
                    if (!comp.carExist(carId))
                    {
                        cout << "Автомобиля с таким ID не существует" << endl;
                    }
                    else if (comp.checkCarRent(carId))
                    {
                        comp.unrentCar(carId);
                        cout << "Автомобиль с гос.номером " << comp.getCarById(carId)->getFormatedStateNumber()
                            << " успешно снят с аренды" << endl;
                    }
                    else
                    {
                        cout << "Автомобиль с гос.номером " << comp.getCarById(carId)->getFormatedStateNumber()
                            << " не находится в аренде" << endl;
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 3:
                    system("cls");
                    clientId = 0;
                    clientId = readValue("ID клиента");
                    if (!comp.clientExist(clientId))
                    {
                        cout << "Клиента с таким ID не существует" << endl;
                    }
                    else
                    {
                        comp.unrentClient(clientId);
                        cout << "Вся аренда клиента " << comp.getClientById(clientId)->getSurname() << " " 
                            << comp.getClientById(clientId)->getName() << " обнулена." << endl;
                    }
                    system("pause");
                    menu = -1;
                    break;
                case 0:
                    break;
                }
            }
            menu = -1;
            break;
        case 0:
            break;
        }
    }
    comp.saveHistoryClientsByCar();
    comp.saveCurrentClientsByCar();
    comp.saveCars();
    comp.saveClients();
}
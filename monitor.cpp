#include "monitor.h"

unsigned int Monitor::quantity = 0;

// KONSTRUKTORY ****************************************

Monitor::Monitor() // podstawowy konstruktor
{
    quantity++;
#ifdef _DEBUG
    cout<<"Monitor(), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif
}

Monitor::Monitor(string model_name) // z inicjalizacja nazwy modelu
{
    quantity++;
#ifdef _DEBUG
    cout<<"Monitor("<<model_name<<"), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->name_of_model = model_name;
}

Monitor::Monitor(unsigned int apps_number) // z inicjalizacja ilosci aplikacji
{
    quantity++;
#ifdef _DEBUG
    cout<<"Monitor("<<apps_number<<"), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->number_of_apps= apps_number;
    if(this->number_of_apps > 0)
    {
        this->opened_apps = new App[this->number_of_apps]; // stworzenie dynamicznej tablicy na aplikacje
    }
}

Monitor::Monitor(string model_name, unsigned int apps_number) // pełna inicjalizacja
{
    quantity++;
#ifdef _DEBUG
    cout<<"Monitor("<<model_name<<" "<<apps_number<<"), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->name_of_model = model_name;
    this->number_of_apps = apps_number;
    if(this->number_of_apps > 0)
    {
        this->opened_apps = new App[this->number_of_apps]; // stworzenie dynamicznej tablicy na aplikacje
    }

}

Monitor::Monitor(const Monitor &monitor_to_copy) // konstruktor kopiujacy
{
    quantity++;
#ifdef _DEBUG
    cout<<"Monitor(const Monitor &monitor_to_copy), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->name_of_model = monitor_to_copy.name_of_model;
    this->number_of_apps = monitor_to_copy.number_of_apps;
    if(this->number_of_apps > 0)
    {
        this->opened_apps = new App[this->number_of_apps];
    }
    for(unsigned int i = 0; i < number_of_apps; i++)
    {
        this->opened_apps[i] = monitor_to_copy.opened_apps[i];
    }
}

// KONSTRUKTORY ****************************************


Monitor::~Monitor() // destruktor
{
    quantity--;
#ifdef _DEBUG
    if(this->name_of_model == "unknown" && number_of_apps == 0)
    {
        cout<<"~Monitor(), current number of class 'Monitor' objects: "<<quantity<<endl;
    }
    else
    {
        cout<<"~Monitor("<<this->name_of_model<<" "<<number_of_apps<<"), current number of class 'Monitor' objects: "<<quantity<<endl;
    }
#endif

    if(this->opened_apps)
    {
        delete[] this->opened_apps;
    }
}

// OPERATORY ******************************************

bool Monitor::operator==(const Monitor &monitor_to_compare) // operator porownojacy dwa monitory
{
#ifdef _DEBUG
    cout<<"Comparing "<<name_of_model<<" with "<<monitor_to_compare.name_of_model<<endl;
#endif
    return this->name_of_model == monitor_to_compare.name_of_model;
}

Monitor& Monitor::operator=(const Monitor &monitor_to_copy) // przypisanie monitorowi parametrow innego
{
    name_of_model = monitor_to_copy.name_of_model;
    screen_on = monitor_to_copy.screen_on;
    number_of_apps = monitor_to_copy.number_of_apps;
    user = monitor_to_copy.user;

    if(opened_apps) delete[] opened_apps;

    if(number_of_apps > 0)
    {
        opened_apps = new App[number_of_apps];
    }

    for(unsigned int i = 0; i < number_of_apps; i++)
    {
        opened_apps[i] = monitor_to_copy.opened_apps[i];
    }

    return *this;
}

Monitor::operator string() // krotkie info o monitorze w postaci stringa
{
    return name_of_model+(screen_on ? ", on, " : ", off, ")+to_string(number_of_apps)+", "+user.get_name()+", "+to_string(user.get_age());
}

App* Monitor::operator[](unsigned int i) // daje dostep do itej aplikacji
{
    if(i > number_of_apps)
    {
        cout<<"No app with that index";
    }
    return &opened_apps[i];
}

Monitor& Monitor::operator!() // gasi lub zapala ekran
{
    screen_on = !screen_on;
    return *this;
}

ostream & operator<<( ostream &stream , Monitor &monitor ) // wypisuje dane o monitorze
{
    string s_opened_apps = "";
    for(unsigned int i = 0; i < monitor.number_of_apps; i++) // tworzenie listy apki
    {
        s_opened_apps +=  "["+to_string(i)+"]: "+monitor.opened_apps[i].get_name()+"\n";
    }
    return stream<<"model name: "<<monitor.name_of_model<<", "
                 <<(monitor.screen_on ? "screen on" : "screen off")<<", "
                 <<monitor.number_of_apps<<" opened apps, user nickname and age : "
                 <<monitor.user.get_name()<<" "<<monitor.user.get_age()<<endl<<"Opened apps:\n"
                 <<s_opened_apps;
}

// OPERATORY ******************************************

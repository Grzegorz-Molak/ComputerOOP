#include "monitor.h"
#include <fstream>

int Monitor::m_quantity = 0;

// KONSTRUKTORY ****************************************
Monitor::Monitor()
{
    this->m_quantity++;
}

Monitor::Monitor(string name) : Monitor()
{
    m_name = name;
#ifdef _DEBUG
    cout<<"Monitor("<<name<<"), 'Monitor' objects: "<<this->m_quantity<<endl;
#endif
}

// KONSTRUKTORY ****************************************

Monitor::~Monitor()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~Monitor, 'Monitor' objects: "<<this->m_quantity<<endl;
#endif
}

// OPERATORY ******************************************

ostream & operator<<( ostream &s , const Monitor& monitor)
{
    s << *(dynamic_cast<const Electronic*>(&monitor));
    s<<"Przekatna: "<<monitor.m_diagonal<<endl;
    s<<"Jasnosc: "<<monitor.m_brightness<<endl;
    s<<"Apps: "<<monitor.m_apps.size()<<endl;

    stack<App> apps = monitor.m_apps;

    if(apps.empty()) cout<<" | BRAK"<<endl;
    else
    {
        while(!apps.empty())
        {
            s<<"App: "<<apps.top()<<endl;
            apps.pop();
        }
    }
return s;
}

istream & operator>>( istream &s , Monitor& monitor)
{
return s >> monitor.m_brightness;
}

double Monitor::diagonal() const
{
    return m_diagonal;
}

void Monitor::setDiagonal(double diagonal)
{
    m_diagonal = diagonal;
}

unsigned int Monitor::getBrightness() const
{
    return m_brightness;
}

void Monitor::setBrightness(unsigned int value)
{
    m_brightness = value;
}

void Monitor::switchPower()
{
#ifdef _DEBUG
    cout<<"Calling switchPower in Monitor class"<<endl;
#endif
    if(this->m_power == false)
    {
        this->m_power = true;
        this->m_apps.emplace("Hello World");
    }
    else
    {
        this->m_power = false;
        this->m_apps.pop();
    }
}

void Monitor::save()
{
    ofstream file;
    file.open(m_name+".txt", ios_base::out);

    if(file)
    {
        cout<<"udalo sie utworzyc plik"<<endl;
        save(file);
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie utworzyc pliku"<<endl;
        return;
    }

    save(file);
    file.close();
}

void Monitor::save(ostream& file)
{
    Electronic::save(file);
    file<<"Przekatna: "<<m_diagonal<<endl;
    file<<"Jasnosc: "<<m_brightness<<endl;
    file<<"Apps: "<<m_apps.size()<<endl;

    stack<App> apps = m_apps;

    if(apps.empty()) cout<<" | BRAK"<<endl;
    else
    {
        while(!apps.empty())
        {
            file<<"App: "<<apps.top()<<endl;
            apps.pop();
        }
    }
   // file<<*this;
}

void Monitor::read()
{
    string namefile;
    ifstream file;
    cout<<"Prosze podac nazwe pliku: "<<endl;
    cin>>namefile;
    file.open(namefile, ios_base::in);
    if(file)
    {
        cout<<"udalo sie otworzyc plik"<<endl;
        read(file);
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        return;
    }

}

void Monitor::read(istream& file)
{
    Electronic::read(file);
    while(!m_apps.empty())
    {
        m_apps.pop();
    }

    App app;
    stack<App> helpApp;
    string title;
    string AppName;
    int AppsQuantity = 0;

    file>>title;
    if(title == "Przekatna:") file>>m_diagonal;
    file>>title;
    if(title == "Jasnosc:") file>>m_brightness;
    file>>title;
    if(title == "Apps:") file>>AppsQuantity;

    for(int i = 0; i < AppsQuantity; i++)
    {
    file>>title;
    if(title != "App:") continue;
    getline(file, AppName);
    app.setName(AppName);
    helpApp.push(app);
    }

    while(!helpApp.empty())
    {
        m_apps.push(helpApp.top());
        helpApp.pop();
    }
}



void Monitor::openApp(string name)
{
#ifdef _DEBUG
    cout<<"Calling openApp in Monitor class"<<endl;
#endif
    if(m_power)
    {
    this->m_apps.pop();
    this->m_apps.emplace(name);
    }
    else
    {
        if(askToTurnOn())
        {
            switchPower();
            openApp(name);
        }
    }
}

void Monitor::closeApp()
{
#ifdef _DEBUG
    cout<<"Calling closeApp in Monitor class"<<endl;
#endif
    if(m_power)
    {
        this->m_apps.pop();
        if(m_apps.empty())
        {
            this->m_apps.emplace("Hello World");
        }
    }
    else
    {
        cout<<"Monitor jest wylaczony, nie ma zadnych otwartych afileacji"<<endl;
    }

}






// OPERATORY ******************************************

#include "monitor.h"
#include "useful.h"
#include <fstream>

int Monitor::m_quantity = 0;

// KONSTRUKTORY ****************************************
Monitor::Monitor()
{
    this->m_quantity++;
#ifdef _DEBUG
    cout<<"Monitor("<<m_name<<", 'Monitor' objects: "<<this->m_quantity<<endl;
#endif
}

Monitor::Monitor(string name) : Monitor()
{
    m_name = name;
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

    if(!apps.empty())
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
    s >> *(dynamic_cast<Electronic*>(&monitor));
    while(!monitor.m_apps.empty())
    {
        monitor.m_apps.pop();
    }

    App app;
    stack<App> helpApp;
    string title;
    string AppName;
    int AppsQuantity = 0;

    s>>title>>monitor.m_diagonal;
    s>>title>>monitor.m_brightness;
    s>>title>>AppsQuantity;

    for(int i = 0; i < AppsQuantity; i++)
    {
    s>>title;
    getline(s, AppName);
    app.setName(AppName);
    helpApp.push(app);
    }

    while(!helpApp.empty())
    {
        monitor.m_apps.push(helpApp.top());
        helpApp.pop();
    }
    return s;
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
        cout<<"Wlaczam monitor, otwieram standardowa aplikacje Hello World"<<endl;
        this->m_power = true;
        this->m_apps.emplace("Hello World");
    }
    else
    {
        cout<<"Wylaczam monitor, zamykam aplikacje"<<endl;
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
        file<<"Monitor"<<endl;
        file<<*this;
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie utworzyc pliku"<<endl;
        return;
    }
}

int Monitor::read()
{
    string namefile;
    ifstream file;
    cout<<"Prosze podac nazwe pliku: "<<endl;
    cin>>namefile;
    file.open(namefile, ios_base::in);
    if(file)
    {
        cout<<"udalo sie otworzyc plik"<<endl;
        file>>namefile;
        if(namefile == "Monitor")
        {
            file>>*this;
        }
        else
        {
            cout<<"Do monitora moze byc przypisany tylko monitor"<<endl;
            return 0;
        }
        file.close();
        return 1;
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        return 0 ;
    }

}

void Monitor::openApp(string name)
{
#ifdef _DEBUG
    cout<<"Calling openApp in Monitor class"<<endl;
#endif
    cout<<"Otwieram "<<name<<" i zamykam "<<m_apps.top().name()<<endl;
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
    cout<<"Zamykam "<<m_apps.top().name()<<endl;
    if(m_power)
    {
        this->m_apps.pop();
        if(m_apps.empty())
        {
            cout<<"Otwieram standardowa aplikacje Hello World"<<endl;
            this->m_apps.emplace("Hello World");
        }
    }
    else
    {
        cout<<"Monitor jest wylaczony, nie ma zadnych otwartych aplikacji"<<endl;
    }

}

void Monitor::print()
{
   cout<<*this;
}

void Monitor::edit()
{
  Electronic::edit();
  string text;
  cout<<"Nowa przekatna( <0 ,100>: "<<endl;
      m_diagonal = getInt(0,100);
  cout<<"Nowa jasnosc( <0,100>): "<<endl;
      m_brightness = getInt(0,100);

   stack<App> apps;
   while(!m_apps.empty())
   {
     cout<<"Nowa nazwa apikacji: "<<endl;
     cin>>text;
     apps.emplace("text");
     m_apps.pop();
   }
   while(!apps.empty())
   {
       m_apps.emplace(apps.top());
       apps.pop();
   }
}

int Monitor::functions()
{
  Electronic::functions();
  cout<<"2. Otworz nowa aplikacje"<<endl;
  cout<<"3. Zamknij aplikacje"<<endl;
  return 2;
}




// OPERATORY ******************************************

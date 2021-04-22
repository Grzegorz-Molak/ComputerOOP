#pragma once
#include <string>
#include "user.h"

using namespace std;

class Electronic
{
public:
    Electronic();
    virtual ~Electronic();


    bool power() const;
    virtual void switchPower() = 0;

    string name() const;
    void setName(const string &name);

    User user() const;
    void setUser(const User &user);

    static int quantity();

    friend ostream & operator<<( ostream &s , const Electronic& electronic);
    friend istream & operator>>( istream &s , Electronic& electronic);
protected:
    bool m_power = 0;
    string m_name = "unknown";
    User m_user;

 private:
    static int m_quantity;
};

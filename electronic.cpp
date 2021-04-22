#include "electronic.h"

int Electronic::m_quantity = 0;

Electronic::Electronic()
{
    this->m_quantity++;
#ifdef _DEBUG
    cout<<"Electronic(), 'Electronic' objects: "<<m_quantity<<endl;
#endif
}

Electronic::~Electronic()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~Electronic(), 'Electronic' objects: "<<m_quantity<<endl;
#endif
}

ostream & operator<<( ostream &s , const Electronic& electronic)
{
return s << electronic.m_name <<" | "<< electronic.m_power <<" | "<< electronic.m_user;
}
istream & operator>>( istream &s , Electronic& electronic)
{
return s >> electronic.m_name >> electronic.m_power >> electronic.m_user;
}

bool Electronic::power() const
{
    return m_power;
}

string Electronic::name() const
{
    return m_name;
}

void Electronic::setName(const string &name)
{
    m_name = name;
}

User Electronic::user() const
{
    return m_user;
}

void Electronic::setUser(const User &user)
{
    m_user = user;
}


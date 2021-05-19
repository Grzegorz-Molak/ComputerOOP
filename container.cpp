
Node<T> *Container::begin() const
{
    return m_begin;
}

void Container::setBegin(Node<T> *begin)
{
    m_begin = begin;
}

Node<T> *Container::end() const
{
    return m_end;
}

void Container::setEnd(Node<T> *end)
{
    m_end = end;
}

void Container::setSize(int size)
{
    m_size = size;
}

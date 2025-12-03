

template<typename T>
Array<T>::Array() :
    _size(0),
    _data(NULL)
{

}

template<typename T>
Array<T>::Array(unsigned int n) :
    _size(n)
{
    _data = new T[_size];
}

template<typename T>
Array<T>::Array(const Array<T> &other) :
    _size(other._size),
    _data(NULL)
{
    _data = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
    {
        _data[i] = other._data[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return _data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return _data[index];
}
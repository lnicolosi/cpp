
template<typename T>
typename T::const_iterator easyfind(const T &container, int n)
{
    //dois trouver la 1ere occurence de n dans le container
    typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    return it; 
}
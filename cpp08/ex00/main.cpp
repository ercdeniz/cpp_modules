#include "easyfind.hpp"

template <typename T>
T createAndFillContainer(int size)
{
    T container;
    for (int i = 0; i < size; ++i)
        container.push_back(std::rand() % 10);
    return container;
}

template <typename T>
std::string findResult(T& container, int searchValue)
{
    try
    {
        easyfind(container, searchValue);
        return GREEN "Found" RESET;
    }
    catch (const std::exception&)
    {
        return RED "Not Found" RESET;
    }
}

template <typename T>
void containerResult(const std::string& name, T& container, int searchValue1, int searchValue2)
{
    std::cout << MAGENTA << "\n     --- Testing " << name << " ---" << RESET << std::endl;

    std::cout << YELLOW << "Container contents: " << RESET;
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << "[" << BLUE << *it << RESET << "] ";
    std::cout << "\n\n";

    std::cout << CYAN "  Search Value      Result    " RESET << std::endl;
    std::cout << "+--------------+--------------+" << std::endl;

    std::string result1 = findResult(container, searchValue1);
    std::string result2 = findResult(container, searchValue2);

    std::cout << "|    " << std::setw(4) << searchValue1 << "      |" << std::setw(22) << result1 << "   |" << std::endl;
    std::cout << "+--------------+--------------+" << std::endl;
    std::cout << "|    " << std::setw(4) << searchValue2 << "      |" << std::setw(22) << result2 << "   |" << std::endl;
    std::cout << "+--------------+--------------+" << std::endl;
}

int main()
{
    int size = 5;
    std::srand(std::time(0));
    std::vector<int> vec = createAndFillContainer<std::vector<int> >(size);
    std::deque<int> deq = createAndFillContainer<std::deque<int> >(size);
    std::list<int> lst = createAndFillContainer<std::list<int> >(size);

    containerResult("vector", vec, 2, 5);
    containerResult("deque", deq, 0, 7);
    containerResult("list", lst, 6, 9);

    return 0;
}
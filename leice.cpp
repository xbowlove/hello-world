#include <iostream>

template <typename T>
class Entity
{
public:
    Entity(T t)
    {
        std::cout << t << std::endl;
    }
    void PrintClassName()
    {
        std::cout << "this is Entity !" << std::endl;
    }
};

int main()
{
    Entity<double> entity(10.4); // 方式 1
    entity.PrintClassName();
    Entity<double> *entity2 = new Entity<double>(20.4); // 方式 2
    entity2->PrintClassName();
    Entity<double> entity3 = Entity<double>(30.4); // 方式 3
    entity3.PrintClassName();
    std::cin.get();
}
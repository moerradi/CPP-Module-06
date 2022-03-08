#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t ptr)
{
	return reinterpret_cast<Data*>(ptr);
}

int main()
{
	Data	*data = new Data();
	data->str = "Hello World";
	data->n = 42;
	data->b = true;
	uintptr_t	ptr = serialize(data);
	std::cout << ptr << std::endl;
	Data	*data2 = deserialize(ptr);
	std::cout << data2->str << std::endl;
	std::cout << data2->n << std::endl;
	std::cout << data2->b << std::endl;
	return 0;
}
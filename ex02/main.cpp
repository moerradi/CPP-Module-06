#include "Base.hpp"

Base* generate(void) {
	srand(time(NULL));
	int r = rand() % 3;
	if (r == 0)
		return new A;
	else if  (r == 1)
		return new B;
	else
		return new C;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}
void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast &e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::bad_cast &e) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::bad_cast &e) {
				std::cout << "unknown" << std::endl;
			}
		}
	}
}
int main()
{
	Base *p = generate();
	identify(p);
	identify(*p);
}
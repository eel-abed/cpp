#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pmerge;
	
	if (!pmerge.run(argc, argv))
		return 1;
	
	return 0;
}

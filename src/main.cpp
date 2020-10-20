#include "GameController.h"
#include "LoadResources.h"
using namespace std;
int main()
{
	LoadResources resource;
	GameController m(resource);
	m.startPlay();

	return EXIT_SUCCESS;
}
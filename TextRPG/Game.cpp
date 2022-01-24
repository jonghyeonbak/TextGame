#include "Include.h"
#include "MainGame.h"

int main()
{
	CMainGame mainGame;

	if (mainGame.Initialize())
		mainGame.Progress();

	int* ptr = new int;
	delete ptr;

	return 0;
}
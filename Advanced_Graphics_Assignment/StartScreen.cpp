#include "StartScreen.h"

StartScreen::StartScreen()
{
	//Title of Game:



	//Backdrop Of StartScreen


	
	//png of selector




}

StartScreen::~StartScreen()
{



}

void StartScreen::ChangeSelectedMode(int change)
{
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	//selecting between credits screen and starting the game


	//code for pointer positions
}

int StartScreen::SelectedMode() 
{
	return mSelectedMode;
}

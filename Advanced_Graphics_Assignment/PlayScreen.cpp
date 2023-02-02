#include "PlayScreen.h"


PlayScreen::PlayScreen()
{
	m_pBackdrop = new Texture("Assets/Textures/Carnvial Set Base.jpg", .3, .3, .3, -.3, -.3, -.3, -.3, .3, GL_RGBA);
}

PlayScreen::~PlayScreen()
{
	delete m_pBackdrop;
	m_pBackdrop = nullptr;

}

void PlayScreen::Update()
{


}

void PlayScreen::Render()
{
	m_pBackdrop->Draw();
}

#ifndef HUD_H
#include "Font.h"


class HUD {
public:

	HUD();
	~HUD();

	void draw();

	// Setter methods to update the position, color, etc. of the text
	void setPosition(const glm::vec2& position);
	void setColor(const glm::vec3& color);
	// Add other setter methods as needed

private:
	Font* m_pFont;
	glm::vec2 position;
	glm::vec3 color;

	// Add other member variables as needed
};

#endif

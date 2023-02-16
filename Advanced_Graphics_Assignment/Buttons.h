#include "Texture.h"
#include "freetype/freetype.h"
#include "ft2build.h"
#include "Font.h"
#include FT_FREETYPE_H

class Buttons {
public:

    Buttons();
	~Buttons();

    void Update();
    void Render();
    void Draw();

private:
    Font* m_pFont;
    Texture* m_pReturnToMenuButton;
};


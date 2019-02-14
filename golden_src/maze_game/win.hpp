#ifndef WIN_HPP
#define WIN_HPP

#include "../renderer/interlayer.h"

class WinWindow : public LeInterLayer
{
public:
        void draw();
        void on_mouse_clicked();
};

#endif

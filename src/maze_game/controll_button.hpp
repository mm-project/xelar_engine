#include "../skeleton/image_object.h"

class ControlButton  : public LeImageObject
{
    public:          
            ControlButton(int image_id):LeImageObject(image_id, 50,50,1,1) {
            }
};

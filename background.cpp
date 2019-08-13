#include "background.h"

BackGround::BackGround()
{
    triggered = false;
}

void BackGround::run()
{
    while (1)
    {
        while (triggered == false)
            ;
        triggered = false;
        emit Generator();
    }
}

void BackGround::Trigger(void)
{
    triggered = true;
}


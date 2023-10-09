/**
\file        Input.cpp
\author      hyun.gang
\par         email: hangam131313@gmail.com
\brief
        This file will return the user's key
        input.

        copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved
*/

#include "windows.h"
#include "Input.h"
#include "Sound_Manager.h"

bool IsKeyDown(int Key)
{
    return ((GetAsyncKeyState(Key) & 0x0001) != 0);
}
//return the keyboard input with test GetAsyncKeyState.

int User_Input()
{
    if (IsKeyDown(VK_LEFT))
    {
        return LEFT;
    }
    else if (IsKeyDown(VK_RIGHT))
    {
        return RIGHT;
    }
    else if (IsKeyDown(VK_UP))
    {
        return UP;
    }
    else if (IsKeyDown(VK_DOWN))
    {
        return DOWN;
    }
    else if (IsKeyDown(VK_SPACE))
    {
        return SPACE;
    }
    else if (IsKeyDown(VK_ESCAPE))
    {
        return ESC;
    }
    else if (IsKeyDown(VK_CONTROL))
    {
        return CTR;
    }
    else if (IsKeyDown(VK_RETURN))
    {
        return ENTER;
    }
    else if (IsKeyDown(0x41))
    {
        return A;

    }
    else if (IsKeyDown(0x51))
    {
	return QUIT_;
    }
    else if (IsKeyDown(0x45))
    {
        return E;
    }
    else if (IsKeyDown(0x52))
    {
	return RESTART_;
    }
    else if (IsKeyDown(0x42))
    {
	return BOSS_;
    }
    return 0;

}

#include <SDL.h>
#include "GENERAL.H"
#include "KEYBOARD.H"
#include "MOUSEMOD.H"

static T_buttonClick G_mouseButton = 0 ;
static T_word16 G_mouseX = 0 ;
static T_word16 G_mouseY = 0 ;

T_void DirectMouseSet(T_word16 newX, T_word16 newY)
{
    newX >>= 1;
    newY >>= 1; // scale for large screen
    if (newX > 319)
        newX = 319  ;
    if (newY > 199)
        newY = 199 ;
    G_mouseX = newX ;
    G_mouseY = newY ;
}


void OutsideMouseDriverGet(T_word16 *xPos, T_word16 *yPos)
{
    *xPos = G_mouseX ;
    *yPos = G_mouseY ;
}

void OutsideMouseDriverSet(T_word16 xPos, T_word16 yPos)
{
    SDL_WarpMouse(xPos*2, yPos*2);
    DirectMouseSet(xPos*2, yPos*2);
}

T_void DirectMouseSetButton(T_buttonClick click)
{
    G_mouseButton = click ;
}

T_buttonClick DirectMouseGetButton(T_void)
{
    return G_mouseButton ;
}

extern void WindowsUpdate(char *p_screen, char *palette);

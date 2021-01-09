
#include <windows.h>
#include <winuser.h>
#include <iostream>
using namespace std;


int main() {

    cout << "dead by daylight flashlight auto-clicker" << endl;
    cout << "by warrenjay a.k.a castor troy" << endl;
    cout << "instructions: " << endl;
    cout << "open dead by daylight, equip flashlight " << endl; 
    cout << "press E to start / right mouse twice to end" << endl; 
    cout << "\n" << endl;
    cout << "WARNING: this program runs in background and simply clicks your mouse" << endl;

    bool status = false; 
    int count = 0; 

    while (true) {
        /* 0x8000 first bit is 1 if button is down */
        /* 0x0 if buttn is up */
        /* last bit is toggled for capslock/numlock */
        /* 0x8000 is 1000 0000 in binary */
        /* 0x45 is the E  on the keyboard */ 
         
        if (GetKeyState(0x45) & 0x8000)  {
             status = true;  
             if (count < 1) {
               cout << "pressing right mouse..." << endl;
             }
        }

        if (status == true) {

            count++; 
            INPUT mouse; 
            mouse.type = INPUT_MOUSE;
            mouse.mi.dx=0; mouse.mi.dy=0; 
            mouse.mi.mouseData = XBUTTON2;
            mouse.mi.dwExtraInfo = 0;
            mouse.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
            SendInput(1, &mouse, sizeof(INPUT));
            ZeroMemory(&mouse, sizeof(INPUT));
            Sleep(10); 
            /* release */
            mouse.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &mouse, sizeof(INPUT));
            ZeroMemory(&mouse, sizeof(INPUT));


            /* press E again to stop */
            if (GetKeyState(VK_RBUTTON) & 0x8000) {
                cout << "stopped pressing ..." << endl;
                count = 0; 
                status = false;
            }
        }
    }
}

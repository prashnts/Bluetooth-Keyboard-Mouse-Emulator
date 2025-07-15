#ifndef USBHID_H
#define USBHID_H

#include "USBHIDMouse.h"
#include "USBHIDKeyboard.h"
#include <M5Cardputer.h>

void usbKeyboard();
void handleUsbMode(bool mouseMode);
int trackballMouse();
#endif
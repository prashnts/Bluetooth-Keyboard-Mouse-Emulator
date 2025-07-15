#include "usbHid.h"
#include "trackball.h"

USBHIDMouse mouse;
USBHIDKeyboard keyboard;

void handleUsbMode(bool mouseMode) {
    trackballMouse();
    delay(5);
    usbKeyboard();
    delay(5);
}

int trackballMouse() {
    mouse.begin();
    int moveX = 0;
    int moveY = 0;
    Keyboard_Class::KeysState keystatus = M5Cardputer.Keyboard.keysState();

    bool fn_pressed = M5Cardputer.Keyboard.isPressed() && keystatus.fn;
    int speed = fn_pressed ? 2 : 6;

    if (trackball.changed()) {
        moveX = (trackball.left() - trackball.right()) * speed;
        moveY = (trackball.up() - trackball.down()) * speed;

        if(trackball.click()) {
            mouse.press(fn_pressed ? MOUSE_BUTTON_RIGHT : MOUSE_BUTTON_LEFT);
        }
        else if(trackball.release()) {
            mouse.release(MOUSE_BUTTON_LEFT);
        }
        if (fn_pressed) {
            // Scroll H and V
            mouse.move(0, 0, moveY, moveX);
        } else {
            mouse.move(moveX, moveY);
        }
    } else if (M5Cardputer.BtnA.isPressed()) {
        mouse.press(MOUSE_BUTTON_RIGHT);
    } else {
        mouse.release(MOUSE_BUTTON_LEFT);
        mouse.release(MOUSE_BUTTON_RIGHT);
        return 1;
    }
    return 0;
}


void usbKeyboard() {
    keyboard.begin();
    if (M5Cardputer.Keyboard.isChange()) {
        if (M5Cardputer.Keyboard.isPressed()) {
            Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();
            KeyReport report = {0};
            report.modifiers = status.modifiers;
            uint8_t index    = 0;

            if (status.opt) {
                // Command key, Left GUI.
                report.modifiers |= (1 << (KEY_LEFT_GUI - 0x80));
            }

            for (auto i : status.hid_keys) {
                if (status.fn) {
                    if (i == 0x38) {            // '.' -> RT
                        report.keys[index] = KEY_RIGHT_ARROW - 0x88;
                    } else if (i == 0x36) {     // ',' -> LT
                        report.keys[index] = KEY_LEFT_ARROW - 0x88;
                    } else if (i == 0x33) {     // ';' -> UP
                        report.keys[index] = KEY_UP_ARROW - 0x88;
                    } else if (i == 0x37) {     // '.' -> DN
                        report.keys[index] = KEY_DOWN_ARROW - 0x88;
                    } else if (i == 0x35) {     // '`' -> ESC
                        report.keys[index] = 0x29;
                    }
                } else {
                    report.keys[index] = i;
                }
                index++;
                if (index > 5) {
                    index = 5;
                }
            }

            keyboard.sendReport(&report);
            keyboard.releaseAll();
        }
    }
}
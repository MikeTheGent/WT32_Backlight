# WT32-SC01 Backlight Brightness
This is a very simple project which shows the control of the WT32-SC01 backlight brightness. I couldn't find anything on-line which explained how to control the backlight and it took some trial and error to find the correct pin. I thought I would try and save others the bother by sharing this example. 

The WT32-SC01 is an interesting and useful 3.5" TFT touch screen with built in ESP32. It is available from aliexpress.com and other suppliers for less than £$€30. The glass on the screen is thin and fragile, and the device needs to be handled carefully. There is a serious error in the wiring of the USB-C connector which means the device can only be powered by a cable with USB-A on the other end. The error can be corrected with some frighteningly careful soldering: see [WT32-SC01 USB C power fix](https://sl-alex.net/hw/2022/06/22/WT32-SC01_USB_C_power_fix/).

The more recent WT32-SC01 Plus has an ESP32 S3.

The project is structured for PlatformIO and VS Code, using the excellent TFT_eSPI library. The essential lines could easily be incorporated into another environment:

## Initialisation
```
ledcSetup(backlightChannel, 100, 8);
ledcAttachPin(23, backlightChannel);
```
Where `backlightChannel` is a `uint8_t`. The number of LEDC channels varies between different ESP32 revisions, but the minimum appears to be 6. This example sets the resolution to 8 bits and the frequency to 100. See [https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/ledc.html](https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/ledc.html) for more about LED Control.

## Brightness
```
ledcWrite(backlightChannel, brightness);
```

Where `backlightChannel` is the channel attached in initialisation and `brightness` is, in this example, 0 to 255.

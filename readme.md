# WT32-SC01 Backlight Brightness
This is a very simple project which shows the control of the WT32-SC01 backlight brightness. I couldn't find anything on-line which explained how to control the backlight and it took some trial and error to find the correct pin. I thought I would try and save others the bother by sharing this example. 

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
/* A-Maze
 by Alojz Jakob <http://jakobdesign.com>

 ********** TAMAGUINO ***********
 * Maze game for Arduino *
 ********************************
 
*/

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>


// make an instance of arduboy used for many functions
Arduboy2 arduboy;


ArduboyPlaytune tunes(arduboy.audio.enabled);

const unsigned int FRAME_RATE = 25;


 // 'title', 128x64px
const unsigned char title1 [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x60, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0x20, 0x60, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xd0, 0x68, 0xf4, 0x5a, 0xbe, 0xd5, 0xad, 0x95, 0xa9, 0x94, 0x29, 0x01, 0x29, 0x03, 0xa2, 0x04, 0x48, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0x0c, 0xb6, 0x5a, 0xaf, 0x52, 0xa6, 0x4c, 0x18, 0x30, 0x20, 0x20, 0x10, 0x68, 0xb4, 0x5a, 0xad, 0x56, 0x2a, 0x40, 0x00, 0x01, 0xff, 0x00, 0x00, 0x80, 0x40, 0x20, 0xa0, 0x20, 0xb0, 0x10, 0x10, 0x10, 0x1f, 0x38, 0x22, 0x67, 0xa3, 0x25, 0x22, 0x25, 0x22, 0x25, 0x20, 0x22, 0xa0, 0x61, 0x04, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x11, 0x0d, 0x86, 0x60, 0x58, 0xac, 0x5a, 0xaf, 0x52, 0x05, 0x4a, 0x00, 0x89, 0x80, 0x82, 0x80, 0x81, 0x80, 0xc0, 0x40, 0x40, 0x20, 0x11, 0x0e, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7c, 0x03, 0x24, 0x01, 0x0b, 0x41, 0x00, 0x3f, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0xce, 0x78, 0x00, 0x40, 0x00, 0x00, 0x00, 0xe0, 0x31, 0xdf, 0xd0, 0x50, 0x90, 0x50, 0x90, 0x50, 0x10, 0x50, 0x10, 0x90, 0x1c, 0x37, 0xe0, 0x02, 0x00, 0x01, 0x02, 0x01, 0x0a, 0x00, 0x29, 0x00, 0x00, 0x80, 0xc0, 0x60, 0xa0, 0x62, 0xc0, 0x08, 0x81, 0x60, 0x30, 0x88, 0x27, 0x52, 0x0d, 0xf6, 0x1b, 0x09, 0x0c, 0x05, 0x04, 0x0c, 0x19, 0xd0, 0x70, 0x00, 0x00, 0x00, 0x80, 0x43, 0xa6, 0x58, 0xa8, 0x54, 0x3a, 0x15, 0x00, 0x00, 0x00, 0xe0, 0x38, 0x06, 0x03, 0x80, 0x60, 0x18, 0x06, 0x01, 0x02, 0x01, 0x12, 0x40, 0x08, 0x01, 0x00, 0x00, 0x00, 0x13, 0x04, 0x14, 0x04, 0x04, 0x04, 0x8c, 0xfc, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x82, 0x82, 0xc2, 0xc2, 0x8a, 0x81, 0x05, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x05, 0xfc, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x85, 0xfc, 0x04, 0x06, 0x03, 0x01, 0x00, 0x80, 0x60, 0x18, 0x07, 0x03, 0x02, 0x06, 0x04, 0x02, 0x01, 0x00, 0x00, 0xc0, 0x3f, 0x0d, 0x03, 0x00, 0x00, 0x00, 0x02, 0x80, 0x41, 0x20, 0x23, 0x66, 0x44, 0x88, 0x98, 0x10, 0x08, 0x27, 0x01, 0x08, 0x00, 0x3e, 0x63, 0xc0, 0x82, 0x08, 0x01, 0x04, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x07, 0x04, 0x08, 0x08, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x30, 0xe0, 0x00, 0x00, 0x00, 0x5f, 0x11, 0x31, 0x21, 0x21, 0x21, 0x61, 0xc1, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0c, 0x18, 0x10, 0x30, 0x20, 0x30, 0x10, 0x18, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x1c, 0x30, 0x20, 0x20, 0x20, 0x10, 0x18, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x20, 0x20, 0x20, 0x18, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x46, 0x41, 0x40, 0x40, 0x20, 0x50, 0x48, 0x44, 0x32, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x08, 0x18, 0x30, 0x20, 0x20, 0x20, 0x21, 0x31, 0x12, 0x0c, 0x08, 0x08, 0x08, 0x18, 0x10, 0x10, 0x10, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x0f, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0c, 0x06, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x94, 0x94, 0x68, 0x00, 0x1c, 0x3c, 0xf0, 0x20, 0x1c, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0x24, 0x24, 0xf8, 0x00, 0xfc, 0xfc, 0x80, 0x80, 0x00, 0x78, 0xfc, 0x84, 0x84, 0x78, 0x00, 0x60, 0xe0, 0x80, 0x80, 0x7c, 0x00, 0xc4, 0xe4, 0xb4, 0x9c, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
 // 'title2', 128x64px
const unsigned char title2 [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x40, 0x00, 0x40, 0x20, 0x00, 0xa0, 0x00, 0xa0, 0x00, 0x20, 0x40, 0x00, 0x40, 0x00, 0x40, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x40, 0xa0, 0x50, 0xaa, 0x55, 0xa8, 0x15, 0xa8, 0x14, 0x28, 0x01, 0x28, 0x01, 0xa2, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x04, 0xa2, 0x50, 0xaa, 0x50, 0xa2, 0x44, 0x08, 0x10, 0x20, 0x00, 0x00, 0x40, 0xa0, 0x50, 0xa8, 0x54, 0x2a, 0x40, 0x00, 0x01, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0xa0, 0x10, 0x00, 0x10, 0x0a, 0x10, 0x22, 0x45, 0xa2, 0x05, 0x22, 0x05, 0x22, 0x05, 0x20, 0x00, 0xa0, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x11, 0x08, 0x04, 0x20, 0x50, 0xa8, 0x50, 0xaa, 0x50, 0x00, 0x40, 0x00, 0x01, 0x80, 0x00, 0x80, 0x01, 0x80, 0x40, 0x00, 0x40, 0x20, 0x11, 0x0a, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x01, 0x20, 0x01, 0x0a, 0x41, 0x00, 0x15, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x8a, 0x50, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x20, 0x55, 0x80, 0x50, 0x80, 0x50, 0x80, 0x50, 0x00, 0x50, 0x00, 0x10, 0x08, 0x15, 0xa0, 0x00, 0x00, 0x01, 0x02, 0x01, 0x0a, 0x00, 0x28, 0x00, 0x00, 0x00, 0x80, 0x40, 0xa0, 0x40, 0x80, 0x00, 0x80, 0x40, 0x20, 0x00, 0x22, 0x50, 0x08, 0x54, 0x0a, 0x01, 0x08, 0x05, 0x00, 0x04, 0x08, 0x50, 0x20, 0x00, 0x00, 0x00, 0x80, 0x41, 0xa2, 0x50, 0xa8, 0x54, 0x2a, 0x15, 0x00, 0x00, 0x00, 0x40, 0x28, 0x04, 0x02, 0x00, 0x20, 0x10, 0x02, 0x01, 0x02, 0x01, 0x02, 0x40, 0x08, 0x01, 0x00, 0x00, 0x00, 0x11, 0x00, 0x14, 0x00, 0x04, 0x00, 0x04, 0xa8, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x82, 0x00, 0x82, 0x40, 0x8a, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x05, 0xa8, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0xa8, 0x04, 0x02, 0x01, 0x00, 0x00, 0x80, 0x40, 0x08, 0x05, 0x02, 0x00, 0x02, 0x04, 0x02, 0x01, 0x00, 0x00, 0x80, 0x15, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x41, 0x20, 0x01, 0x22, 0x44, 0x88, 0x10, 0x00, 0x00, 0x22, 0x01, 0x08, 0x00, 0x2a, 0x41, 0x80, 0x00, 0x08, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x08, 0x15, 0x00, 0x10, 0x00, 0x10, 0x20, 0x40, 0x00, 0x00, 0x00, 0x55, 0x00, 0x11, 0x20, 0x01, 0x20, 0x41, 0x80, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x08, 0x10, 0x20, 0x00, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x20, 0x00, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x41, 0x00, 0x40, 0x20, 0x50, 0x08, 0x44, 0x22, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x00, 0x08, 0x10, 0x20, 0x00, 0x20, 0x01, 0x20, 0x10, 0x08, 0x00, 0x08, 0x00, 0x08, 0x10, 0x00, 0x10, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x05, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x54, 0x80, 0x14, 0x28, 0x00, 0x08, 0x14, 0xa0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xa8, 0x54, 0x20, 0x04, 0xa8, 0x00, 0xa8, 0x54, 0x80, 0x00, 0x00, 0x50, 0xa8, 0x04, 0x80, 0x50, 0x00, 0x40, 0xa0, 0x00, 0x80, 0x54, 0x00, 0x44, 0xa0, 0x14, 0x88, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

 // 'title3', 128x64px
const unsigned char title3 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xa0, 0x50, 0xaa, 0x54, 0xa8, 0x15, 0xa8, 0x14, 0x28, 0x01, 0x28, 0x01, 0xa0, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0xa2, 0x50, 0xa8, 0x50, 0xa2, 0x40, 0x00, 0x10, 0x00, 0x00, 0x00, 0x40, 0xa0, 0x50, 0xa8, 0x54, 0x2a, 0x40, 0x00, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0xa0, 0x10, 0x00, 0x10, 0x08, 0x10, 0x22, 0x45, 0x82, 0x05, 0x22, 0x05, 0x02, 0x05, 0x20, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x20, 0x50, 0xa8, 0x50, 0xaa, 0x50, 0x00, 0x40, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x01, 0x0a, 0x41, 0x00, 0x15, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x8a, 0x50, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x51, 0x80, 0x40, 0x80, 0x50, 0x80, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x01, 0x02, 0x01, 0x0a, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x50, 0x08, 0x14, 0x0a, 0x01, 0x08, 0x05, 0x00, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xa2, 0x40, 0xa0, 0x50, 0x2a, 0x14, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x02, 0x00, 0x20, 0x10, 0x02, 0x01, 0x02, 0x01, 0x02, 0x40, 0x08, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x02, 0x40, 0x0a, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x20, 0x05, 0x00, 0x01, 0x00, 0x05, 0x00, 0x01, 0x88, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x01, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x22, 0x01, 0x08, 0x00, 0x22, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x10, 0x00, 0x00, 0x20, 0x01, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x20, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x20, 0x40, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01, 0x20, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x54, 0x80, 0x14, 0x28, 0x00, 0x08, 0x14, 0xa0, 0x00, 0x08, 0x00, 0x00, 0x00, 0xa8, 0x54, 0x20, 0x04, 0xa8, 0x00, 0xa8, 0x54, 0x80, 0x00, 0x00, 0x50, 0xa8, 0x04, 0x80, 0x50, 0x00, 0x40, 0xa0, 0x00, 0x80, 0x54, 0x00, 0x44, 0xa0, 0x14, 0x88, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

 // 'title4', 128x64px
const unsigned char title4 [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x80, 0x01, 0x80, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x20, 0x10, 0x00, 0x10, 0x08, 0x10, 0x22, 0x40, 0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x20, 0x10, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x14, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x0a, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x11, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xa2, 0x40, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x02, 0x00, 0x20, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x40, 0x08, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x88, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x01, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x22, 0x01, 0x08, 0x00, 0x22, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x10, 0x00, 0x00, 0x20, 0x01, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x20, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x20, 0x40, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01, 0x20, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x88, 0x00, 0x20, 0x00, 0x88, 0x00, 0x20, 0x04, 0x80, 0x00, 0x00, 0x10, 0x80, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x80, 0x14, 0x80, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


/*
const int8_t button1Pin = 9; //LEFT
const int8_t button2Pin = 8; //RIGHT
const int8_t button3Pin = 7; //UP
const int8_t button4Pin = 6; //DOWN
const int8_t button5Pin = 5; //A
const int8_t button6Pin = 4; //B
const int8_t button7Pin = 2; //MENU
*/
//const int8_t sound = 3; 
bool sound_enabled=true;
//const int8_t ledPin = 10; 

/*int8_t button1State = 0;
int8_t button2State = 0;
int8_t button3State = 0;
int8_t button4State = 0;
int8_t button5State = 0;
int8_t button6State = 0;
int8_t button7State = 0;


#define ACTIVATED LOW
*/
#define DELAYMULTIPLIER  0




int8_t posx=0, posy=2; // Where you are in the Maze

int8_t illuminatedRow=0;
int8_t blinkPlayer=1;
int8_t wallPhase=1;

int8_t level=1;

int8_t gameMode=0;
int8_t selectedOption=1;
int8_t menuPointerPos=0;
bool menuPointerPosDir=false,gamePaused=false,escapeGameOver=false;

void setup() {
  
  //Serial.begin(9600);
  
  /*pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);
  pinMode(button7Pin, INPUT);

  digitalWrite(button1Pin, HIGH);
  digitalWrite(button2Pin, HIGH);
  digitalWrite(button3Pin, HIGH);
  digitalWrite(button4Pin, HIGH);
  digitalWrite(button5Pin, HIGH);
  digitalWrite(button6Pin, HIGH);
  digitalWrite(button7Pin, HIGH);
  // or just 
  // pinMode(button1Pin, INPUT_PULLUP)
  // etc
  
//  pinMode( OUTPUT);
 // pinMode(ledPin, OUTPUT);

 // pinMode(13,OUTPUT);*/ 
  arduboy.begin();
  //arduboy.initRandomSeed();
  //randomSeed(analogRead(A4));
  //randomSeed(analogRead(A4)+readVcc());
  arduboy.setFrameRate(FRAME_RATE);
  arduboy.clear();
  arduboy.display();
  // audio setup
  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a DevKit
  tunes.initChannel(PIN_SPEAKER_2);
#else
  // if it's a DevKit
  tunes.initChannel(PIN_SPEAKER_1); // use the same pin for both channels
  tunes.toneMutesScore(true);       // mute the score when a tone is sounding
#endif
  delay(random(2,2000));
  
  arduboy.clear();
  
  // splash
  arduboy.setTextColor(WHITE);
  //arduboy.println(F("jakobdesign presents")); 
  //arduboy.print(F(" generating maze...")); 
  arduboy.drawBitmap(0, 10, title4 , 128, 64, WHITE);
  arduboy.display();
  //digitalWrite(ledPin, HIGH);
  tunes.tone(2200,5);
  //digitalWrite(ledPin, LOW);
  delay(80);
  arduboy.clear();
  arduboy.drawBitmap(0, 5, title3 , 128, 64, WHITE);
  arduboy.display();
  //digitalWrite(ledPin, HIGH);
  tunes.tone(2200,5);
  //digitalWrite(ledPin, LOW);
  delay(80);
  arduboy.clear();
  arduboy.drawBitmap(0, 2, title2 , 128, 64, WHITE);
  arduboy.display();
  //digitalWrite(ledPin, HIGH);
  tunes.tone(2200,5);
  //digitalWrite(ledPin, LOW);
  delay(80);
  arduboy.clear();
  arduboy.drawBitmap(0, 0, title1 , 128, 64, WHITE);
  arduboy.display();
  //digitalWrite(ledPin, HIGH);
  tunes.tone(2200,5);
  //digitalWrite(ledPin, LOW);
  delay(3000);
  arduboy.clear();
  arduboy.drawBitmap(0, 2, title2 , 128, 64, WHITE);
  arduboy.display();
  //digitalWrite(ledPin, HIGH);
  tunes.tone(2200,5);
  //digitalWrite(ledPin, LOW);
  delay(80);
  arduboy.clear();
  arduboy.drawBitmap(0, 5, title3 , 128, 64, WHITE);
  arduboy.display();
  //digitalWrite(ledPin, HIGH);
  tunes.tone(2200,5);
  //digitalWrite(ledPin, LOW);
  delay(80);
  arduboy.clear();
  arduboy.drawBitmap(0, 10, title4 , 128, 64, WHITE);
  arduboy.display();
  //digitalWrite(ledPin, HIGH);
  tunes.tone(2200,5);
  //digitalWrite(ledPin, LOW);
  delay(80);
  arduboy.clear();  
}


void loop() {
    // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;
  /*button1State = arduboy.pressed(LEFT_BUTTON);
  button2State = arduboy.pressed(RIGHT_BUTTON);
  button3State = arduboy.pressed(UP_BUTTON);
  button4State = arduboy.pressed(DOWN_BUTTON);
  button5State = arduboy.pressed(A_BUTTON);
  button6State = arduboy.pressed(B_BUTTON);
  button7State = (arduboy.pressed(LEFT_BUTTON));
  */
  arduboy.pollButtons();
  arduboy.clear();

  if(gameMode==0){

    //arduboy.drawBitmap(0, -20, title1 , 128, 64, WHITE);
    mainMenu();
    displayBattery(WHITE);
    
  }
  if(gameMode==1){
    walker();
    displayBattery(WHITE);
    if(!gamePaused){
      selectedOption=1;
    }
  }
  if(gameMode==2){
    collector();
    displayBattery(WHITE);
    if(!gamePaused){
      selectedOption=1;
    }
  }
  if(gameMode==3){
    escaper();
    displayBattery(WHITE);
    if(!gamePaused and !escapeGameOver){
      selectedOption=1;
    }
  }
  if(gameMode==4){
    dark();
    displayBattery(WHITE);
    if(!gamePaused){
      selectedOption=1;
    }
  }

  displayIndicators(WHITE);
  
  arduboy.display();
  delay(10*DELAYMULTIPLIER);
  
}

void displayIndicators(uint8_t font){
  //speaker
  arduboy.drawLine(103,1,103,6,font);
  arduboy.drawLine(102,1,102,6,font);
  arduboy.drawLine(101,2,101,5,font);
  arduboy.drawLine(100,3,100,4,font);
  arduboy.drawLine(99,3,99,4,font);
  if(sound_enabled){
    arduboy.drawPixel(105,2,font);
    arduboy.drawPixel(106,3,font);
    arduboy.drawPixel(106,4,font);
    arduboy.drawPixel(105,5,font);
  }
  //...
}


void displayBattery(uint8_t font){

  arduboy.setTextColor(font);
  arduboy.setCursor(50,0);
  arduboy.print("vcc:");/////////////////////////////////////
  int batt=readVcc(); 
  arduboy.print(batt);////////////////////////////////////////

  arduboy.drawLine(114,1,125,1,font);
  arduboy.drawLine(114,6,125,6,font);
  arduboy.drawLine(114,1,114,6,font);
  arduboy.drawLine(125,1,125,6,font);
  arduboy.drawLine(126,3,126,4,font);

  if(batt>4350){
    arduboy.drawLine(109,2,109,1,font);
    arduboy.drawLine(111,2,111,1,font);
    arduboy.drawLine(108,3,112,3,font);
    arduboy.drawLine(108,4,112,4,font);
    arduboy.drawPixel(110,5,font);
    arduboy.drawPixel(111,6,font);
    arduboy.drawPixel(112,6,font);
    arduboy.drawPixel(113,6,font);
  }
  //if(batt>2900){
  if(batt>3330){
    arduboy.drawLine(116,3,116,4,font);
    arduboy.drawLine(117,3,117,4,font);
  }
  //if(batt>3000){
  if(batt>3450){
    arduboy.drawLine(119,3,119,4,font);
    arduboy.drawLine(120,3,120,4,font);
  }
  //if(batt>3100){
    if(batt>3800){
    arduboy.drawLine(122,3,122,4,font);
    arduboy.drawLine(123,3,123,4,font);
  }
    
}

 int readVcc() {
//  delayShort(1000);
  //arduboy.initRandomSeed();//dont think needed
  power_adc_enable();// ADC on
  int result; // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // wait for Vref to settle after the mux change
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
 // result = ADCL;
  //result |= ADCH<<8;
  result = ADCW;//use ADCW to get the upper and lower registers in one
  result = 1125300L / result -249;// AVcc in mV = 1.1*1023*1000 = 1125300
  // Back-calculate AVcc in mV
  return result;
  power_adc_disable(); // ADC off
}

/*void tunes.tone(uint8_t pin,int freq,int duration){
  if(sound_enabled){
    tone(pin,freq,duration);  
  }
}*/

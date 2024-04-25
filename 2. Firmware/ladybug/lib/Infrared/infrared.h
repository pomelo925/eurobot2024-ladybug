#ifndef _VL53_H_
#define _VL53_H_

// This array will store the amount of cake in that position.
extern int VL53_data[3];
extern int VL53mode;

void setID();
void VL53_setup();
void read_VL53s();
void print_VL53s();

#endif

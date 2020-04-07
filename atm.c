#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  unsigned int denomination_count = 0x0;
   unsigned short int notes[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned short int remaining_amount = amount;
  
  for (int i = 0; i < 8; i++){
    denomination_count <<=  4;
    denomination_count |= remaining_amount / notes[i];
    remaining_amount %=  notes[i];
  }
  return denomination_count;
}
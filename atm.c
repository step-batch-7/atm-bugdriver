#include "atm.h"
#include <math.h>

unsigned int get_money(unsigned short int amount)
{
  if (amount > 31999)
  {
    return 0;
  }
  unsigned int denomination_count = 0x0;
  unsigned short int notes[8] = {1, 5, 10, 20, 50, 100, 500, 2000};
  unsigned short int remaining_amount = amount;

  for (int i = 7; i >= 0; i--)
  {
    denomination_count += pow(16, i) * (remaining_amount / notes[i]);
    remaining_amount %= notes[i];
  }
  return denomination_count;
}
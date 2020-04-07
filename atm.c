#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  unsigned int denomination_count = 0x0;
  denomination_count |= amount / 2000;
  denomination_count <<= 28;
  return denomination_count;
}
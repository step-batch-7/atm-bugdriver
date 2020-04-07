#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  unsigned int denomination_count = 0x0;
  if (amount > 31999)
    return denomination_count;
  unsigned short int notes[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned short int remaining_amount = amount;

  for (int i = 0; i < 8; i++)
  {
    denomination_count = denomination_count << 4;
    denomination_count |= remaining_amount / notes[i];
    remaining_amount %= notes[i];
  }
  return denomination_count;
}

void display_notes(unsigned short int amount, unsigned int notes_count)
{
  unsigned short int notes[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  printf("denomination count for %u\n", amount);
  unsigned int count = 0;
  for (int i = 7; i >= 0; i--)
  {
    count = notes_count & 0xf;
    count &&printf("%u %s of Rs %u\n", count, count < 2 ? "note" : "notes", notes[i]);
    notes_count = notes_count >> 4;
  }
  printf("\n");
}
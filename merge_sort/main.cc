#include <iostream>
#include "merge_sort.h"
#include "test_merge_sort.h"

int main(int argc, char *argv[]) {
  const int num_count = 30;
  int original[] = {325432, 989,   547510, 3,   -93,  189019, 5042,  123,
                    597,    42,    7506,   184, 184,  2409,   45,    824,
                    4,      -2650, 9,      662, 3928, -170,   45358, 395,
                    842,    7697,  110,    14,  99,   221};

  int numbers[num_count];

  memcpy(numbers, original, sizeof numbers);

  printf("Sorting %d numbers...\n\n", num_count);

  jw::merge_sort(numbers, 0, num_count - 1);

  if (jw::is_sorted(numbers, num_count)) {
    printf("** SUCCESS! **\n");
  } else {
    printf("Uh oh - not in order.\n");
  }

  if (jw::contain_same_ints(original, numbers, num_count)) {
    printf("** Contain the same elements! **\n");
  } else {
    printf("Uh oh - something is missing.\n");
  }

  jw::print_ints(numbers, num_count);
  putchar('\n');
  jw::print_ints(original, num_count);

  return 0;
}
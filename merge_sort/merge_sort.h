#ifndef PROJECT_MERGE_SORT_H
#define PROJECT_MERGE_SORT_H

namespace jw {

// Overwrites the original array with merged values.
void merge(int numbers[], int low, int mid, int high);
// Sorts the slice of the given array from index low to index high
void merge_sort(int numbers[], int low, int high);

}  // namespace jw

#endif  // PROJECT_MERGE_SORT_H

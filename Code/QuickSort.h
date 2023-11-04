#pragma once
#include <vector>
class Charactor;

void Swap(Charactor** a, Charactor** b);
int Partition(std::vector<Charactor*>& array, int start, int end);
void QuickSort(std::vector<Charactor*>& array, int start, int end);
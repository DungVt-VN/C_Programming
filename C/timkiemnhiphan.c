int binarySearch(float array[], int size, int target)
{
int lower = 0, upper = size - 1, mid;
while (lower <= upper) {
mid = (upper + lower)/2;
if (array[mid] > target)
{ upper = mid - 1; }
else if (array[mid] < target)
{ lower = mid + 1; }
else
{ return mid; }
}
return -1;
}
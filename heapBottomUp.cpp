#include <iostream>
using namespace std;

int n;

int leaf(int i){ return 2*i;}
int right(int i){ return 2*i+1;}

int parent(int i) {
  if(i%2 == 1)
    return i/2;
  else
    return (i-1)/2;
}

void maxHeap(int* a, int i) {

  int largest=0;
  int v;

  int l = leaf(i);
  int r = right(i);

  if(l < n && a[l] > a[i])
    largest = l;
  else
    largest = i;

  if(r < n && a[r] > a[largest])
    largest = r;

  if(largest != i) {
    v = a[i];
    a[i] = a[largest];
    a[largest] = v;
    maxHeap(a, largest);
  }
}

void heapBottomUp(int a[]) {
  int i=0;

  for(i = parent(n); i >= 0; i--) {
    maxHeap(a, i);
  }
}

int main() {
  int i;
  int a[] = {6, 5, 3, 1, 8, 7, 2, 4};
  n = sizeof(a) / sizeof(int);

  for(i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  heapBottomUp(a);
  
  for(i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

}

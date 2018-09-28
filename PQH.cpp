#include "PQH.hpp"
using namespace std;


mh::mh(int cap)
{
    heapSize = 0;
    arraySize = cap;
    harr = new node[cap];
}
void swap(node *x, node *y)
{
    node temp = *x;
    *x = *y;
    *y = temp;
}
void mh::minHeapify(int i)
{

    int l = left(i);
    int r = right(i);
    int smallest = i;

      if (l < heapSize && harr[l] < harr[i])
          smallest = l;
      if (r < heapSize && harr[r] < harr[smallest])
          smallest = r;

      if (smallest != i)
      {
          swap(&harr[i], &harr[smallest]);
          minHeapify(smallest);
      }







}

void mh::dequeueH()
{
  node root;
  int index = 0;
  while(index < arraySize)
  {
    if (heapSize <= 0)
        return;
    if (heapSize == 1)
    {
        heapSize--;
        //cout << index+1 <<":    " << harr[0].name << ",  " << harr[0].pri << ",  " << harr[0].treat << endl;
        return;
    }

    // Store the minimum value, and remove it from heap
    root = harr[0];
    //cout << index+1 <<":    " << root.name << ",  " << root.pri << ",  " << root.treat << endl;
    harr[0] = harr[heapSize-1];
    heapSize--;
    minHeapify(0);
    index++;
  }
  cout << index << endl;


}



void mh::enqueueH(node arr[])
{
  int index = 0;
  while(index < arraySize)
  {
    if (heapSize == arraySize)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    node temp = node(arr[index].name,arr[index].pri,arr[index].treat);
    heapSize++;
    int i = heapSize - 1;
    harr[i] = temp;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
    //cout <<index << ": Added " << harr[i].name << endl;
    index++;
  }
}


int main(){
  
  cout << "main work" << endl;
}
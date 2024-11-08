#include <stdio.h>
#define maxsize 100

int heap[maxsize];
int heapsize=0;

void swap(int *x,int *y)
{
    int temp=x;
    *x=*y;
    *y=temp;
}

void heapify(int index)
{
    int largest=index;
    int left=2*largest +1;
    int right=2*largest +2;

    if(left<heapsize&&heap[left]>heap[largest])
        {
            largest=left;
        }
    if(right<heapsize&&heap[right]>heap[largest])
        {
            largest=right;
        }

    if(largest!=index)
        {
            swap(heap[index],heap[largest]);
            heapify(largest);
        }
}

void insert(int value)
{
    if(heapsize>=maxsize)
        {
            printf("Max limit reached \n");
            return;
        }

    heap[heapsize]=value;
    int current = heapsize;
    heapsize++;

    while(current>0 && heap[(current-1)/2]<heap[current])
        {
            swap(&heap[(current-1)/2],&heap[current]);
            current = (current-1)/2;
        }
}
void deleteRoot(){

 if(heapsize<=0)
    {
        printf("heap is empty \n");
        return;
    }

    heap[0]=heap[heapsize-1];
            heapsize--;

    heapify(0);


}
void display() {
    for (int i = 0; i < heapsize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);

    printf("Max-Heap array: ");
    display();

    deleteRoot();
    printf("After deleting root: \n");
    display();

    return 0;
}

#include <limits>
#include <iostream>
using namespace std;
 
struct HeapElement {
    double value;
    HeapElement* parent;
    HeapElement* child1;
    HeapElement* child2;
};
class Heap {
    HeapElement* head;
public:
    Heap();
    ~Heap();
    void insert(double d); // inserts value d into the heap
    double top(); // returns the smallest element
    void pop_top(); // removes the smallest element
 
}; 

Heap::Heap(){
     head = NULL;
}
 
Heap::~Heap(){
    while (head != NULL){
        pop_top();
    }
}
double Heap::top(){ // returns the smallest element
    if (head != NULL){
        return head->value;
    }
    else{
        cout << "empty heap" << endl;
        return std::numeric_limits<double>::max();
    }
 
}

void Heap::insert(double d){// inserts value d into the heap
    if (head == NULL){
        head = new HeapElement;
        head->value = d;
        head->parent = NULL;
        head->child1 = NULL;
        head->child2 = NULL;
    }
    else{
        HeapElement* freepos_parent = head;
        HeapElement* freepos = new HeapElement;
        double temp;
         
        //find the parent of a free position and then insert value d to this positon(a node that that has less than 2 childrend.)
        while (freepos_parent->child1 != NULL && freepos_parent->child2 != NULL){
            if (rand() % 2 == 0){
                freepos_parent = freepos_parent->child1;
            }
            else{
                freepos_parent = freepos_parent->child2;
            }
        }
         
        //if left child is NULL then insert to left child, else insert to right child.
        if (freepos_parent->child1 == NULL){
            freepos_parent->child1 = freepos;
        } 
        else{
            freepos_parent->child2 = freepos;
        }
        //insert the new value to the position freepos.
        freepos->parent = freepos_parent;
        freepos->value = d;
        freepos->child1 = NULL;
        freepos->child2 = NULL;
 
        while (freepos_parent!=NULL && freepos_parent->value > freepos->value){
            //swap the value
            temp = freepos_parent->value;
            freepos_parent->value = freepos->value;
            freepos->value = temp;
            //set to one level higher
            freepos = freepos_parent;
            freepos_parent = freepos->parent;
        }
    }
}

void Heap::pop_top(){ // removes the smallest element
    if (head == NULL){
        cout << "The heap is already empty." << endl;
    }
    else if (head->child1 == NULL && head->child2 ==NULL){
        delete head;
        head = NULL;
    }
    else{
        HeapElement* leaf =  head;
        //find a leaf node
        while (leaf->child1 != NULL || leaf->child2 != NULL){ //if it has child
            if (leaf->child1 != NULL && leaf->child2 != NULL){ //if has two children
                if (rand() % 2 == 0){
                    leaf = leaf->child1;
                }
                else{
                    leaf = leaf->child2;
                }
            }
            else if (leaf->child1 != NULL){
                leaf = leaf->child1;
            }
            else{ leaf = leaf->child2; }
        }
         
        //cut the leaf
        if (leaf == leaf->parent->child1){
            leaf->parent->child1 = NULL;
        }
        else{ 
            leaf->parent->child2 = NULL;
        }
 
        //change head to the leaf
        leaf->parent = NULL;
        leaf->child1 = head->child1;
        leaf->child2 = head->child2;
 
        // change the parents of childs of previous head
        if (head->child1 != NULL){
            head->child1->parent = leaf;
        }
        if (head->child2 != NULL){
            head->child2->parent = leaf;
        }
 
        delete head;   
        head = leaf;
        //swap
        HeapElement* small_child = new HeapElement;
        double temp;
        while (leaf->child1 != NULL || leaf->child2 != NULL){
            if (leaf->child1 != NULL){
                small_child = leaf->child1;
                if (leaf->child2 != NULL && leaf->child2->value < leaf->child1->value){
                    small_child = leaf->child2;
                }
            }
            else{ small_child = leaf->child2; }
            if (leaf->value > small_child->value){
                temp = small_child->value;
                small_child->value = leaf->value;
                leaf->value = temp;
            }
            leaf = small_child;
        }
 
    }
 
}

int main(){
    Heap heap;
        // example input
    double input[20] = {65,45,13,89,14,30,05,98,62,26,78,12,19,10,58,59,8,99,37,95}; 
    for (int i = 0; i < 20; i++){
        heap.insert(input[i]);//data is inserted into an heap
    }
 
    double sorted_array[20];
    for (int j = 0; j <20; j++){
        sorted_array[j] = heap.top();
        heap.pop_top();//the smallest element is removed
    }
 
    for (int j = 0; j <20; j++){
        cout<<sorted_array[j]<<" ";
    }
    cout << "\n";
}
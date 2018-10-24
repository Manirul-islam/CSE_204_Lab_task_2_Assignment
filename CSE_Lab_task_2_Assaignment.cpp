
#include <iostream>

using namespace std;

class node {
public:
    int data;
    node *next;
};

int insFirst54( /*node *start, node *avail,*/ int item );

// Lets make start and avail as global.
node *start, *avail;

int main()
{
    node *tmp, *save;

    // initialize both pointers.
    start=avail=NULL;

    // step 1: Prepare avail free pool.
    for (int i=1; i<=20; i++) {
        tmp = new node;
        tmp->next = NULL;
        if ( i==1 ) {
            avail = tmp;
        } else {
            save->next = tmp;
        }
        save = tmp;
    }
    // step 2: iteratively take input and create a new node to form linked list.
    int in;
    cout << "Enter a number:";
    cin >> in;
    while (in != 0) {
        if ( insFirst54(/*start, avail,*/ in)==0 ) {
            cout<< "Insert successful."<<endl;
        } else {
            cout<<"Failed."<<endl;
        }

        cout << "Enter a number:";
        cin >> in;
    }

    // Traverse linked list.
    tmp = start;
    while( tmp!= NULL ) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    return 0;
}


int insFirst54( /*node *start, node *avail,*/ int item ) {
    if (avail==NULL) {
        cout<< "Overflow"<<endl;
        return -1;
    }
    // step 2
    node* new_ = avail;
    avail = avail->next;
    // step 3
    new_->data = item;
    new_->next = start;
    start = new_;
    return 0;
}

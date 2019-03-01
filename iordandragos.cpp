#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");
int n;
int V[100];

class node
{
    public:
        double my_info;
        node *my_left;
        node *my_right;
};

node *my_node;
node *arbore;

node* make_some_tree(node *nod, double new_one){
    if(nod == NULL){
        nod = new node;
        nod->my_info = new_one;
        nod->my_left = nod->my_right = NULL;
        return nod;
    }

    if(nod->my_info < new_one){
        return make_some_tree(nod->my_right, new_one);
    }
    if(nod->my_info > new_one){
        return make_some_tree(nod->my_left, new_one);
    }
}


int RSD(node *this_one)
{
    if (this_one!=NULL) {
        cout<<this_one->my_info<<" ";
        RSD(this_one->my_left);
        RSD(this_one->my_right);
                                  }
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> V[i];

    arbore = make_some_tree(arbore, V[1]);

    for(int i = 2; i <= n; i++) {
        make_some_tree(arbore, V[i]);
    }
    RSD(arbore);

    return 0;
}

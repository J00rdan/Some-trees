#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.dat");

int n;
int INF[100];
int ST[100];
int DR[100];

void read(){
    fin >> n;

    for(int i = 1; i <= n; i++) fin >> INF[i];
    for(int i = 1; i <= n; i++) fin >> ST[i];
    for(int i = 1; i <= n; i++) fin >> DR[i];
}

void print_RSD(int node){
    cout << INF[node] << " ";

    int left_child = ST[node];
    if(left_child != 0) print_RSD(left_child);

    int right_child = DR[node];
    if(right_child != 0) print_RSD(right_child);
}

void print_SRD(int node){
    int left_child = ST[node];
    if(left_child != 0) print_SRD(left_child);

    cout << INF[node] << " ";

    int right_child = DR[node];
    if(right_child != 0) print_SRD(right_child);
}

void print_SDR(int node){
    int left_child = ST[node];
    if(left_child != 0) print_SDR(left_child);

    int right_child = DR[node];
    if(right_child != 0) print_SDR(right_child);

    cout << INF[node] << " ";
}

int main()
{
    read();
    cout << "RSD(1):";
    print_RSD(1);
    cout << endl;
    cout << "SRD(1):";
    print_SRD(1);
    cout << endl;
    cout << "SDR(1):";
    print_SDR(1);
    cout << endl;


    return 0;
}

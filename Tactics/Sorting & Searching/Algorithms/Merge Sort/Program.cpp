#include <bits/stdc++.h>
using namespace std;

/* ---------- Fast I/O ---------- */
#define FAST_IO() ios::sync_with_stdio(false); cin.tie(NULL)

/* ---------- Typedefs ---------- */
using ll = long long;
using ull = unsigned long long;
using ld = long double;

/* ---------- Macros ---------- */
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

/*-----------Function-----------*/
void merge(vector<int>& v,int left,int mid,int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;

    // CREATING THE TEMP COPY ->
    vector<int> L(n1) , R(n2);
    for(int i=0;i<n1;i++)
    L[i] = v[left+i];
    for(int i=0;i<n2;i++)
    R[i] = v[mid+1+i];

    int i=0,j=0,k=left;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) v[k] = L[i++];
        else v[k] = R[j++];
        k++;
    }

    // ADDING THE REMAINING ELEMENTS 
    while(i<n1) v[k++] = L[i++];
    while(j<n2) v[k++] = R[j++];
}

void mergeSort(vector<int>& v,int left,int right) {
    if(left>=right) return ; // BASE CONDITOIN

    int mid = (left+right)/2;

    // SORT THE FIRST & SECOND HALVES ->
    mergeSort(v,left,mid);
    mergeSort(v,mid+1,right);

    // MERGE THE SORTED HALVES
    merge(v,left,mid,right);
}

/* ---------- Main ---------- */
int main() {
    FAST_IO();

    int len;
    cout<<"ENTER THE LENGTH : " << endl;
    cin>>len;

    vector<int> v;
    cout << "ENTER THE ELEMENTS : " << endl;
    while(len-->0) {
        int input;
        cin>>input;
        v.push_back(input);
    }

    mergeSort(v,0,v.size()-1);

    cout<<"OUTPUT : ";
    for(int i=0;i<v.size();i++)
    cout << v[i] << endl;
    
    return 0;
}
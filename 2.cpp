#include<iostream>
using namespace std;

// Project 1: Modeling Alleles with Binary Values (Mendel’s Law of Dominance)
// Objective:
// Introduce Mendel’s Law of Dominance, where dominant alleles mask the effects of recessive alleles.

// Problem:
// In classical genetics, Mendel found that dominant alleles mask recessive ones. For example, in pea plants:

// T (tall) is dominant.
// t (short) is recessive.

// In this project:
// Take two alleles as binary input (1 for dominant, 0 for recessive).
// Implement Mendel’s Law of Dominance: if at least one allele is dominant (1), the plant will be tall;
//  otherwise, it will be short.
// Output whether the plant is tall or short based on this logic.


bool lawOfDom(bool a, bool b){
    return a || b;
}


int main(){

bool a;
bool b;

cout<<"1: Dominant(Tall) and 0: recessive allele(Short)"<<endl;
cout<<"Enter allele 1: ";
cin>>a;
cout<<"Enter allele 2: ";
cin>>b;

cout<<"Gene for Height: "<<a<<b<<endl;

cout<<"Phenotype for Height: ";

if(lawOfDom(a,b)){
    cout<<"Tall";
}
else
cout<<"Short";


    return 0;
}
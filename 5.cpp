#include<iostream>
#include<time.h>
using namespace std;

void dispGenome(bool a[], int n){
    for (int i = 0; i < n-1; i=i+2) {
        cout << a[i] << a[i+1] << " ";
    }
    cout << endl << endl;
}

bool lawOfDom(bool a, bool b){
    return a || b; // Law of Dominance: Dominant allele masks recessive
}

bool lawOfSeg(bool x[]) {
    int r = rand() % 2;
    return x[r]; // Law of Segregation: Randomly pass on one of two alleles
    // the law of segregation requires that each gamete receive either of the two alleles.
    // Since I am only selecting one of the 2 alleles everytime, therefore I think there's no use for this function.
}

// Function to display all possible combinations of alleles using the Law of Independent Assortment
void lawofInd(bool a[], int traits, bool all[],int allcomb) {

    cout << "All possible combinations of alleles: " << endl;
    int count=0;
    for (int i = 0; i < allcomb; i++) {
        for (int j = 0; j < traits; j++) {
            bool t = i & (1 << j);  // Select either first or second allele based on bit value(0 or 1)
            cout << a[(2 * j) + t] << " ";  // Print selected allele
            all[count++]=a[(2 * j) + t];
        }
        cout << endl;
    }
    cout << endl;
}

void getOff(bool all1[],bool all2[],bool off[], int n){

    int traits = n / 2;  // Number of traits (for dihybrid, this is 2)
    return ;
}

int main() {
    srand(time(0));  // Seed random number generator for randomness

    int traits;

    cout<<"Enter the no. of traits for parents: ";
    cin>>traits;

    int n=traits*2;
    // Arrays to hold the alleles of the parents
    bool a[n] = {};  // Parent 1
    for(int i=0;i<n;i++){
        a[i]=1;     // all ones -> homozygous dominant
    }

    bool b[n] = {0,};  // Parent 2 -> homozygous recessive


    cout<<"Parent generation: "<<endl;

    // Display genomes of the parent 1
    cout << "Genome of Parent1: ";
    dispGenome(a,n);

    // Display genomes of the parent 2
    cout << "Genome of Parent2: ";
    dispGenome(b,n);

    int alleleComb=1<<traits;
    int m=traits*alleleComb;

    // Apply Law of Independent Assortment for Parent 1
    cout<<"Parent 1:"<<endl;
    bool all1[m]={0,}; // all possible combinations of alleles for parent 1
    lawofInd(a,traits,all1,alleleComb);

    // Apply Law of Independent Assortment for Parent 2
    cout<<"Parent 2:"<<endl;
    bool all2[m]={0,}; // all possible combinations of alleles for parent 2
    lawofInd(b,traits,all2,alleleComb);
    

    // Offspring of P1 and P2
    bool off[n]={0,};
    getOff(all1,all2,off,n);

    return 0;
}

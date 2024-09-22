#include<iostream>
#include<time.h>
using namespace std;

void Inp(bool a[], int n) {
    int x = 1;
    while (x <= n / 2) {
        cout << "For trait " << x << ": " << endl;
        int y = 2 * (x - 1);
        int c = 1;
        for (int i = y; i < y + 2; i++) {
            cout << "Enter Allele " << c++ << ": ";
            cin >> a[i];
        }
        x++;
    }
    cout << endl;
}

void dispGenome(bool a[], int n){
    cout << "Genome of Parent: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool lawOfDom(bool a, bool b){
    return a || b; // Law of Dominance: Dominant allele masks recessive
}

bool lawOfSeg(bool x[]) {
    int r = rand() % 2;
    return x[r]; // Law of Segregation: Randomly pass on one of two alleles
}

// Function to display all possible combinations of alleles using the Law of Independent Assortment
void lawofInd(bool a[], int n) {
    int traits = n / 2;  // Number of traits (for dihybrid, this is 2)
    int comb = 1 << traits;  // 2^traits, number of combinations

    cout << "All possible combinations of alleles: " << endl;

    for (int i = 0; i < comb; i++) {
        for (int j = 0; j < traits; j++) {
            bool t = i & (1 << j);  // Select either first or second allele based on bit value
            cout << a[(2 * j) + t] << " ";  // Print selected allele
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Seed random number generator for randomness

    int traits=2;

    cout<<"Enter the no. of traits for a parent: ";
    cin>>traits;

    int n=traits*2;
    // Arrays to hold the alleles of the parent
    bool a[n] = {0,};  // Parent 1

    // Input alleles for Parent 1
    Inp(a, n);

    // Display genomes of the parent
    dispGenome(a,n);

    // Apply Law of Independent Assortment for Parent 1
    lawofInd(a, n);

    return 0;
}

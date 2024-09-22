#include<iostream>
#include<time.h>
using namespace std;

bool lawOfDom(bool a, bool b){
    return a || b; // Law of Dominance: Dominant allele masks recessive
}

bool lawOfSeg(bool x[]){
    int r = rand() % 2;
    return x[r]; // Law of Segregation: Randomly pass on one of two alleles
}

int main(){
    srand(time(0)); // Seed the random generator

    bool a[2]; // Alleles for Parent 1
    bool b[2]; // Alleles for Parent 2

    // Input for Parent 1
    cout << "Enter alleles of Parent 1 (1 or 0): " << endl;
    for(int i = 0; i < 2; i++){
        cout << "Allele " << i+1 << ": ";
        cin >> a[i];
    }
    cout << endl;

    // Input for Parent 2
    cout << "Enter alleles of Parent 2 (1 or 0): " << endl;
    for(int i = 0; i < 2; i++){
        cout << "Allele " << i+1 << ": ";
        cin >> b[i];
    }
    cout << endl;

    // Display Genes of P1 and P2
    cout << "Gene of P1: ";
    for(int i = 0; i < 2; i++){
        cout << a[i];
    }
    cout << endl;

    cout << "Gene of P2: ";
    for(int i = 0; i < 2; i++){
        cout << b[i];
    }
    cout << endl << endl;

    // Display Genotypes and Phenotypes of Offspring
    int c = 1;
    int d=0;
    int r=0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << "Offspring O" << c << ": Genotype (" << a[i] << "," << b[j] << ") ";
            (lawOfDom(a[i], b[j]) ? d++ : r++);
            cout << "Phenotype: " << (lawOfDom(a[i], b[j]) ? "Tall" : "Short") << endl;
            c++;
        }
    }
    cout<<endl;

    // Law of Segregation: Random offspring genotype from each parent
    bool x = lawOfSeg(a);
    bool y = lawOfSeg(b);
    cout << "Random Offspring Genotype: (" << x << "," << y << ")" << endl;
    cout << "Phenotype: " << (lawOfDom(x, y) ? "Tall" : "Short") << endl;
    cout << "Probability: " << (lawOfDom(x, y) ? float(d)/(d+r) : float(r)/(d+r)) << endl;

    return 0;
}

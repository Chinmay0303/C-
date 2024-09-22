#include<iostream>
#include<time.h>
#include<string>
using namespace std;

// Function to display the genome (alleles) of a parent
// Alleles are either dominant (1) or recessive (0), and we print them as R/r, Y/y, T/t based on traits.
void displayGenome(bool alleles[], int totalAlleles) {
    char rec[totalAlleles / 2] = {'r', 'y', 't'};  // Recessive alleles for traits
    char dom[totalAlleles / 2] = {'R', 'Y', 'T'};  // Dominant alleles for traits

    // Loop through each allele and display corresponding dominant or recessive letter
    for (int i = 0; i < totalAlleles; i++) {
        if(alleles[i] == 0) {
            cout << rec[i / 2];  // Recessive allele
        }
        if(alleles[i] == 1) {
            cout << dom[i / 2];  // Dominant allele
        }

        // After displaying a pair of alleles, add a space for readability
        if ((i + 1) % 2 == 0)
            cout << " ";  // Separate pairs of alleles
    }
}

// Law of Dominance: Returns the dominant allele
// This follows Mendel's Law of Dominance, where a dominant allele (1) masks the effect of a recessive one (0).
bool lawOfDominance(bool allele1, bool allele2) {
    return allele1 || allele2;  // If either allele is dominant, return true
}

// Function to display the phenotype based on alleles (visible traits)
// The phenotype is determined by the combination of alleles (dominant vs. recessive).
void displayPhenotype(bool alleles[], int totalAlleles) {
    bool phen[totalAlleles / 2] = {0};  // Phenotype array storing dominant/recessive expression
    int j = 0;

    // Loop through pairs of alleles to determine phenotype based on dominance
    for(int i = 0; i < totalAlleles; i += 2) {
        phen[j++] = lawOfDominance(alleles[i], alleles[i + 1]);
    }

    // Define the trait names (wrinkled/round seeds, green/yellow color, dwarf/tall plant)
    char traits[6][20] = {"Wrinkled", "Round", "Green", "Yellow", "Dwarf", "Tall"};

    // Display the corresponding trait for each allele pair
    for(int i = 0; i < totalAlleles / 2; i++) {
        if(phen[i] == 0)
            cout << traits[2 * i] << " ";  // Recessive trait
        else
            cout << traits[2 * i + 1] << " ";  // Dominant trait
    }
}

// Generates all gamete combinations (assorted alleles) that a parent can pass on.
void displayAlleleCombinations(bool alleleCombinations[], int traitsCount) {
    int totalCombinations = traitsCount * (1 << traitsCount);  // Total combinations = 2^traitsCount
    char t1[2] = {'r', 'R'};  // Alleles for Trait 1
    char t2[2] = {'y', 'Y'};  // Alleles for Trait 2
    char t3[2] = {'t', 'T'};  // Alleles for Trait 3

    // Loop through all combinations and display the corresponding genotype (R/r, Y/y, T/t)
    for(int i = 0; i < totalCombinations; i += traitsCount) {
        for(int j = 0; j < traitsCount; j++) {
            if((i + j) % traitsCount == 0) {
                cout << t1[alleleCombinations[i + j]];  // Trait 1 alleles (R/r)
            }
            if((i + j) % traitsCount == 1) {
                cout << t2[alleleCombinations[i + j]];  // Trait 2 alleles (Y/y)
            }
            if((i + j) % traitsCount == 2) {
                cout << t3[alleleCombinations[i + j]];  // Trait 3 alleles (T/t)
            }
            if ((i + j + 1) % traitsCount == 0)
                cout << " ";  // Separate genotype combinations
        }
    }
    cout << endl;
}

// Function to encode a binary genome into a decimal value
// Encodes a binary representation of alleles into a single integer
int encodeGene(bool alleles[], int length) {
    int decimalValue = 0;
    int multiplier = 1;

    // Convert binary array to decimal
    for (int i = length - 1; i >= 0; i--) {
        decimalValue += alleles[i] * multiplier;
        multiplier *= 2;
    }
    return decimalValue;
}

// Function to decode a decimal value back into a binary genome
// Decodes the stored decimal representation back into binary alleles.
void decodeGene(int encodedGene, bool decodedAlleles[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        decodedAlleles[i] = encodedGene & 1;  // Extract least significant bit
        encodedGene >>= 1;  // Shift bits to the right
    }
}

// Law of Independent Assortment: Generates all possible combinations of alleles
// This simulates Mendel’s Law of Independent Assortment, generating combinations of alleles in gametes.
int lawOfIndependentAssortment(int parentEncoded, int traitsCount, int totalCombinations) {
    bool alleles[traitsCount * 2];  // Store alleles for the parent
    decodeGene(parentEncoded, alleles, traitsCount * 2);  // Decode parent genome

    int combinationLength = traitsCount * totalCombinations;
    bool allCombinations[combinationLength] = {0};

    int count = 0;
    for (int i = 0; i < totalCombinations; i++) {
        for (int j = 0; j < traitsCount; j++) {
            bool selectAllele = i & (1 << j);  // Select allele based on current combination
            allCombinations[count++] = alleles[(2 * j) + selectAllele];
        }
    }
    return encodeGene(allCombinations, combinationLength);  // Return the encoded allele combination
}

// Function to display the genomes and phenotypes of both parents
void displayParentGenomes(bool parent1Alleles[], bool parent2Alleles[], int totalAlleles) {
    // Print separator for clarity
    for(int i = 0; i <= 64; i++){
        cout << "-";
    }
    cout << endl;

    // Display Parent 1
    cout << "Parent 1 (P1) Genotype: ";
    displayGenome(parent1Alleles, totalAlleles);
    cout << "\tPhenotype: ";
    displayPhenotype(parent1Alleles, totalAlleles);
    cout << endl;

    // Display Parent 2
    cout << "Parent 2 (P2) Genotype: ";
    displayGenome(parent2Alleles, totalAlleles);
    cout << "\tPhenotype: ";
    displayPhenotype(parent2Alleles, totalAlleles);
    cout << endl;

    // Print another separator
    for(int i = 0; i <= 64; i++){
        cout << "-";
    }
    cout << endl << endl;
}

// Function to display unique possible offspring
// This section handles displaying the offspring genotype and phenotype.
void displayOffspring(int childGenotypes[], int totalChildren, int totalAlleles, bool decodedOffspring[]) {
    int count = 1;
    cout << "Offspring\tGenotype \tPhenotype" << endl;

    // Print separator
    for(int i = 0; i <= 50; i++) {
        cout << "-";
    }
    cout << endl;

    // Loop through the children and display unique genotypes and phenotypes
    for (int i = 0; i < totalChildren; i++) {
        if (childGenotypes[i] >= 1) {
            cout << "   " << count++ << " \t\t";
            decodeGene(i, decodedOffspring, totalAlleles);
            displayGenome(decodedOffspring, totalAlleles);

            if(totalAlleles > 4)
                cout << " \t";
            else
                cout << " \t\t";

            displayPhenotype(decodedOffspring, totalAlleles);
            cout << endl;
        }
    }

    // Print separator
    for(int i = 0; i <= 50; i++) {
        cout << "-";
    }
    cout << endl;
}

// Generate offspring genotypes based on parent genomes
// Simulates possible offspring based on the Law of Segregation and Independent Assortment.
void generateOffspring(int parent1Index, int parent2Index, int traitsCount, int totalCombinations, int childGenotypes[], bool offspring[]) {
    int combinationLength = traitsCount * totalCombinations;
    bool parent1Combinations[combinationLength] = {0};
    bool parent2Combinations[combinationLength] = {0};

    int totalAlleles = 2 * traitsCount;
    int totalChildren = totalCombinations * totalCombinations;

    // Decode both parent genotypes
    decodeGene(parent1Index, parent1Combinations, combinationLength);
    decodeGene(parent2Index, parent2Combinations, combinationLength);

    // Loop to combine alleles from each parent
    for (int i = 0; i < totalCombinations; i++) {
        for (int j = 0; j < totalCombinations; j++) {
            bool currentOffspring[totalAlleles] = {0};

            // Combine alleles for each trait
            for (int t = 0; t < traitsCount; t++) {
                currentOffspring[2 * t] = parent1Combinations[traitsCount * i + t];
                currentOffspring[2 * t + 1] = parent2Combinations[traitsCount * j + t];
            }

            // Encode the offspring genotype and store it
            int encodedOffspring = encodeGene(currentOffspring, totalAlleles);
            childGenotypes[encodedOffspring]++;
        }
    }

    // Display the offspring
    displayOffspring(childGenotypes, totalChildren, totalAlleles, offspring);
}

// Recursive function to simulate generations of offspring
// This allows for multiple generations to be simulated, based on user input.
void generateGeneration(bool parent1Alleles[], bool parent2Alleles[], int traitsCount, int genCount) {
    int totalAlleles = traitsCount * 2;
    displayParentGenomes(parent1Alleles, parent2Alleles, totalAlleles);

    // Encode the parent genotypes into numbers
    int parent1Encoded = encodeGene(parent1Alleles, totalAlleles);
    int parent2Encoded = encodeGene(parent2Alleles, totalAlleles);

    // Apply Law of Independent Assortment to generate gamete combinations
    int totalCombinations = 1 << traitsCount;
    int combinationLength = traitsCount * totalCombinations;

    // Generate gamete combinations for Parent 1
    int parent1CombinationIndex = lawOfIndependentAssortment(parent1Encoded, traitsCount, totalCombinations);
    bool parent1AlleleCombinations[combinationLength] = {0};
    decodeGene(parent1CombinationIndex, parent1AlleleCombinations, combinationLength);
    cout << "Gamete combinations (Parent 1): ";    
    displayAlleleCombinations(parent1AlleleCombinations, traitsCount);

    // Generate gamete combinations for Parent 2
    int parent2CombinationIndex = lawOfIndependentAssortment(parent2Encoded, traitsCount, totalCombinations);
    bool parent2AlleleCombinations[combinationLength] = {0};
    decodeGene(parent2CombinationIndex, parent2AlleleCombinations, combinationLength);
    cout << "Gamete combinations (Parent 2): ";
    displayAlleleCombinations(parent2AlleleCombinations, traitsCount);

    cout << endl;

    // Generate possible offspring genotypes
    int totalChildren = totalCombinations * totalCombinations;
    int childGenotypes[totalChildren] = {0};
    bool offspring[totalAlleles] = {0};

    cout << endl;
    cout << "F" << genCount << " Generation:" << endl << endl;
    generateOffspring(parent1CombinationIndex, parent2CombinationIndex, traitsCount, totalCombinations, childGenotypes, offspring);

    // Ask user if they want to generate the next generation
    cout << endl;
    cout << "Do you want to generate the next generation? (y/n): ";
    char userChoice;
    cin >> userChoice;
    if (userChoice == 'y' || userChoice == 'Y') {
        int validOffspringCount = 0;

        // Count valid offspring combinations
        for (int i = 0; i < totalChildren; i++) {
            if (childGenotypes[i] > 0) {
                validOffspringCount++;
            }
        }

        // Create an array to store valid offspring indices
        int validOffspringIndices[validOffspringCount] = {0};
        int index = 0;
        for (int i = 0; i < totalChildren; i++) {
            if (childGenotypes[i] > 0) {
                validOffspringIndices[index++] = i;
            }
        }

        // Select two random offspring to generate the next generation
        int randomOffspring1 = validOffspringIndices[rand() % validOffspringCount];
        int randomOffspring2 = validOffspringIndices[rand() % validOffspringCount];

        bool offspring1[totalAlleles] = {0};
        bool offspring2[totalAlleles] = {0};
        decodeGene(randomOffspring1, offspring1, totalAlleles);
        decodeGene(randomOffspring2, offspring2, totalAlleles);

        // Recursive call to generate the next generation
        generateGeneration(offspring1, offspring2, traitsCount, ++genCount);
    } else {
        return;
    }
}

int main() {
    srand(time(0));  // Seed random number generator for randomness

    int traitsCount;

    // Display the traits that are being simulated
    cout << "\nTrait 1 (Seed Shape): Round (R) / Wrinkled (r)" << endl;
    cout << "Trait 2 (Seed Color): Yellow (Y) / Green (y)" << endl;
    cout << "Trait 3 (Plant Height): Tall (T) / Dwarf (t)" << endl << endl;

    while(true){
    // Prompt user to select how many traits to simulate (1, 2, or 3)
    cout << "Please select how many traits you'd like to explore: \n\n1 for one trait (Monohybrid Cross), 2 for two traits (Dihybrid Cross), 3 for three traits (Trihybrid Cross)." << endl;
    cin >> traitsCount;

    if(traitsCount<=3 && traitsCount>0){
        break;
    }
    else{
        cout<<"Enter a valid number\n\n";
    }
    }
    
    int totalAlleles = traitsCount * 2;
    bool parent1Alleles[totalAlleles];
    bool parent2Alleles[totalAlleles];

    // Set Parent 1 to homozygous dominant (all 1s), Parent 2 to homozygous recessive (all 0s)
    for (int i = 0; i < totalAlleles; i++) {
        parent1Alleles[i] = 1;  // Parent 1: Homozygous Dominant
        parent2Alleles[i] = 0;  // Parent 2: Homozygous Recessive
    }

    cout << endl;
    generateGeneration(parent1Alleles, parent2Alleles, traitsCount, 1);  // Start with the first generation
    

    return 0;
}

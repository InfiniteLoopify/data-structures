#include <iostream>
#include "Combinatorics.h"
using namespace std;

int main()
{
    vector<char> bioinformaticString {'A','B','C','D','E'};
    int stringLength = 2;
    Combinatorics<char> comb(bioinformaticString);
    comb.set_repeat(true);

    comb.display_objectList();
    comb.permutation(stringLength);
    cout << endl << comb.get_count();

    return 0;
}

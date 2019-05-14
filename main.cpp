#include "bc.h"
#include <iostream>

using namespace std;

int main () {
    cout << "This recomender will help you choose a profession and an area..." << endl;

    BC backChainer(true);
    backChainer.inferenceSection();
    cout << "Your recomended profession is: ";
    backChainer.printProfession();
}

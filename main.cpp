#include "bc.h"
#include "fc.h"
#include <iostream>

using namespace std;

int main () {
    cout << "This recomender will help you choose a profession and an area..." << endl;

    BC backChainer(false);
    backChainer.inferenceSection();

    FC forwardChainer (backChainer.getProfession(), false);
    forwardChainer.start();

    cout << "Congratulation! Your future profession will be ";
    forwardChainer.printProfession();
    cout << "With a focus in ";
    forwardChainer.printArea();

    return 0;
}

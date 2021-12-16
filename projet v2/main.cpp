#include "CVehicule.h"


int main()
{
    printf("Debut du programme\n");
    CVehicule *v1 = new CVehicule();

    v1->deplacer(2, 0, 5000);

    v1->deplacer(0, 50, 5850);

    v1->deplacer(2, 0, 15000);

    return 0;
}

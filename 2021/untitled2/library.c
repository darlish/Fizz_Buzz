#include "library.h"

#include <stdio.h>


int main(void) {
#include <stdio.h>

    int main () {

        int A[5] = {1, 2, 3, 17, 5};

        int *p;

        int i;

        p = A;

        for ( i = 0; i < 5; i++ )

            printf("%d - ", p + i );

        return 0;

    }
}

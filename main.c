#include <stdio.h>



#define BLINKER_SIZE 3
#define BLINKER_GEN 3
char small_blinker[] = {
      0,0,0,
      1,1,1,
      0,0,0
};
char temp_blinker[BLINKER_SIZE*BLINKER_SIZE];

#define FIELD_SIZE 45
#define FIELD_GEN 175
char field[FIELD_SIZE * FIELD_SIZE];
char temp_field[FIELD_SIZE*FIELD_SIZE];

/* set the cell i,j as alive */
#define SCELL(I,J) field[FIELD_SIZE*(I)+(J)] = 1

void dump_field(const char *f, int size)
{
   int i;
   for (i=0; i < (size*size); i++)
   {
      if ( (i % size) == 0 ) printf("\n");
      printf("%c", f[i] ? 'X' : '.');
   }
   printf("\n");
}


int main(int argc, char **argv)
{
    int i;
    char *fa, *fb, *tt, op;
    
    /* fast and dirty selection option */
    if ( argc > 1 )
    {
       op = *argv[1];
    } else {
       op = 'b';
    }
    
    switch ( op )
    {
      case 'B':
      case 'b':
        /* blinker test */
        fa = small_blinker;
        fb = temp_blinker;
        for(i=0; i< BLINKER_GEN; i++)
        {
           dump_field(fa, BLINKER_SIZE);
           evolve(fa, fb, BLINKER_SIZE);
           tt = fb; fb = fa; fa = tt;
        }
        return 0;
      case 'G':
      case 'g':
        for(i=0; i < (FIELD_SIZE*FIELD_SIZE) ; i++) field[i]=0;
        /* prepare the glider */
                     SCELL(0, 1);
                                  SCELL(1, 2);
        SCELL(2, 0); SCELL(2, 1); SCELL(2, 2);
        /* evolve */
        fa = field;
        fb = temp_field;
        for (i=0; i < FIELD_GEN; i++)
        {
           dump_field(fa, FIELD_SIZE);
           evolve(fa, fb, FIELD_SIZE);
           tt = fb; fb = fa; fa = tt;
        }
        return 0;
      default:
        fprintf(stderr, "no CA for this\n");
        break;
    }
    return 1;
}
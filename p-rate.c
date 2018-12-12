#include <stdio.h>
#include <string.h>

/* --- Declaring Functions ---*/
double loading(int P, int *X, double S, double Lt, double Tc, double Tt, double D, double L, double Vc, double Ve, double *P1, double *P2, double *P3, double *P4);
int findMax(double a, double b, double c, double d);


/* --- Main Code ---*/
int main(void)
{
  int P, X = 0;
  double S, Lt, Tc, Tt, D, L, Vc, Ve, P1, P2, P3, P4 = 0;
  int repeat = 1;
  char answer;

  /* --- Relevant Parameters */
  printf("Enter the length of cut to fill the truck (Lt): ");
  scanf("%lf", &Lt);
  printf("Enter the truck exchange time (Tc): ");
  scanf("%lf", &Tc);
  printf("Enter the truck turning time (Tt): ");
  scanf("%lf", &Tt);
  printf("Enter the cut depth (D): ");
  scanf("%lf", &D);
  printf("Enter the effective face length (L): ");
  scanf("%lf", &L);
  printf("Enter the cutting speed (Vc): ");
  scanf("%lf", &Vc);
  printf("Enter the empty travel speed(Ve) ");
  scanf("%lf", &Ve);


  printf("Enter the value of cutting drum width (S): ");
  scanf("%lf", &S); //test
  printf("Value of S is: %lf\n", S);

  /* --- Main Drama ---*/
  do 
  {
    printf("Enter the mode of travel and loading combination: ");
    scanf("%d", &P);
    loading(P, &X, S, Lt, Tc, Tt, D, L, Vc, Ve, &P1, &P2, &P3, &P4);
    printf("Would you like to test another method?\n Enter 'Y' for Yes and 'N' for No: ");
    scanf("%s", &answer);
    if (answer == 'Y')
    {
      repeat = 1;
    }
    else
    {
      repeat = 0;
    }
  } while (repeat);

  printf("X is %d\n", X);

  if (X == 4)
  {
    findMax(P1, P2, P3, P4);
  }
}

/* --- Loading Function which calculates the production rate ---*/
double loading(int P, int *X, double S, double Lt, double Tc, double Tt, double D, double L, double Vc, double Ve, double *P1, double *P2, double *P3, double *P4)
{
  if (P == 1)
  {
    *P1 = ((S * D) / 1000) * (60 / ((1/Vc) + (1/Ve) + (Tc / Lt)));
    printf("P1 is %lf\n", *P1 );
    *X = *X + 1;
    return 0;
  }
  else if (P == 2)
  {
    *P2 = ((S * L * D) / 1000) * (60 / ((L / Vc) + (L / Ve)));
    printf("P2 is %lf\n", *P2 );
    *X = *X + 1;
    return 0;
  }
  else if (P == 3)
  {
    *P3 = ((S * D) / 1000) * (60 / ((1 / Vc) + (Tt / L) + (Tc / Lt)));
    printf("P3 is %lf\n", *P3 );
    *X = *X + 1;
    return 0;
  }
  else if (P == 4)
  {
    *P4 = ((S * L * D) / 1000) * (60 / ((L / Vc) + Tt));
    printf("P4 is %lf\n", *P4 );
    *X = *X + 1;
    return 0;
  }

  else 
  {
    return 1;
  }
}

/* --- Function for arranging all the P values --- */
int findMax(double a, double b, double c, double d)
{
  double value[4];
  value[0] = a;
  value[1] = b;
  value[2] = c;
  value[3] = d;

  char *variable[4] = {"P1","P2","P3","P4"};

  double max = 0; 
  int index = 0;
  for (int i = 0; i < 4; i++)
  {
    if (value[i] > max)
    {
      max = value[i];
      index = i;
    }
  }

  printf("Highest Production Rate is of %s: %lf\n", variable[index], max);

  return 0;

}

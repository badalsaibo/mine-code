#include <stdio.h>

/* -- initial declerationof all functions --*/
double calcIs(double *PLI);
double calcJv(double *PLI);
double calcAw(double *PLI);
double calcJs(double *PLI);
double calcM(double *PLI);

int main(void)
{
  /* -- Relevant Parameters -- */
  double Is, Jv, Aw, Js, M, UCS, CI, L, k, Mc;

  printf("Point Load Index(Is): ");
  scanf("%lf", &Is);
  calcIs(&Is); //Function that returns the corresponding value

  printf("Volumetric Joint Count(Jv): ");
  scanf("%lf", &Jv);
  calcJv(&Jv); //Function that returns the corresponding value

  printf("Abrasivity(Aw): ");
  scanf("%lf", &Aw);
  calcAw(&Aw); //Function that returns the corresponding value

  printf("Direction of cutting respect to major joint direction(Js): ");
  scanf("%lf", &Js);
  calcJs(&Js); //Function that returns the corresponding value

  printf("Machine Power(M): ");
  scanf("%lf", &M);
  calcM(&M); //Function that returns the corresponding value

  printf("Enter UCS: ");
  scanf("%lf", &UCS);
  
  // Condition for calculation 
  if (UCS > 120)
  {
    printf("Surface Miner is not applicable\n");
    return 1;
  }
  else 
  {
    if (Aw > 3)
    {
      printf("Aw is greater than 3. Surface Miner not applicable\n");
      return 1;
    }
    else 
    {
      /* -- Cuttability Index --*/
      CI = Is + Jv + Aw + Js + M;
      printf("CI is: %lf\n", CI);

      if (CI > 70)
      {
        printf("CI is greater than 70. Surface Miner not applicable\n");
        return 1;
      }
      else
      {
        /* -- If CI < 70 -- */
        printf("Enter the value of k (0.5 - 1.0): ");
        scanf("%lf", &k);
        printf("Enter the value of Mc: ");
        scanf("%lf", &Mc);
        /* -- Cuttability Index Production Rate --*/
        L = (1 - (CI/100)) * k * Mc;
        printf("L is: %lf\n", L);
      }
    }
  }

}

/* -- Calculates the relevant Is based on the users input -- */
double calcIs(double *PLI)
{
  if (*PLI < 0.5)
  {
    *PLI = 5;
    return 0;
    
  }
  else if (*PLI >= 0.5 && *PLI <= 1.5)
  {
    *PLI = 10;
    return 0;
  }

  else if (*PLI >= 1.5 && *PLI <= 2.0)
  {
    *PLI = 15;
    return 0;
  }

  else if (*PLI >= 2.0 && *PLI <= 3.5)
  {
    *PLI = 20;
    return 0;
  }

  else if (*PLI > 3.5)
  {
    *PLI = 25;
    return 0;
  }
  else 
  {
    return 1;
  }
}

/* -- Calculates the relevant Jv based on the users input -- */
double calcJv(double *PLI)
{
  if (*PLI > 30)
  {
    *PLI = 5;
    return 0;
    
  }
  else if (*PLI >= 10 && *PLI <= 30)
  {
    *PLI = 10;
    return 0;
  }

  else if (*PLI >= 3 && *PLI <= 10)
  {
    *PLI = 15;
    return 0;
  }

  else if (*PLI >= 1 && *PLI <= 3)
  {
    *PLI = 20;
    return 0;
  }

  else if (*PLI == 1)
  {
    *PLI = 25;
    return 0;
  }
  else 
  {
    return 1;
  }
}

/* -- Calculates the relevant Aw based on the users input -- */
double calcAw(double *PLI)
{
  if (*PLI < 0.5)
  {
    *PLI = 3;
    return 0;
    
  }
  else if (*PLI >= 0.5 && *PLI <= 1.5)
  {
    *PLI = 6;
    return 0;
  }

  else if (*PLI >= 1.5 && *PLI <= 2.0)
  {
    *PLI = 9;
    return 0;
  }

  else if (*PLI >= 2.0 && *PLI <= 3.0)
  {
    *PLI = 12;
    return 0;
  }

  else if (*PLI > 3.0)
  {
    *PLI = 15;
    return 0;
  }
  else 
  {
    return 1;
  }
}

/* -- Calculates the relevant Js based on the users input -- */
double calcJs(double *PLI)
{
  if (*PLI >= 72 && *PLI <= 90)
  {
    *PLI = 3;
    return 0;
    
  }
  else if (*PLI >= 54 && *PLI <= 72)
  {
    *PLI = 6;
    return 0;
  }

  else if (*PLI >= 36 && *PLI <= 54)
  {
    *PLI = 9;
    return 0;
  }

  else if (*PLI >= 18 && *PLI <= 36)
  {
    *PLI = 12;
    return 0;
  }

  else if (*PLI >= 0 && *PLI <= 18)
  {
    *PLI = 15;
    return 0;
  }
  else 
  {
    return 1;
  }
}

/* -- Calculates the relevant M based on the users input -- */
double calcM(double *PLI)
{
  if (*PLI > 1000)
  {
    *PLI = 4;
    return 0;
    
  }
  else if (*PLI >= 800 && *PLI <= 1000)
  {
    *PLI = 8;
    return 0;
  }

  else if (*PLI >= 600 && *PLI <= 800)
  {
    *PLI = 12;
    return 0;
  }

  else if (*PLI >= 400 && *PLI <= 600)
  {
    *PLI = 16;
    return 0;
  }

  else if (*PLI < 400)
  {
    *PLI = 20;
    return 0;
  }
  else 
  {
    return 1;
  }
}
#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------------------------------------

int  IsZero (double value);                       /* Is "value" zero? */
int  Lin_Eq_Sol (double a, double b, double *x1); /*finding value of root or if there are no roots or there are infinity number of roots*/
int  Lin_Sol (double *x1);                        /*Enter coeffs and finding number of roots*/
void res_lin(int roots, double *x1);              /*Printing final result of linear solution*/

//-----------------------------------------------------------------------------------------------------------


int main()
{
 double x1 = 0;
 int roots = Lin_Sol( &x1 );
 res_lin(roots, &x1);
 return 0;
}

//-----------------------------------------------------------------------------------------------------------

int IsZero (double value)
    {

    if (fabs (value) < 1e-6)
        return 1;
    else
        return 0;
    }
//-----------------------------------------------------------------------------------------------------------
int Lin_Sol (double *x1)
{
 double a = 0 ,b = 0 ;

   printf ("Solving Linear Equation like : ax+b = 0 \n");
   printf ("Enter coeff a ,b  : ");
    while ( scanf  ("%lf%lf", &a ,&b ) != 2 )                  /*If someone will try to enter */
       {                                                       /*a character ,the program will*/
        printf ("Enter literally coef, not a char or word :"); /*warn about a typo.           */
        fflush (stdin);                                        /*                             */
       }                                                       /*                             */
 int roots = Lin_Eq_Sol (a, b, x1);
 return roots;
}
//-----------------------------------------------------------------------------------------------------------
int Lin_Eq_Sol (double a, double b, double *x1)
{
   if ( IsZero (a) )
      {
       if ( IsZero (b) )
         {
         return -1;
         }
       else
         {
         return 0;
         }
      }
   else
     {
      if ( IsZero(-b/a) )
           *x1 = fabs(-b/a); /* If b = 0 -b/a = -0, but this looking terrible. So this string fixing this */
      else *x1 = -b/a;
      return 1;
     }
}
//-----------------------------------------------------------------------------------------------------------

void res_lin(int roots, double *x1)
 {
   if ( roots == -1)
       printf ("Number of roots if INF");
   if ( roots == 0 )
      printf ("There are no roots");
   if ( roots == 1 )
      printf ("Root is x = %lf", *x1);
 }





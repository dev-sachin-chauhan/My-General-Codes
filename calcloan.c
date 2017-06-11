#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main ()
{
    double loanAmount;
    double interestRate;
    double interstPerMonth;
    double numerator;
    double denominator;
    double interest;
    double emi;
    int numberOfPayments;
    int i=0;
    
    printf ("Enter amount of loan : $");
    scanf("%lf",&loanAmount);
    
    printf ("Enter Interest rate per year : %%");
    scanf("%lf",&interestRate);
    
    printf ("Enter number of payments : ");
    scanf("%d",&numberOfPayments);
    
    interstPerMonth = (interestRate/1200);
    
    numerator = pow(1+interstPerMonth,numberOfPayments);
    denominator = numerator -1;
    
    emi = loanAmount*interstPerMonth*numerator/denominator;
    
    printf("\nMonthly payment should be %.2lf", emi);
    
    printf("\n==============================AMORTIZATION SCHEDULE============================");
    printf("\n#             Payment             Principle           Interest           Balance");
    for(i=1; i <= numberOfPayments; i++) {
            interest = loanAmount*interstPerMonth;
            loanAmount = loanAmount - (emi - interest);
            printf("\n%-3d           $%-8.2lf           $%-8.2lf           $%-8.2lf          $%-8.2lf\n", i, emi, emi-interest, interest, loanAmount );
    }
    
    return 0;
}

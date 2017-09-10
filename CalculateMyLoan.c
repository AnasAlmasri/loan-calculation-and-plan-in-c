#include <stdio.h>
#include <math.h>

int main(){
    float b_balance, y_interest, m_payment, m_interest, principal, e_balance;

    printf("\nEnter loan amount: ");
    scanf("%f", &b_balance);
    printf("\nEnter yearly interest rate: ");
    scanf("%f", &y_interest);
    printf("\nEnter monthly payment: ");
    scanf("%f", &m_payment);

    if(b_balance <= m_payment){
        m_interest=0.00;
        principal=m_payment;
    }
    else{
        m_interest=(b_balance)*(y_interest)/12;
        principal=(m_payment)-(m_interest);
    }
    while(m_payment<=m_interest){
        printf("***>Monthly payment is too small.\n");
        printf("Enter monthly payment: ");
        scanf("%f", &m_payment);
    }

    printf("\nBeginning     Payment     Interest     Principal     Ending\n");
    printf("Balance                                              Balance\n");
    printf("---------    --------     --------     ---------    ---------\n");

    do{
        if(b_balance <= m_payment){
            m_interest=0.00;
            principal=m_payment;
        }
        else{
            m_interest=(b_balance)*(y_interest)/12;
            principal=(m_payment)-(m_interest);
        }
        e_balance=(b_balance)-(principal);

        printf("%8.2f     %8.2f     %8.2f     %8.2f     %8.2f\n", b_balance, m_payment, m_interest, principal, e_balance);

        if(e_balance <= m_payment){
            m_payment=e_balance;
        }
        b_balance=e_balance;
    }
    while(e_balance > 0.00);


    return 0;
}

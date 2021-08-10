// OfficeOfAccounts Header File
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <conio.h>

#include "OfficeOfAcademics.h"
#include "OfficeOfAccounts.h"

#define ExpensesPath "Expenses.txt"

#define SUCCESSFUL 1
#define YES 1
#define NO 0

int count3=0;

void LOGINSTART();

        void OfficeOfAccounts:: login()
        {
            char EmployeeID[40], pass[40];
            std::cout << "Enter EmployeeID: " ;
            std::cin >> EmployeeID;
            std::cout << "Enter Password: " ;
            //std::cin >> pass;
            int i=0;
            char c;
            c=getch();
            do
            {
                pass[i]=c;
                i++;
                printf("*");
                c=getch();
            } while (c!='\r');
            pass[i]='\0';
            std::cout << std::endl;
            int loginverify = OfficeOfAcademics::VerifyCredentials(EmployeeID, pass);
            if(loginverify==SUCCESSFUL)
            {
                std::cout << ("\n** Login Successful! **\n\n");
                DisplayOptions();
            }
            else
            {
                std::cout << ("Enter credentials again\n");
                count3++;
                if(count3==3)
                {
                    printf("You have entered the wrong credentials three times\n\n");
                    ::LOGINSTART();
                }
                login();
            }
        }
        void OfficeOfAccounts:: ViewMedicalExpenses()
        {
            std::cout << "Cumulative Medical Expenses: Rs. ";
            FILE *fp = fopen(ExpensesPath,"r");
            double amt;
            fscanf(fp,"%lf", &amt);
            fclose(fp);
            printf("%lf\n",amt);
        }
        
        void OfficeOfAccounts:: UpdateExpenses(double amt)
        {
       
            FILE *fp = fopen(ExpensesPath,"r");
            double StoredAmount;
            fscanf(fp,"%lf", &StoredAmount);
            fclose(fp);
            amt += StoredAmount;
            fp = fopen(ExpensesPath,"w");
            fprintf(fp,"%.2lf",amt);
            fclose(fp);
        }
        void OfficeOfAccounts:: DisplayOptions()
        {
            int incorrectChoice = NO;
            int repeat = YES;
            do
            {        	
		        std::cout << " 1:View Medical Expenses\n";      //can be made into two if we want(for whole expenses and for particular patient)
		        
		        std::cout << "Enter your choice (The corresponding number): ";
		        int choice;
		        std::cin >> choice;

		        switch(choice)
		        {
		            case 1:         //getting Medical expenses record
		            {   
		                ViewMedicalExpenses();
		                break;
		            }
		            default:
		            {
						std::cout << "Please enter a valid option!\n";
		                incorrectChoice = YES;
		            }
		        }
		        if(incorrectChoice == YES)
		            repeat = YES;
		        else
		        {
		        	std::cout << " Do you wish to perform more functions as an OfficeOfAccounts user? (Yes/No): ";
		        	std::string resp1;
		        	std::cin >> resp1;
		        	std::transform(resp1.begin(), resp1.end(), resp1.begin(), ::tolower);
					if(resp1.std::string::compare("yes")==0)
                        repeat = YES;
                    else
                        repeat = NO;
                }	        
			}while(repeat == YES);
        }

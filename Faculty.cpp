#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <conio.h>

#include "Faculty.h"
#include "OfficeOfAcademics.h"

#define SUCCESSFUL 1
#define YES 1
#define NO 0
int count2=0;

void LOGINSTART();

    void Faculty :: login()
    {
        char ldap[40], pass[40];
        std::cout << "Enter LDAP ID: ";
        std::cin >> ldap;
        std::cout << "Enter Password: ";
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
        int loginverify = OfficeOfAcademics::VerifyCredentials(ldap, pass);

        if (loginverify == SUCCESSFUL)
        {
            std::cout << ("\n** Login Successful! **\n\n");
            FurtherOptions();
        }
        else
        {
            std::cout << ("Enter credentials again\n");
            count2++;
            if(count2==3)
            {
                printf("You have entered the wrong credentials three times\n\n");
                ::LOGINSTART();
            }
            login();
        }
    }

    void Faculty::FurtherOptions()
    {
        int repeat = YES;
        while(repeat == YES)
        {
            std::cout << ("Enter the Roll Number of the student to retrieve Medical Leave Record: ");
            char roll[15];
            std::cin >> roll;
            OfficeOfAcademics::GetMedicalLeaveRecord(roll);
            std::cout << "\n\nDo you wish to check for another student? (Yes/No): ";
            std::string response;

            std::cin >> response;
            std::transform(response.begin(), response.end(), response.begin(), ::tolower);
            if(response.std::string::compare("yes")==0)
            {
                repeat = YES;
            }
            else repeat = NO;
        }
    }

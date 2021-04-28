#include <stdio.h>
#include<time.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

void head(void);
void fAQ(void);
void corona_symptoms(void);
void spread(void);
void who(void);
void eligibility_criteria(void);
void counter(void);
void registration_form(void);
int elegibility_check(int a);
void choice();
void tail(void);

struct patient
{
    char firstname[20], lastname[20], contact[12], location[20];
    int age, id,day,month,year;
} details;

int main()
{
    head();
    choice();

    return 0;
}

void fAQ(void)
{
    int option;
    printf("\n_________________________________\n\n FREQUENTLY ASKED QUESTONS....\n_________________________________\n\n");
    printf("1.What are the Symptoms of corona.\n");
    printf("2.How does corona Spread ?\n");
    printf("3.WHO guidelines.\n");
    printf("4.What is the eligibility criteria.\n\n\n");
    printf("->Press 5 to Return to main menu.\n\n");
    do
    {
    printf("Enter Respective  choice :");
    scanf("%d", &option);
    printf("\n\n");

    switch (option)
    {
    case 1:
        corona_symptoms();
        break;

    case 2:
        spread();
        break;

    case 3:
        who();
        break;
    case 4:
    {
        eligibility_criteria();
    }
    break;
    case 5:
        choice();
        break;
    default:
        printf("Please select from given option numbers : \n");
  }
}while(option>5);
}

void head(void)
{
    printf("\nMinistry Of Health & Family welfare\nGovernment of India\n______________________________________ \n");
    printf("\nHelpline Number : +91-11-23978046\nToll Free : 1075\nHelpline Email ID : ncov2019@gov.in\n\n\n");
    printf("\t\t\t\t _________________________________________________________________________________________________________\n");
    printf("\t\t\t\t|  _____________________________________________________________________________________________________  |\n");
    printf("\t\t\t\t| |                                                                                                     | |\n");
    printf("\t\t\t\t| |                        WELCOME TO COVID VACCINE REGISTRATION PORTAL BY DASHY                        | |\n");
    printf("\t\t\t\t| |_____________________________________________________________________________________________________| |\n");
    printf("\t\t\t\t|_________________________________________________________________________________________________________|\n\n");

    printf("\n\nTill everyone is vaccinated , let us not forgot our responsibilities .");
    printf("Even after receiving the covid -19 vaccine continue taking all precautions .");
    printf("\n\t>  wash your hands    \n\t>  wear masks    \n\t>  social distancing\n");
    printf("________________________________________________________________________________________________________________________________________________________________________________________\n\n");
}

void corona_symptoms(void)
{
    printf("\n\n\t\t\t\t\t\t\t * COVID - 19 SYMPTOMS *\t\t\n\n");
    printf("# Most common symptoms:\n");
    printf("  >  Fever\n  >  Dry cough\n  >  Tiredness\n\n");

    printf("# Less common symptoms:\n");
    printf("  >  Aches and pains\n  >  Sore throat\n  >  Diarrhoea\n  >  Conjunctivitis\n  >  Headache\n  >  Loss of taste or smell\n  >  A rash on skin, or discolouration of fingers or toes\n\n");
    printf("# Serious symptoms:\n");
    printf("  >  Difficulty breathing or shortness of breath\n  >  Chest pain or pressure\n  >  Loss of speech or movement.");
}

void spread(void)
{
    printf("\n\n\t\t\t\t\t\t\t * HOW DOES COVID - 19 SPREAD ? *\t\t\n\n");
    printf("1.  > COVID-19 is caused by the SARS-CoV-2 virus, which spreads between people, mainly when an infected person is in close contact with another person.\n    > The virus is transmitted through direct contact with respiratory droplets of an infected person (generated through coughing and sneezing). \n    > Individuals can also be infected from and touching surfaces contaminated with the virus and touching their face (e.g., eyes, nose, mouth). \n    > The COVID-19 virus may survive on surfaces for several hours,but simply disinfectants(specially alcohol based) can kill it.\n\n");
    printf("2.  Transmission can occur more easily in the Three C's:\n\n   >  Crowded places with many people nearby.\n   >  Close-contact settings, especially where people have conversations very near each other.\n   >  Confined and enclosed spaces with poor ventilation.\n\n");
}

void who(void)
{
    printf("\n\n\t\t\t\t\t\t\t * Guidelines by WORLD HEALTH ORGANISATION *\t\t\n\n");
    printf("> Maintain at least a 1-metre distance.\n");
    printf("> Make wearing a mask is normal.\n");
    printf("> Meet people outside. Outdoor gatherings are safer than indoor ones.\n");
    printf("> Regularly and thoroughly clean your hands with Alcohol based soap.\n");
    printf("> Avoid touching your eyes, nose and mouth.\n");
    printf("> Cover your mouth and nose with your bent elbow or tissue when you cough or sneeze.\n");
    printf("> Clean and disinfect surfaces frequently especially those which are regularly touched.\n");
}

void eligibility_criteria(void)
{
    printf("\n\t\t\t\t\t* ELIGIBILITY CRITERIA *\n\n");

    printf("1.) In the initial phase, COVID 19 vaccine will be provided to the priority group- Health Care and Front-line workers.\n");
    printf("    The 60 plus age group may also begin early based on vaccine availability.\n\n");
    printf("2.) In the second phase, people below the age of 60 years and those above 45 and having comorbidities will be able to \n");
    printf("    receive COVID-19 vaccines first dose\n\n");
}

int elegibility_check(int a)
{
    int flag=0;
    char ans[4];
    if (a >= 60)
    {
        printf("\n\nCongratulations!...You are eligible for getting the vaccination .\n You can register yourself\n ");
        flag=1;
    }
    else
    {
        printf("\nAre you a Frontline worker(yes/no) : ");
        scanf("%s", ans);
        if (strcmp(ans, "yes") == 0 || strcmp(ans, "Yes") == 0 || strcmp(ans, "YES") == 0)
        {
            printf("\n\nCongratulations!...You are eligible for getting the vaccination .\n You can register yourself\n ");
            flag=1;
        }
        else
        {
            printf("\nSorry..You are NOT eligible.Keep safety precautions till you are eligible.\n");
            printf("\tTHANK YOU!");
        }
    }
    return flag;
}

void registration_form(void)
{
    int a;
    printf("\n\nEnter your age : ");
    scanf("%d", &a);
    int flag=elegibility_check(a);
    if(flag==1)
    {
        int count, last_id = 0;
        FILE *store_data, *retreive_data;
        retreive_data = fopen("store_data.txt", "r");
        while (fscanf(retreive_data, "%d %s %s %s %s %d %d %d %d\n", &details.id, details.firstname, details.lastname, details.contact, details.location, &details.age,&details.day,&details.month,&details.year) != EOF)
        {
            last_id = details.id;
        }
        printf("\n\n\n\t Your ID is : %d", ++last_id);
        details.id = last_id;
        printf("\n\n\t Enter Your Following details\n");
        printf("\nFirstName : ");
        scanf("%s", details.firstname);
        printf("\nLastName : ");
        scanf("%s", details.lastname);
        details.age=a;
        int t;
        do
        {
            t=0;
            printf("\nContact : ");
            scanf("%s", details.contact);


            if(strlen(details.contact)!=10)
            {
                t=1;
                printf("Enter a valid phone number \n");
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                    if(details.contact[i]>'9' || details.contact[i]<'0')
                    {
                        t=1;
                        printf("Enter a valid phone number in Digits \n");
                        break;

                    }

                }
            }

        }
        while(t);
        printf("\nLocation : ");
        scanf("%s", details.location);


        time_t now;
        time(&now);
        struct tm *local = localtime(&now);
        details.day = local->tm_mday;
        details.month = local->tm_mon + 1;
        details.year = local->tm_year + 1900;


        store_data = fopen("store_data.txt", "a");
        fprintf(store_data, "%d \t%s \t%s \t%s \t%s \t%d \t%d-%d-%d\n", details.id, details.firstname, details.lastname, details.contact, details.location, details.age,details.day,details.month,details.year);
        printf("\nRecord Saved successfully !\n");
        printf("%d \t%s \t%s \t%s \t%s \t%d \t%d-%d-%d\nVisit %s Govt Hospital For Vaccination after Two days\n", details.id, details.firstname, details.lastname, details.contact, details.location, details.age,details.day,details.month,details.year,details.location);
        fclose(store_data);
    }


}

void counter(void)
{
    int total = 0;
    FILE *read;
    read = fopen("store_data.txt", "r");
    while (fscanf(read, "%d \t%s \t%s \t%s \t%s \t%d \t%d-%d-%d\n", &details.id, details.firstname, details.lastname, details.contact, details.location, &details.age,&details.day,&details.month,&details.year) != EOF)
    {
        total = details.id;
    }
    printf("TOTAL REGISTERED : %d\n", total);
    choice();
}

void generated_form()
{
    FILE *read;
    read=fopen("store_data.txt","r");
    if(read==NULL)
    {
        printf("NO data Found");
        choice();
    }
    int p_id;
    printf("Enter Id : ");
    scanf("%d",&p_id);
    int flag=0;
    while(fscanf(read,"%d \t%s \t%s \t%s \t%s \t%d \t%d-%d-%d\n",&details.id,details.firstname,details.lastname,details.contact,details.location,&details.age,&details.day,&details.month,&details.year)!=EOF)
    {

        if(details.id==p_id)
        {
            flag=1;
            printf("\n\n\n\t\t\t_____________________________________________________________________________________________________\n");
            printf("\t\t\t|  _______________________________________________________________________________________________  |\n");
            printf("\t\t\t| |                                                                                               | |\n");
            printf("\t\t\t| |                               Details of the Patient By Id                                    | |\n");
            printf("\t\t\t| |_______________________________________________________________________________________________| |\n");
            printf("\t\t\t|___________________________________________________________________________________________________|\n");
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t    ID: %d                                                                                        \n", details.id);
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t    Name: %s %s                                                                                   \n", details.firstname, details.lastname);
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t    Age: %d                                                                                       \n", details.age);
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t    Contact: %s                                                                                   \n", details.contact);
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t    Location: %s                                                                                  \n",details.location);
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t    Registration Date:  %d-%d-%d                                                                  \n",details.day,details.month,details.year);
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t    Visit %s Govt Hospital For Vaccination after Two Days                                        \n",details.location);
            printf("\t\t\t                                                                                                  \n");
            printf("\t\t\t ___________________________________________________________________________________________________\n");
            printf("\t\t\t|___________________________________________________________________________________________________|\n");
        }
    }
    if(flag==0)
    {
        printf("File Not found for ID: %d\n",p_id);
    }
    fclose(read);
}

void total()
{
    int total=0;
    FILE *read;
    read=fopen("store_data.txt","r");
    while (fscanf(read,"%d \t%s \t%s \t%s \t%s \t%d \t%d-%d-%d\n",&details.id,details.firstname,details.lastname,details.contact,details.location,&details.age,&details.day,&details.month,&details.year)!=EOF)
    {
        total=details.id;
    }
    printf("TOTAL REGISTERED : %d\n",total);

}

void tail()
{
    printf("\t\t\t\t _________________________________________________________________________________________________________\n");
    printf("\t\t\t\t|  _____________________________________________________________________________________________________  |\n");
    printf("\t\t\t\t| |                                                                                                     | |\n");
    printf("\t\t\t\t| |                                       THANKS FOR VISITING. :)                                       | |\n");
    printf("\t\t\t\t| |_____________________________________________________________________________________________________| |\n");
    printf("\t\t\t\t|_________________________________________________________________________________________________________|\n");
    printf("\t\t\t\t                                                                                                     DASHY\n");

}

void choice()
{
    char ch[4];
    do
    {
        short int op;
        printf("1. Registeration for Vaccine\n");
        printf("2. Generate your form from id\n");
        printf("3. Count Total No of Patient\n");
        printf("4. Frequently Asked Questions\n");
        printf("5. exit from portal\n\n");
        printf("Enter respective option number which you want to select :");
        scanf("%hu", &op);
        switch (op)
        {
        case 1:
            registration_form();
            break;
        case 2:
            generated_form();
            break;
        case 3:
            total();
            break;
        case 4:
            fAQ();
            break;
        case 5:
            tail();
            exit(0);

        default:
            printf("*PLEASE SELECT FROM GIVEN numbers.\n");
        }
        printf("\n\n\n Do you want to explore more ? yes/no : ");
        scanf("%s", ch);

        printf("\n");
        if (strcmp(ch, "no") == 0 || strcmp(ch, "No") == 0 || strcmp(ch, "NO") == 0)
            tail();
    }
    while (strcmp(ch, "yes") == 0 || strcmp(ch, "Yes") == 0 || strcmp(ch, "YES") == 0);
}

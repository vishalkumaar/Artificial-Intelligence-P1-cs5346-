/*Enclosed a program, which comprises the inference engine based on backward chaining.  You need it for your
 project #1.  The program contains some errors and it is not designed to be efficient.
 Modify the program to make it better and efficient.  Explain in your report how you have modified the
 program to make it better.*/

//TO DO:
//1- Remove globals
//X1a- change variable list
//X2- Remove gotos
//X3- Use cpp libraries rather than c
//X3a- change printf to cout
//X3b- use string instead of char[]
//3c- use string.compare instead of strcmp
//X3d- use cin instead of gets
//X4- re-write question to make sense





/*****backward chaining *******/
/* Install your IF clauses in sequence in the first case
 statement of the main program
 example: if((a1==2) && (a2==6)) s=1;
 if(strcmp(j,NO") != 0) s=1;
 the then part of the above construction always
 contains s=1;
 install your the clauses in sequence in the second
 case statement of the main program
 example strcpy(po,"YES");*/

#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

bool debug = true;
/*  conclusion list */
string conclusionList[21];
/*  variable list */
string variableList[18];
/*  clause vairable list */
string clauseVariableList[69];
string variable;
string /* qualify */ goodGrades, /* degree*/ degree;
string /* discovery */ labwork, /* position */ profession;
string outdoorWork, leadership, groupWork, medSchool, medCert, TeachCert,MedField,Criminal,workAlone;
int coursesWithLabs, groupLeader, hoursOutside;
char buff[128];
string buffer;

/* instantiated list */
int i,instantiatedList[18];
/* statement stack */
int statementStack[11];
int /* clause stack */ clauseStack[11], sn, f, s, /*stack pointer */ stackPointer;

float /* grade */ grade, /*experience */ ex;

void determine_member_concl_list(void);
void push_on_stack(void);
void instantiate(void);
void b545(void);
void InBetweenFunction(void);
void b520(void);
void KeepProcessing(void);//if the conclusion is not found.
void popStack(void);


int main()
{
    /***** initialization section ******/
    /* stack space is 10 we initially place stack space at 10+1 */
    stackPointer=17;
    for (int i=0; i<17; i++)
    {
        //strcpy(conclt[i],"");
        //strcpy(varlt[i],"");
        instantiatedList[i]=0;
        statementStack[i]=0;
        clauseStack[i]=0;
    }

    for (int i = 0; i < 21; i++)
        conclusionList[i].assign(" ");
    for (int i = 0; i < 18; i++)
        variableList[i].assign(" ");
    for (int i=0; i<69; i++)
        clauseVariableList[i].assign(" ");
    /* enter conclusions which are the variables in the then part, 1 at
     a time.  enter the conclusions in exact order starting at the 1st
     if-then.  after last conclusion hit return key for rest of
     conclusions */

    /*** comment 305 *****/
    //strcpy(conclt[1], "PO");
    conclusionList[1].assign("GOODGRADES");
    //strcpy(conclt[2], "QU");
    conclusionList[2].assign("GOODGRADES");
    //strcpy(conclt[3], "PO");
    conclusionList[3].assign("LABWORK");
    //strcpy(conclt[4], "PO");
    conclusionList[4].assign("LEADERSHIP");
    //strcpy(conclt[5], "PO");
    conclusionList[5].assign("PROFESSION");
    //strcpy(conclt[6], "PO");
    conclusionList[6].assign("PROFESSION");
    conclusionList[7].assign("PROFESSION");
    conclusionList[8].assign("WORKALONE");
    conclusionList[9].assign("PROFESSION");
    conclusionList[10].assign("PROFESSION");
    conclusionList[11].assign("OUTDOOR WORK");
    conclusionList[12].assign("PROFESSION");
    conclusionList[13].assign("PROFESSION");
    conclusionList[14].assign("PROFESSION");
    conclusionList[15].assign("MEDICALCERTIFICATE");
    conclusionList[16].assign("PROFESSION");
    conclusionList[17].assign("TEACHINGCERTIFICATE");
    conclusionList[18].assign("PROFESSION");
    conclusionList[19].assign("PROFESSION");
    conclusionList[20].assign("PROFESSION");
    //printf("*** CONCLUSION LIST ***\n");
    for (int i=1; i<21; i++) /*printf("CONCLUSION %d %s\n", i,conclt[i])*/ cout << "Conclusion: " << i << " " << conclusionList[i] << endl;

    //printf("HIT RETURN TO CONTINUE");
    cout << "Hit Return to continue..." << endl;
    //gets(buff);
    getchar();
    /* enter variables which are in the if part, 1 at a time in the exact
     order that they occur, up to 3 variables per if statement.  do not
     duplicate any variable names.  any name is used only once.  if no
     more variables left just hit return key. */
    //printf("*** VARIABLE LIST *\n");
    cout << "Variable List:" << endl;
    /**** comment 367 *****/
    //strcpy(varlt[1], "DE");
    variableList[1].assign("DEGREE");
    //strcpy(varlt[2], "DI");
    variableList[2].assign("GOOD GRADES");
    //strcpy(varlt[3], "EX");
    variableList[3].assign("LAB WORK");
    //strcpy(varlt[4], "GR");
    variableList[4].assign("LEADERSHIP");
    variableList[5].assign("MED SCHOOL");
    variableList[6].assign("GROUP WORK");
    variableList[7].assign("WORK ALONE");
    variableList[8].assign("OUTDOOR WORK");
    variableList[9].assign("MEDICAL CERTIFICATE");
    variableList[10].assign("TEACHER CERTIFICATE");
    variableList[11].assign("GPA");
    variableList[12].assign("PROFESSION");
    variableList[13].assign("COURSES WITH LABS");
    variableList[14].assign("GROUP LEADER");
    variableList[15].assign("HOURS OUTSIDE");
    variableList[16].assign("MED FIELD");
    variableList[17].assign("CRIMINAL BACKGROUND");
    for(int i=1; i<18; i++) /*printf("VARIABLE %d %s\n", i, varlt[i])*/ cout << "Variable: " << i << " " << variableList[i]<<endl;
    //printf("HIT RETURN KEY TO CONTINUE");
    cout << "Hit Return to continue..."<<endl;
    //gets(buff);
    getchar();
    /* enter variables as they appear in the if clauses.  a maximum of 3
     variables per if statement.  if no more variables hit return key. */
    // printf("*** CLAUSE VARIABLE LIST ***\n");
    cout<<"****Clause variable list****"<<endl;
    /***** comment 407 through 409 ***/
    //strcpy(clvarlt[1], "DE");
    clauseVariableList[1].assign("GPA");
    //strcpy(clvarlt[5], "DE");
    clauseVariableList[5].assign("GPA");
    //strcpy(clvarlt[9], "DE");
    clauseVariableList[9].assign("COURSES WITH LABS");
    //strcpy(clvarlt[10], "DI");
    clauseVariableList[13].assign("GROUP LEADER");
    //strcpy(clvarlt[13], "QU");
    clauseVariableList[17].assign("DEGREE");
    clauseVariableList[18].assign("GOOD GRADES");
    //strcpy(clvarlt[14], "GR");
    clauseVariableList[21].assign("DEGREE");
    clauseVariableList[22].assign("GOOD GRADES");
    clauseVariableList[23].assign("LAB WORK");
    //strcpy(clvarlt[15], "EX");
    clauseVariableList[25].assign("DEGREE");
    clauseVariableList[26].assign("LEADERSHIP");
    //strcpy(clvarlt[17], "QU");
    clauseVariableList[29].assign("GROUP WORK");
    //strcpy(clvarlt[18], "GR");
    clauseVariableList[33].assign("DEGREE");
    clauseVariableList[34].assign("MED SCHOOL");
    clauseVariableList[35].assign("GROUP WORK");
    //strcpy(clvarlt[19], "EX");
    clauseVariableList[37].assign("DEGREE");
    clauseVariableList[38].assign("WORK ALONE");
    clauseVariableList[41].assign("HOURS OUTSODE");
    clauseVariableList[45].assign("DEGREE");
    clauseVariableList[46].assign("OUTDOOR WORK");
    clauseVariableList[49].assign("DEGREE");
    clauseVariableList[50].assign("GROUP WORK");
    clauseVariableList[53].assign("DEGREE");
    clauseVariableList[54].assign("OUTDOOR WORK");
    clauseVariableList[57].assign("MED SCHOOL");
    clauseVariableList[58].assign("MED FIELD");
    clauseVariableList[61].assign("DEGREE");
    clauseVariableList[62].assign("MEDICAL CERTIFICATE");
    clauseVariableList[63].assign("GROUP WORK");
    clauseVariableList[65].assign("CRIMINAL BACKGROUND");
    clauseVariableList[69].assign("DEGREE");
    clauseVariableList[70].assign("TEACHING CERTIFICATE");
    clauseVariableList[73].assign("DEGREE");
    clauseVariableList[74].assign("OUTDOOR WORK");
    clauseVariableList[77].assign("DEGREE");
    clauseVariableList[78].assign("GOOD GRADES");
    clauseVariableList[79].assign("GOOD WORK");

    //strcpy(clvarlt[21], "QU");
    //strcpy(clvarlt[22], "GR");
    for(int i=1; i<18; i++)
    {
        // printf("** CLAUSE %d\n", i);
        cout<<"***CLAUSE*** "<<i << endl;
        for(int j=1; j<5; j++)
        {
            int k = 4 * (i-1) + j;

            //printf("VARIABLE %d  %s\n", j, clvarlt[k]); }
            cout<<" VARIABLE "<< j <<clauseVariableList[k]<<endl;
        }


        if (i==17)
        {
            //printf("HIT RETURN KEY TO CONTINUE"); gets(buff); }
            cout<<"HIT THE RETURN KEY TO CONTINUE..."<<endl;
            getchar();
        }
    }
    /****** inference section *****/
    //printf("** ENTER CONCLUSION ? "); gets(varble);

    // cout<<"****ENTER CONCLUSION? "<<endl;
    cout<<"Conclusion here is.... ";
    cin>>variable;//----variable.assign("PROFESSION");
    //----cout << variable << endl;
    b520();


}
void b520()
{
    if (debug) cout << "B520 called" << endl;
    /* get conclusion statement number (sn) from the conclusion list
     (conclt) */
    /* first statement starts search */
    f=1;
    determine_member_concl_list();
    if (sn != 0)
    {

        //     KeepProcessing();
        //        if(sn!=0)
        //       {
        InBetweenFunction();
        popStack();
        //}
    }
    else instantiate();
}

void KeepProcessing()
{
    if (debug) cout << "Keep Processing called" << endl;

    /* if sn = 0 then no conclusion of that name */
    do
    {
        /* push statement number (sn) and clause number=1 on goal
         stack which is composed of the statement stack (statsk)
         and clause stack (clausk) */

        push_on_stack();
        b545();
    }
    while((s != 1) && (sn !=0));
}


void b545()
{
    if (debug) cout << "B545 called" << endl;
    do {
        /* calculate clause location in clause-variable
         list */
        i= (statementStack[stackPointer] -1) *4 + clauseStack[stackPointer];
        /* clause variable */
        //strcpy(variable, clauseVariableList[i]);
        variable.assign(clauseVariableList[i]);
        if(strcmp(variable.c_str(), "") != 0) {
            /*is this clause variable a conclusion? */
            f = 1;
            determine_member_concl_list();
            if(sn != 0)
            /* it is a conclusion push it */
                b520();
            /* check instantiation of this clause */
            instantiate();
            clauseStack[stackPointer] = clauseStack[stackPointer] + 1;
        }
    } while(strcmp(variable.c_str(), "") != 0); /*End of inside do-while*/
    /*no more clauses check if part of statement */
    sn = statementStack[stackPointer];
    s = 0;
    /**** if then statements ****/
    /* sample if parts of if then statements from
     the position knowledge base */

    switch (sn) { //Left hand side of Rules
            /* if part of statement 1 */
            /****** comment 1500 ****/
        case 1: //if(strcmp(degree.c_str(), "NO") == 0) s = 1;
            if (grade >= 3.5) s = 1;
            break;
            /* if part of statement 2 */
            /***** comment 1510 ******/
        case 2: //if(strcmp(degree.c_str(), "YES") == 0) s = 1;
            if (grade < 3.5) s = 1;
            break;
            /* if part of statement 3 */
        case 3: //if((strcmp(degree.c_str(), "YES") == 0) &&
                //   (strcmp(labwork.c_str(), "YES") == 0)) s =1;
            if (coursesWithLabs > 2) s = 1;
            break;
            /* if part of statement 4 */
            /******** comment 1560 ******/
        case 4: //if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                //   (grade<3.5) && (grade >= 2)) s = 1;
            if (groupLeader >= 1) s = 1;
            break;
            /******** comment 1570 ********/
            /* if part of statement 5 */
        case 5: //if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                //   (grade<3) && (grade<2)) s = 1;
            if (strcmp(degree.c_str(), "engineering\0") == 0 && strcmp(goodGrades.c_str(), "true\0") == 0) s = 1;
            break;
            /* if part of statement 6 */
        case 6: //if((strcmp(goodGrades.c_str(), "YES") == 0) &&
                //   (grade >=3.5)) s = 1;
            if (strcmp(degree.c_str(), "science\0") == 0 && strcmp(goodGrades.c_str(), "true\0") && strcmp(labwork.c_str(), "true\0")) s = 1;
            break;
        case 7: if(strcmp(degree.c_str(), "none\0") != 0 && strcmp(leadership.c_str(), "true\0")) s = 1;
            break;
        case 8: if (strcmp(groupWork.c_str(), "false\0") == 0) s = 1;
            break;
        case 9: if (strcmp(degree.c_str(), "none\0") != 0 && strcmp(medSchool.c_str(), "true\0") == 0 && strcmp(groupWork.c_str(), "true\0") == 0) s = 1;
            break;
        case 10: if (strcmp(degree.c_str(), "english\0") == 0 && strcmp(workAlone.c_str(), "true\0")) s = 1;
            break;
        case 11: if (hoursOutside >= 16) s = 1;
            break;
        case 12: if (strcmp(degree.c_str(), "science\0") == 0 && strcmp(outdoorWork.c_str(), "true/0") == 0) s = 1;
            break;
        case 13: if (strcmp(degree.c_str(), "psychology\0") == 0 && strcmp(groupWork.c_str(), "true\0") == 0) s = 1;
            break;
        case 14: if (strcmp(degree.c_str(), "none\0") == 0 && strcmp(outdoorWork.c_str(), "true\0") == 0) s = 1;
            break;
        case 15: if (strcmp(medSchool.c_str(), "false\0") == 0 && strcmp(MedField.c_str(), "true\0") == 0) s = 1;
            break;
        case 16: if (strcmp(degree.c_str(), "none\0") != 0 && strcmp(medCert.c_str(), "true\0") == 0 && strcmp(groupWork.c_str(), "true") == 0) s = 1;
            break;
        case 17: if (strcmp(Criminal.c_str(), "true\0") == 0) s = 1;
            break;
        case 18: if (strcmp(degree.c_str(), "none\0") != 0 && strcmp(TeachCert.c_str(), "true\0") == 0) s = 1;
            break;
        case 19: if (strcmp(degree.c_str(), "none\0") == 0 && strcmp(outdoorWork.c_str(), "false\0") == 0) s = 1;
            break;
        case 20: if (strcmp(degree.c_str(), "cs\0") == 0 && strcmp(goodGrades.c_str(), "true\0") == 0 && strcmp(groupWork.c_str(), "true\0")) s = 1;
            break;
        default : cout << "Unusable statement number." << endl;
            /********* comment 1680 ******/
    } //end of switch
    /* see if the then part should be invoked */
    if( s != 1)
    {
        /* failed..search rest of statements for
         same conclusion */
        /* get conclusion */
        i = statementStack[stackPointer];
        //strcpy(variable, clauseVariableList[i]);
        variable.assign(clauseVariableList[i]);
        /* search for conclusion starting at the
         next statement number */
        f = statementStack[stackPointer] + 1;
        determine_member_concl_list();
        stackPointer = stackPointer+1;
    } //end of if
    /* pop old conclusion and put on new one */
}   /*End of outer do-while loop */


void InBetweenFunction()
{
    if (debug) cout << "In Between Function Called" << endl;
    if(sn != 0)
    {
        /* if part true invoke then part */
        /* then part of if-then statements from the
         position knowledge base */
        switch (sn)
        {
                /* then part of statement 1 */
                /******* comment 1500 *******/
            case 1: //strcpy(po, "NO");
                //printf("PO=NO\n");
                goodGrades.assign("true");
                cout<<"Good Grades = YES";
                break;
                /* then part of statement 2 */
                /****** comment 1510 ******/
            case 2: //strcpy(qu, "YES");
                //printf("QU=YES\n");
                goodGrades.assign("false");
                cout<<"Good Grades = NO";
                break;

                /* then part of statement 3 */
            case 3: labwork.assign("true");
                cout<<"LAB WORK = YES";
                break;
                /* then part of statement 4 */
                /******** comment 1560 ******/
            case 4: leadership.assign("true");
                cout<<"leadership = YES";
                break;
                /* then part of statement 5 */
                /****** comment 1570 *****/
            case 5: profession.assign("Engineering");
                cout<<"Profession = Engineering";
                break;
                /* then part of statement 6 */
            case 6: profession.assign("Science");
                cout<<"Profession = Science";
                break;
            case 7: profession.assign("Business");
                cout<<"Profession = Business";
                break;

            case 8: workAlone.assign("true");
                cout<<"workAlone = YES";
                break;


            case 9: profession.assign("Medical");
                cout<<"Profession = Medical";
                break;

            case 10 : profession.assign("English");
                cout<<"Profession = English";
                break;

            case 11: outdoorWork.assign("true");
                cout<<"outdoorWork = YES";
                break;

            case 12 : profession.assign("geography");
                cout<<"Profession = geography";
                break;

            case 13 : profession.assign("psychology");
                cout<<"Profession = psychology";
                break;

            case 14 : profession.assign("agriculture");
                cout<<"Profession = agriculture";
                break;

            case 15: medCert.assign("true");
                cout<<"medCert = YES";
                break;

            case 16 : profession.assign("Health care");
                cout<<"Profession = Health";
                break;

            case 17: TeachCert.assign("true");
                cout<<"Teaching certification = YES";
                break;

            case 18: profession.assign("education");
                cout<<"Profession = education";
                break;

            case 19: profession.assign("property management");
                cout<<"Profession = prop management";
                break;

            case 20: profession.assign("Computer science");
                cout<<"Profession = CS";
                break;
                /****** comment 1680 ********/
        }
    }
}//end of switch
/* pop the stack */


void popStack()
{
    if (debug) cout << "Pop Stack" << endl;
    stackPointer=stackPointer+1;

    if(stackPointer >= 11)
    {
        /* finished */
        printf("*** SUCCESS\n");
//        exit(0);
    }
    else
    {
        /* stack is not empty */
        /* get next clause then continue */
        clauseStack[stackPointer] = clauseStack[stackPointer]+1;
        b545();
        if((s!=1)&&(sn!=0))
        {
            KeepProcessing();
        }
        else if(sn!=0)
        {
            InBetweenFunction();
            popStack();
        }
    }
    //end of 2nd if (sn != 0)
}//end of 1st if (sn != 0)
//end of main

void determine_member_concl_list() {
    /* routine to determine if a variable (varble) is a member of the
     conclusion list (conclt).  if yes return sn != 0.
     if not a member sn=0;
     */
   if (debug) cout << "Determine Member Conclussion List called for " << variable << endl;
   if (debug) getchar();
    /* initially set to not a member */



    sn = 0;
    /* member of conclusion list to be searched is f */


    int i = f;
    //---- while((strcmp(variable.c_str(), conclusionList[i].c_str()) != 0) &&(i<21))
    while(strcmp(variable.c_str(),conclusionList[i].c_str()) != 0 && (i<21))
    /* test for membership */
        i=i+1;
    if (strcmp(variable.c_str(), conclusionList[i].c_str())==0)
 //   if(variable==conclusionList[i])

        sn = i;  /* a member */
    if (debug) {
        if (sn != 0)cout << "Determine Member Conclussion List found conclusion = " << conclusionList[i] << " at i= " << i << " and sn = " << sn << endl ;
        else cout << "Variable not found in conclussion list" << endl;
    }
}

void push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
 conclusion stack which consists of the statement stack (statsk) and the
 clause stack (clausk)..to push decrement stack pointer (sp) */
{
    //----- if (debug)
    if (debug) cout << "Push on Stack Called" << endl;
    stackPointer=stackPointer-1;
    statementStack[stackPointer] = sn;
    clauseStack[stackPointer] = 1;
    //---if (debug)
    if (debug) cout << "Stack pointer is now: " << stackPointer << endl;
}

void instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
 instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
 variable list (varlt) contains the variable (varble). */
{
    int  i=1;
    /* find variable in the list */
    while((strcmp(variable.c_str(), variableList[i].c_str()) != 0) && (i<18))
        i=i+1;
    if((strcmp(variable.c_str(), variableList[i].c_str()) == i) && (instantiatedList[i] != 1)) {
        /*found variable and not already instantiated */
        if (debug) cout << "Instantiate called for " << variableList[i] << endl;
        instantiatedList[i]=1; /*mark instantiated */
        /* the designer of the
         knowledge base places the input statements to
         instantiate the variables below in the case statement */
        switch (i)
        {
                /***** input statement *****/
                /* input statements for sample position knowledge
                 base */
                /***** comment 1700 ******/
                //case 1: printf("INPUT YES OR NO FOR DE-? ");
                //        gets(de);
            case 1: cout << "What degree are you working towards?";
                cin >> degree;
                cout << endl;
                break;
                //case 2: printf("INPUT YES OR NO FOR DI-? ");
                //        gets(di);
            case 2: cout << "What GPA do you maintain?";
                cin >> grade;
                if (grade > 3.5)
                    goodGrades.assign("true");
                else
                    goodGrades.assign("false");
                break;
                //case 3: printf("INPUT A REAL NUMBER FOR EX-? ");
                //        scanf("%f", &ex);
            case 3: cout << "How many courses will you take that include a lab section?";
                cin >> coursesWithLabs;
                break;
            case 4:// printf("INPUT A REAL NUMBER FOR GR-? ");
                // scanf("%f", &gr);
                cout << "How many group projects have you been the leader off?";
                cin >> groupLeader;
                if (groupLeader >= 1) leadership.assign("true");
                else leadership.assign("false");
                break;
            case 5: cout << "Will you go to med school after college? ";
                cin >> buffer;
                if (buffer.compare("yes") == 0 || buffer.compare("y") == 0)
                    medSchool.assign("true");
                else medSchool.assign("false");
                break;
                /***** comment 1715 ****/
            case 6: cout << "Do you like working in groups? ";
                cin >> buffer;
                if (buffer.compare("yes") == 0 || buffer.compare("y") == 0)
                    groupWork.assign("true");
                else groupWork.assign("false");
                break;
            case 7: cout << "Do you like working in groups? ";
                cin >> buffer;
                if (buffer.compare("yes") == 0 || buffer.compare("y") == 0)
                    workAlone.assign("false");
                else workAlone.assign("true");
                break;
            case 8: cout << "How many hours do you spend outside every week? ";
                cin >> hoursOutside;
                if (hoursOutside > 15)
                    outdoorWork.assign("true");
                else
                    outdoorWork.assign("false");
                break;
            case 9: cout << "Will you get a medical certification? ";
                cin >> buffer;
                if (buffer.compare("yes") == 0 || buffer.compare("y") == 0)
                    medCert.assign("true");
                else medCert.assign("false");
                break;

            case 10: cout<< "Will you get a Teaching certification? ";
                cin>>buffer;
                if(buffer.compare("yes")==0||buffer.compare("y")==0)
                    TeachCert.assign("true");
                else
                    TeachCert.assign("false");
                break;

            case 11: cout<<"What is your GPA?";
                cin >> grade;
                if (debug) cout << "Grade is " << grade << endl;
                break;

            case 12 : cout<< "What do you want to do?";
                cin>>profession;
                break;

            case 13: cout << "How many courses will you take that include a lab section?";
                cin >> coursesWithLabs;
                break;

            case 14: cout<< "How many projects have you been a group leader for?";
                cin>>groupLeader;
                break;

            case 15: cout<<"How many hours are you outside per week? " ;
                cin>>hoursOutside;
                break;

            case 16: cout<<"Are you interested to study regarding the health care?";
                cin>>buffer;
                if(buffer.compare("yes")==0||buffer.compare("y")==0)
                    MedField.assign("true");
                else
                    MedField.assign("false");
                break;

            case 17 : cout<<"Do you have a criminal background?";
                cin>>buffer;
                if(buffer.compare("yes")==0||buffer.compare("y")==0)
                    Criminal.assign("true");
                else
                    Criminal.assign("false");
                break;

            default: cout<<"********************";
                break;



        } //end of switch
        /* end of inputs statements for sample position knowledge
         base */
    }//end of if((strcmp(variable...
}//end of func




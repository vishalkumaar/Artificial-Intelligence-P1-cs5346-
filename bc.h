#include<string>

class BC
{
	private:
		/* Variables declared here */
        static const int size = 21;
        static const int clauseSize = 81;
        std::string conclusionList[size], variableList[size], clauseVariableList[clauseSize];
        std::string varble;
        std::string goodGrades, degree;
        std::string labwork, profession;
        std::string outdoorWork, leadership;
        std::string groupWork, medSchool, medCert;
        std::string teachCert,medField,criminal,workAlone;
        int coursesWithLabs, groupLeader, hoursOutside;
        std::string buff;
        bool done;
        int instantiatedList[size];
        int statementStack[size], clauseStack[size], statementNumber, f, statementActive, stackPointer;
        float grade;
        bool debug;
        void B520();
    	void KeepProcessing();
    	void determine_member_concl_list();
    	void push_on_stack();
    	void instantiate();
    	void initkbase(int);
    	void InBetweenFunction();
    	void popStack();
        void B545();

    public:
    	BC(bool debug = false);
    	void inferenceSection();
        void printProfession();
        std::string getProfession() {return profession;}
};

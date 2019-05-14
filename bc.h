#include<string>

class BC
{
	private:
		/* Variables declared here */
        static const int size = 21;
        static const int clauseSize = 69;
        std::string conclusionList[size], variableList[size], clauseVariableList[clauseSize];
        std::string varble, qu, de, di, po;
        std::string goodGrades, degree;
        std::string labwork, profession;
        std::string outdoorWork, leadership;
        std::string groupWork, medSchool, medCert;
        std::string teachCert,medField,criminal,workAlone;
        int coursesWithLabs, groupLeader, hoursOutside;
        std::string buff;
        int instantiatedList[size];
        int statementStack[size], clauseStack[size], statementNumber, f, statementActive, stackPointer;
        float gr, ex, grade;
        bool debug;
    public:
    	BC(bool debug = false);
    	void inferenceSection();
    	void B520();
    	void KeepProcessing();
    	void determine_member_concl_list();
    	void push_on_stack();
    	void instantiate();
    	void initkbase(int);
    	void InBetweenFunction();
    	void popStack();
        void B545();
        void printProfession();
};

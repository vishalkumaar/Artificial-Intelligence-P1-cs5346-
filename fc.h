#include <string>

class FC
{

private:
    int flag;
    bool debug, done;
    bool inst = false;
    static const int size = 61;
    static const int clauseSize = 241;
    std::string conditionVariableQueue[size], variableList[size],clauseVariableList[clauseSize],clause,varble;
    int instantiatedList[size];/* instantiated list*/
    std::string fedint,interest,stock,dollar,fedmon;
    std::string likePhysics, likeMath, groupWork, likeBiology;
    std::string likeChemistry, likeMarketing, likeManagement;
    std::string goodCredit, likeMedicalEthics, stateLicensure;
    std::string likeWriting, likeOriginality, likeMedia;
    std::string likeSocialScience, likeEnglish;
    std::string likeReading, likeClimate, likeStones;
    std::string likeLand, likeSoil, likeWaterResources;
    std::string likeAnalyticalSkills, likeInternship, likeAnatomy;
    std::string likeChildren, reliable, likeRepairs;
    std::string profession, area, likeLaw, likeCommunication;
    int f, k, statementActive, frontPointer   /* front pointer */;
    int  backPointer  /* back pointer */,  statementNumber; /* statement number */
    int clauseNumber;  /* clause number */
    bool isYes(std::string);
    void ifcondtions();
    void Result();
    void takingInput(int);
    void search();
    void check_instantiation();
    void instantiate();
    void inference();
    void gotoF();

public:
    FC(std::string, bool);
    void start();
    std::string getArea() {return area;}
    std::string getProfession() {return profession;}
    void printProfession();
    void printArea();
};

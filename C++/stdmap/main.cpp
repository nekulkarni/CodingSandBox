#include <cstdio>
#include <map>
#include <string>
#include <set>

int main(int argc, char const *argv[])
{
    std::map<std::string, char> gradeList;
    gradeList["neeraj"] = 'B';
    gradeList["vassey"] = 'A';

    printf("grade for %s is %c\n", "neeraj", gradeList["neeraj"]);
    printf("grade for %s is %c\n", "vassey", gradeList["vassey"]);

    printf("gradeList[%s] is %s\n","neeraj", (gradeList.find("neeraj") == gradeList.end())? "Absent" : "Present" );
    printf("gradeList[%s] is %s\n","kutra", (gradeList.find("kutra") == gradeList.end())? "Absent" : "Present" );


    // std::set

    std::set<std::string> nameSet;
    nameSet.insert("neeru");
    nameSet.insert("neerya");
    nameSet.insert("chambs");
    

    // query now
    std::string queryNames[] = {"bappa", "chambya", "neeru", "neerya", "chambs", "niramaya", "shastradnya"};
    unsigned size = 

    for (int i = 0; i < queryNames.size(); ++i)
    {
        /* code */
    }
    printf("[%s] is %s\n","kutra", (gradeList.find("kutra") == gradeList.end())? "Absent" : "Present" );


    return 0;
}





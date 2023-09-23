#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string temp;
    
    float score;
    string grade;
    float subjectgrade;   
    
    float subjectSum = 0;
    float majorGpaSum = 0;
    
    for(int i = 0 ; i < 20; i ++){
        getline(cin, temp);
        
        stringstream s1(temp);
        s1>>temp>>score>>grade;    

        if(grade == "P")        continue;
 
        if(grade == "A+")       subjectgrade = 4.5f;
        else if(grade == "A0")  subjectgrade = 4.0f;
        else if(grade == "B+")  subjectgrade = 3.5f;
        else if(grade == "B0")  subjectgrade = 3.0f;
        else if(grade == "C+")  subjectgrade = 2.5f;
        else if(grade == "C0")  subjectgrade = 2.0f;
        else if(grade == "D+")  subjectgrade = 1.5f;
        else if(grade == "D0")  subjectgrade = 1.0f;
        else if(grade == "F")   subjectgrade = 0.0f;
            
        majorGpaSum += score * subjectgrade;
        subjectSum += score;
    }
    
    cout<<majorGpaSum/subjectSum;
}
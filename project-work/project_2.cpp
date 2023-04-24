#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
int main(){
    int numStud , numCourse;
    cout<<"Enter the number of students: ";
    cin>>numStud;
    cout<<"Enter the number of courses: ";
    cin>>numCourse;
    if(numStud<0 || numCourse<0){
        return 0;
    }
    int subIndex , n , percent , *count2 = new int[numStud] , *orders , fails;
    unsigned int *crHr = new unsigned int[numCourse];
    char menu , menu2;
    string *subjectName = new string[numCourse] , *studId = new string[numStud] , **gradeMark = new string*[numStud] , searchId , searchSub , lastId , orderId;
    float *totalCrHr = new float[numStud] , *totalPoint = new float[numStud] , *cgpa = new float[numStud] , *totalMark = new float[numStud];
    float **subjectMark = new float*[numStud] , **point = new float*[numStud] , *avg = new float[numStud] , *temp = new float[numStud] , order , minValue;

    for(int i=0; i<numStud; ++i){
        totalCrHr[i] = 0;
        totalPoint[i] = 0;
        totalMark[i] = 0;
        temp[i] = 0;

        //declaring dynamic 2D arrays
        subjectMark[i] = new float[numCourse];
        point[i] = new float[numCourse];
        gradeMark[i] = new string[numCourse];
    }
    for(int i=0; i<numCourse; ++i){
        cout<<endl<<"Enter the name of course "<<i+1<<" (use 4 characters): ";
        cin>>subjectName[i];
        if((subjectName[i]).length() != 4){
            cout<<"Please use 4 characters: ";
            cin>>subjectName[i];
        }
        if(subjectName[i].length() != 4){
            return 0;
        }

        cout<<"Enter the credit hour of "<<subjectName[i]<<" : ";
        cin>>crHr[i];
    }

    for(int i=0; i<numStud; ++i){
        count2[i]=0;
        int error;
        do{
            error=0;
            cout<<endl<<"Enter the ID of student "<<i+1<<" (like ETS0000/10): ";
            cin>>studId[i];
            if(studId[i].length() != 10){
                cout<<"Please use 10 characters (like ETS0000/10): ";
                cin>>studId[i];
            }
            if(studId[i].size() != 10){
                count2[i] = 2;
            }
            for(int j=0; j<i; ++j){
                if(studId[i] == studId[j]){
                    cout<<"The student is already in database."<<endl;
                    error+=1;
                    break;
                }
            }
            count2[i]+=1;
        }while(error!=0 && count2[i]<3);

        if(count2[i] == 3){
            fails+=1;
            continue;
        }
        for(int j=0; j<numCourse; ++j){

            int k=0;
            do{
                cout<<"Enter the mark of "<<subjectName[j]<<" for "<<studId[i]<<" (enter '101' for NG): ";
                cin>>subjectMark[i][j];
                if(subjectMark[i][j] == 101){
                    k = 2;
                }
                else if((subjectMark[i][j] < 0 || subjectMark[i][j] > 100) && k<3){
                    cout<<"You entered wrong input!! ";
                    if(k<2){
                        cout<<"Try again!";
                    }
                    cout<<endl;
                }
                ++k;
            }while((subjectMark[i][j] < 0 || subjectMark[i][j] > 100) && k<3);

            if(subjectMark[i][j] < 0 || subjectMark[i][j] > 100){
                gradeMark[i][j] = "NG";
                point[i][j] = 0;
                subjectMark[i][j] = 0;
            }
            else if(subjectMark[i][j] >= 85){
                point[i][j] = 4.0;
                gradeMark[i][j] = "A ";
            }
            else if(subjectMark[i][j] >= 75){
                point[i][j] = 3.5;
                gradeMark[i][j] = "B+";
            }
            else if(subjectMark[i][j] >= 70){
                point[i][j] = 3.0;
                gradeMark[i][j] = "B ";
            }
            else if(subjectMark[i][j] >= 60){
                point[i][j] = 2.5;
                gradeMark[i][j] = "C+";
            }
            else if(subjectMark[i][j] >= 50){
                point[i][j] = 2.0;
                gradeMark[i][j] = "C ";
            }
            else if(subjectMark[i][j] >= 40){
                point[i][j] = 1.5;
                gradeMark[i][j] = "D ";
            }
            else{
                point[i][j] = 0.0;
                gradeMark[i][j] = "F ";
            }

            if(gradeMark[i][j] == "NG"){
                continue;
            }

            temp[i] += 1;
            totalMark[i] += subjectMark[i][j];

            totalPoint[i] += (crHr[j] * point[i][j]);
            totalCrHr[i] += crHr[j];
        }

        if(temp[i] == 0){  //if all grades are NG
            continue;
        }

        avg[i] = totalMark[i] / temp[i];
        cgpa[i] = totalPoint[i] / totalCrHr[i];
    }
    //ordering student Ids alphabetically (in ascending order)
    orders = new int[numStud-fails];
    lastId = studId[0];
    for(int i=0; i<numStud; ++i){
        if(count2[i] == 3){
            continue;
        }
        if(lastId <= studId[i]){
            lastId = studId[i];
            orders[numStud-fails-1] = i;
        }
    }
    for(int i=0; i<numStud; ++i){
        if(count2[i] == 3){
            continue;
        }
        orderId = lastId;
        for(int j=0; j<numStud; ++j){
            int count=0;
            for(int k=0; k<i; ++k){
                if(j == orders[k]){
                    count += 1;
                    break;
                }
            }
            if(count==1){
                continue;
            }
            if(orderId >= studId[j]){
                orderId = studId[j];
                orders[i] = j;
            }
        }
        
    }

    //displaying the upper borders and titles of the table
    cout<<endl<<"    ";
    for(int i=0; i<numCourse; ++i){
        cout<<"        ";
    }
    cout<<"STUDENT'S MArk SHEET"<<endl;

    cout<<"______________";
    for(int i=0; i<numCourse; ++i){
        cout<<"________________";
    }
    cout<<"______________________"<<endl;

    cout<<" Stud. ID       ";
    for(int i=0; i<numCourse; ++i){
        cout<<"    "<<subjectName[i]<<"        ";
    }
    cout<<"Average    CGPA"<<endl;

    cout<<"              ";
    for(int i=0; i<numCourse; ++i){
        cout<<"________________";
    }
    cout<<endl;

    cout<<"                ";
    for(int i=0; i<numCourse; ++i){
        cout<<"Mark : Grade    ";
    }
    cout<<endl;

    cout<<"______________";
    for(int i=0; i<numCourse; ++i){
        cout<<"________________";
    }
    cout<<"______________________"<<endl;

    //displaying each row of the table in ascending order of student Ids
    for(int i=0; i<numStud-fails; ++i){
        cout<<' '<<studId[orders[i]]<<"   ";
        for(int j=0; j<numCourse; ++j){
            if(gradeMark[orders[i]][j] == "NG"){
                cout<<"    "<<gradeMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
                continue;
            }
            cout<<"    "<<subjectMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
        }
        if(temp[orders[i]] == 0){
            cout<<"    --        --"<<endl<<endl;
            continue;
        }
        cout<<"    "<<avg[orders[i]]<<"        "<<cgpa[orders[i]]<<endl;
        if(i<numStud-1){
            cout<<endl;
        }
    }

    //displaying the lower borders of the table
    cout<<"______________";
    for(int i=0; i<numCourse; ++i){
        cout<<"________________";
    }
    cout<<"______________________"<<endl<<endl;
    delete []orders;
    
    int count3 = 0;
    do{
        cout<<"Menu\nEnter 'A' to search for the result of a specific student\nEnter 'B' to get the Top n results based on CGPA\nEnter 'C' to get the Top n results based on Average\nEnter 'D' to get the Top n results based on a specific subject\nEnter 'E' to End the program\nYour choice: ";
        cin>>menu;
        menu = toupper(menu);

        int error = 0;
        switch(menu){
            case 'A':
                cout<<"Enter the Id number: ";
                cin>>searchId;
                for(int i=0; i<numStud; ++i){
                    if(count2[i] == 3){
                        continue;
                    }
                    if(studId[i] == searchId){
                        cout<<endl<<"______________";
                        for(int i=0; i<numCourse; ++i){
                            cout<<"________________";
                        }
                        cout<<"______________________"<<endl;
                        cout<<" Stud. ID       ";
                        for(int i=0; i<numCourse; ++i){
                            cout<<"    "<<subjectName[i]<<"        ";
                        }
                        cout<<"Average    CGPA"<<endl;

                        cout<<"              ";
                        for(int i=0; i<numCourse; ++i){
                            cout<<"________________";
                        }
                        cout<<endl;

                        cout<<"                ";
                        for(int i=0; i<numCourse; ++i){
                            cout<<"Mark : Grade    ";
                        }
                        cout<<endl;

                        cout<<"______________";
                        for(int i=0; i<numCourse; ++i){
                            cout<<"________________";
                        }
                        cout<<"______________________"<<endl;

                        cout<<' '<<studId[i]<<"   ";
                        for(int j=0; j<numCourse; ++j){
                            if(gradeMark[i][j] == "NG"){
                                cout<<"    "<<gradeMark[i][j]<<" : "<<gradeMark[i][j]<<"     ";
                                continue;
                            }
                            cout<<"    "<<subjectMark[i][j]<<" : "<<gradeMark[i][j]<<"     ";
                        }
                        if(temp[i] == 0){
                            cout<<"    --        --"<<endl<<endl;
                        }
                        cout<<"    "<<avg[i]<<"        "<<cgpa[i]<<endl;
                        cout<<"______________";
                        for(int j=0; j<numCourse; ++j){
                            cout<<"________________";
                        }
                        cout<<"______________________"<<endl<<endl;
                        break;
                    }
                    else if(i == numStud - 1){
                        cout<<"\nThe ID could not be found.\n"<<endl;
                    }
                }
                break;

            case 'B':
                cout<<endl<<"Do you want the top n students or the top m\% students\nEnter '%' to get top students by percent and any other character for top n students: ";
                cin>>menu2;
                if(menu2=='%'){
                    cout<<"Enter the percentage(0-100): ";
                    cin>>percent;
                    if(percent<0 || percent>100){
                        cout<<"\nThe percentage is out of range\n"<<endl;
                        break;
                    }
                    n=percent*(numStud-fails)/100;  //changing percent to n
                }
                else{
                    cout<<"Enter the value of n: ";
                    cin>>n;
                    if(n<0 || n>numStud-fails){
                        cout<<"\nn is out of range (0-"<<numStud-fails<<")\n"<<endl;
                        break;
                    }
                }
                
                //finding top n students in descending order of CGPA
                orders = new int[n];
                minValue = cgpa[0];
                for(int i=0; i<numStud; ++i){
                    if(count2[i] == 3){
                        continue;
                    }
                    if(minValue >= cgpa[i]){
                        minValue = cgpa[i];
                        orders[n-1] = i;
                    }
                }
                for(int i=0; i<n; ++i){
                    order = minValue;
                    for(int j=0; j<numStud; ++j){
                        if(count2[j] == 3){
                            continue;
                        }
                        int count=0;
                        for(int k=0; k<i; ++k){
                            if(j == orders[k]){
                                count += 1;
                                break;
                            }
                        }
                        if(count==1){
                            continue;
                        }
                        if(order <= cgpa[j]){
                            order = cgpa[j];
                            orders[i] = j;
                        }
                    }
                    
                }

                //displaying upper borders and titles of the table
                cout<<" ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"        ";
                }
                if(menu2=='%'){
                    cout<<"Top "<<percent<<"\% based on CGPA result"<<endl;
                }
                else{
                    cout<<"Top "<<n<<" based on CGPA result"<<endl;
                }

                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl;

                cout<<" Stud. ID       ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"    "<<subjectName[i]<<"        ";
                }
                cout<<"Average    CGPA"<<endl;

                cout<<"              ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<endl;

                cout<<"                ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"Mark : Grade    ";
                }
                cout<<endl;

                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl;

                //displaying top n students in descending order of CGPA
                for(int i=0; i<n; ++i){
                    cout<<' '<<studId[orders[i]]<<"   ";
                    for(int j=0; j<numCourse; ++j){
                        if(gradeMark[orders[i]][j] == "NG"){
                            cout<<"    "<<gradeMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
                            continue;
                        }
                        cout<<"    "<<subjectMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
                    }
                    if(temp[orders[i]] == 0){
                        cout<<"    --        --"<<endl<<endl;
                        continue;
                    }
                    cout<<"    "<<avg[orders[i]]<<"        "<<cgpa[orders[i]]<<endl;
                    if(i<n-1){
                        cout<<endl;
                    }
                }

                //displaying the lower borders of the table
                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl<<endl;
                delete []orders;
               
                break;

            case 'C':
                cout<<endl<<"Do you want the top n students or the top m\% students\nEnter '%' to get top students by percent and any other character for top n students: ";
                cin>>menu2;
                if(menu2=='%'){
                    cout<<"Enter the percentage(0-100): ";
                    cin>>percent;
                    if(percent<0 || percent>100){
                        cout<<"\nThe percentage is out of range\n"<<endl;
                        break;
                    }
                    n=percent*(numStud-fails)/100;  //changing percent to n
                }
                else{
                    cout<<"Enter the value of n: ";
                    cin>>n;
                    if(n<0 || n>numStud-fails){
                        cout<<"\nn is out of range (0-"<<numStud-fails<<")\n"<<endl;
                        break;
                    }
                }

                //finding top n students in descending order of Average
                orders = new int[n];
                minValue = avg[0];
                for(int i=0; i<numStud; ++i){
                    if(count2[i] == 3){
                        continue;
                    }
                    if(minValue >= avg[i]){
                        minValue = avg[i];
                        orders[n-1] = i;
                    }
                }
                for(int i=0; i<n; ++i){
                    order = minValue;
                    for(int j=0; j<numStud; ++j){
                        if(count2[j] == 3){
                            continue;
                        }
                        int count=0;
                        for(int k=0; k<i; ++k){
                            if(j == orders[k]){
                                count += 1;
                                break;
                            }
                        }
                        if(count==1){
                            continue;
                        }
                        if(order <= avg[j]){
                            order = avg[j];
                            orders[i] = j;
                        }
                    }
                    
                }

                //displaying upper borders and titles of the table
                cout<<"   ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"        ";
                }
                if(menu2=='%'){
                    cout<<"Top "<<percent<<"\% based on Average"<<endl;
                }
                else{
                    cout<<"Top "<<n<<" based on Average"<<endl;
                }

                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl;

                cout<<" Stud. ID       ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"    "<<subjectName[i]<<"        ";
                }
                cout<<"Average    CGPA"<<endl;

                cout<<"              ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<endl;

                cout<<"                ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"Mark : Grade    ";
                }
                cout<<endl;

                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl;

                //displaying top n students in descending order of Average
                for(int i=0; i<n; ++i){
                    cout<<' '<<studId[orders[i]]<<"   ";
                    for(int j=0; j<numCourse; ++j){
                        if(gradeMark[orders[i]][j] == "NG"){
                            cout<<"    "<<gradeMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
                            continue;
                        }
                        cout<<"    "<<subjectMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
                    }
                    if(temp[orders[i]] == 0){
                        cout<<"    --        --"<<endl<<endl;
                        continue;
                    }
                    cout<<"    "<<avg[orders[i]]<<"        "<<cgpa[orders[i]]<<endl;
                    if(i<n-1){
                        cout<<endl;
                    }
                }

                //displaying the lower borders of the table
                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl<<endl;
                delete []orders;
               
                break;

            case 'D':
                cout<<"Enter the Subject name: ";
                cin>>searchSub;
                //storing the index of the course chosen
                for(int i=0; i<numCourse; ++i){
                    if(subjectName[i] == searchSub){
                        subIndex = i;
                        break;
                    }
                    else if(i==numCourse-1){
                        error += 1;
                    }
                }
                if(error!=0){
                    cout<<"\nInvalid course name.\n"<<endl;
                    break;
                }
                cout<<endl<<"Do you want the top n students or the top m\% students\nEnter '%' to get top students by percent and any other character for top n students: ";
                cin>>menu2;
                if(menu2=='%'){
                    cout<<"Enter the percentage(0-100): ";
                    cin>>percent;
                    if(percent<0 || percent>100){
                        cout<<"\nThe percentage is out of range\n"<<endl;
                        break;
                    }
                    n=percent*(numStud-fails)/100;  //changing percent to n
                }
                else{
                    cout<<"Enter the value of n: ";
                    cin>>n;
                    if(n<0 || n>numStud-fails){
                        cout<<"\nn is out of range (0-"<<numStud-fails<<")\n"<<endl;
                        break;
                    }
                }
                //finding top n students in descending order of the chosen course
                orders = new int[n];
                minValue = subjectMark[0][subIndex];
                for(int i=0; i<numStud; ++i){
                    if(count2[i] == 3){
                        continue;
                    }
                    if(minValue >= subjectMark[i][subIndex]){
                        minValue = subjectMark[i][subIndex];
                        orders[n-1] = i;
                    }
                }
                for(int i=0; i<n; ++i){
                    order = minValue;
                    for(int j=0; j<numStud; ++j){
                        if(count2[j] == 3){
                            continue;
                        }
                        int count=0;
                        for(int k=0; k<i; ++k){
                            if(j == orders[k]){
                                count += 1;
                                break;
                            }
                        }
                        if(count==1){
                            continue;
                        }
                        if(order <= subjectMark[j][subIndex]){
                            order = subjectMark[j][subIndex];
                            orders[i] = j;
                        }
                    }
                    
                }

                //displaying upper borders and titles of the table
                cout<<endl<<" ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"        ";
                }
                if(menu2=='%'){
                    cout<<"Top "<<percent<<"\% based on "<<subjectName[subIndex]<<" result"<<endl;
                }
                else{
                    cout<<"Top "<<n<<" based on "<<subjectName[subIndex]<<" result"<<endl;
                }

                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl;

                cout<<" Stud. ID       ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"    "<<subjectName[i]<<"        ";
                }
                cout<<"Average    CGPA"<<endl;

                cout<<"              ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<endl;

                cout<<"                ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"Mark : Grade    ";
                }
                cout<<endl;

                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl;

                //displaying top n students in descending order of the chosen course
                for(int i=0; i<n; ++i){
                    cout<<' '<<studId[orders[i]]<<"   ";
                    for(int j=0; j<numCourse; ++j){
                        if(gradeMark[orders[i]][j] == "NG"){
                            cout<<"    "<<gradeMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
                            continue;
                        }
                        cout<<"    "<<subjectMark[orders[i]][j]<<" : "<<gradeMark[orders[i]][j]<<"     ";
                    }
                    if(temp[orders[i]] == 0){
                        cout<<"    --        --"<<endl<<endl;
                        continue;
                    }
                    cout<<"    "<<avg[orders[i]]<<"        "<<cgpa[orders[i]]<<endl;
                    if(i<n-1){
                        cout<<endl;
                    }
                }

                //displaying the lower borders of the table
                cout<<"______________";
                for(int i=0; i<numCourse; ++i){
                    cout<<"________________";
                }
                cout<<"______________________"<<endl<<endl;
                delete []orders;
               
                break;

            case 'E':
            cout<<"\nThank you for using this program!!";
                count3 = 3;
                break;

            default:
                cout<<"\nYou entered wrong input.\n"<<endl;
                count3 += 1;
                break;
        }
    }while(count3<3);
    
    return 0;
}

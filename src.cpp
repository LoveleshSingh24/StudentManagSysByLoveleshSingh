#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Student{
    int roll_no;
    char name[50];
    char gender;
    int age;
    int std;
    float fee;
    void calFee(){
        if(age>15){
            fee=15000;
        }else{
            fee=10000;
        }
    }

    public:
    Student(){

    }
    char* getName(){
        return name;
    }
    int getRoll(){
        return roll_no;
    }
    void modifyData(){
        cout<<"\n\n\tENTER DETAILS TO MODIFIED DATAn\n\n";
        cout<<"roll No. of data  : "<<roll_no;
        cout<<endl<<endl;
        cout<<"Enter new name    : ";
        cin.ignore();
        cin.getline(name,50);
        cout<<endl;
        cout<<"Enter new gender  : ";
        cin>>gender;
        cout<<endl;
        cout<<"Enter new age     : ";
        cin>>age;
        cout<<endl;
        cout<<"Enter new std     : ";
        cin>>std;
        cout<<endl;
    }
    void getData(){
        cout<<endl<<endl;
        cout<<"\n\n\tENTER THE DETAILS OF THE STUDENT\n\n"<<endl;
        cout<<"Enter the name   : ";
        cin.ignore();
        cin.getline(name,50);
        cout<<endl;
        cout<<"Enter the roll   : ";
        cin>>roll_no;
        cout<<endl;
        cout<<"Enter the gender : ";
        cin>>gender;
        cout<<endl;
        cout<<"Enter age        : ";
        cin>>age;
        cout<<endl;
        cout<<"Enter std        : ";
        cin>>std;
        calFee();
    }
   
   
    void showData(){
        cout<<"\n\n\tSUTUDENT DATA\n\n";
        cout<<"Roll No : "<<roll_no<<endl;
        cout<<"Name    : "<<name<<endl;
        cout<<"Gender  : "<<gender<<endl;
        cout<<"Age     : "<<age<<endl;
        cout<<"std     : "<<std<<"th"<<endl;
        cout<<"Fee     : "<<fee<<endl;
        cout<<endl;
    } 
   
    
    void listData(){
        cout.setf(ios::left);//used to set text field
        cout<<endl;
        cout<<setw(10)<<roll_no;
        cout<<setw(20)<<name;
        cout<<setw(10)<<gender;
        cout<<setw(5)<<age;
        cout<<setw(15)<<std;
        cout<<setw(15)<<fee;
        
    }
};
void heading(){    
    cout.setf(ios::left);//used to set text field
    cout<<"\n\nTOTAL NO. OF STUDENT DATA\n\n";
    cout<<setw(10)<<"Roll No";
    cout<<setw(20)<<"Name";
    cout<<setw(10)<<"Gender";
    cout<<setw(5)<<"Age";
    cout<<setw(15)<<"Standard";
    cout<<setw(15)<<"Fee";
    }
void menu(){
    cout<<"\n\n\tSTUDNET MANAGEMENT SYSTEM\n\n ";
    cout<<"========================\n";
    cout<<"0.Exit\n";
    cout<<"1.Registration New Student\n";
    cout<<"2.Show All Student \n";
    cout<<"3.Search by Roll no \n";
    cout<<"4.Search by name  \n";
    cout<<"5.Modify Data\n";
    cout<<"6.Delete Data\n\n";
    cout<<"ENTER YOU CHOICE : ";

}

int main(){
    int k;
    cout<<"ENTER THE TOTAL NUMBER OF STUDENT : ";
    cin>>k;
    int n=0,ch,rn,i,pos;
    int flag=0;
    int *arr{new int[n]};
    Student *s=new Student[k];
    do{
        std::system("cls");
        menu();
        cin>>ch;
        switch (ch)
        {
        case 1:s[n].getData();n++;
            cout<<"\n\nRECORD SAVED SUCCESFULLY \n\n";
            break;
        case 2:
            if(n>0){
                heading();
                for(i=0;i<n;i++){
                    s[i].listData();
                    
                }
                cout<<endl;
            }
            else{
                cout<<endl;
                cout<<"\n\nNOTHING TO DISPLAY !!\n\n"<<endl;
            }
            break;
        case 3:
            flag=0;
            if(n>0){
                cout<<"\n\nEnter the roll No. to display : ";
                cin>>rn;
                for(i=0;i<n;i++){
                    if(rn==s[i].getRoll()){
                        s[i].showData();
                        flag++;        
                    }
                }
            }  
            else{
                cout<<"\n\nNOTHING TO DISPLAY !!\n\n";
            }
            if(flag==0){
                cout<<" \n\nNO SUCH ROLL NO. EXIST...\n\n";
            }
            break;
        case 4:
            flag=0;
            if(n>0){
                char nm[20];
                cout<<"\n\nEnter the Name to Search : ";
                cin.ignore();
                cin.getline(nm,20);
                for(i=0;i<n;i++){
                    if(strcmpi(nm,s[i].getName())==0){
                        //i signify irrespective of lower case and upper case
                        s[i].showData();
                        flag++;
                    }
                }
            }
            else{
                cout<<"\n\nNOTHING TO DISPLAY !!\n\n";
            }
            if(flag==0){
                cout<<"\n\nNO SUCH NAME EXIST...\n\n";
            }
            break;
        case 5:
            flag=0;
            if(n>0){
                int pos;
                cout<<"Enter Roll no to modify  : ";
                cin>>rn;
                for(i=0;i<n;i++){
                    if(rn==s[i].getRoll()){
                        cout<<"\nData givien below will be modified\n"<<endl;
                        s[i].showData();
                        s[i].modifyData();
                        cout<<endl;
                        cout<<"Data is modified!!"<<endl;
                        flag++;       
                    }
                }
            }else{
                cout<<"\n\nNOTHING TO DISPLAY !!\n\n";
            }
            if(flag==0){
                cout<<"\n\nNO SUCH ROLL NO. EXIST...\n\n";
            }
            break;
        case 6:
            flag=0;
            if(n>0){
                cout<<"Enter the roll No. to display : ";
                cin>>rn;
                for(i=0;i<n;i++){
                    if(rn==s[i].getRoll()){
                        cout<<"\n\nFIOLLOWING RECORD WILL BE DELETED...\n\n"<<endl;
                        s[i].showData();
                        flag++;
                        pos=i;
                        break;       
                    }
                }
                if(pos==i){
                    cout<<"\n\nTHE RECORD IS DELETED !!\n\n"<<endl;
                }
                for(i=pos;i<n-1;i++){//staring index is zer0
                    s[i]=s[i+1];

                }
                n--;
            }  
            else{
                cout<<" \n\nNOTHING TO DISPLAY !!\n\n   ";
            }
            if(flag==0){
                cout<<" \n\nNO SUCH ROLL NUMBER EXIST...\n\n";
            }
            break;
        case 0:
            cout<<"\n\nTHANKYOU FOR USING STUDENT MAGEMENT SYSTEM BY LOVELESH\n\n";
            exit(1);
        default:
            break;
        }
        std::system("pause"); 
    }while(ch!=0);

    return 0;
}
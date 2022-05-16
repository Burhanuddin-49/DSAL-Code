#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
class employee
{
 int admno;
 char name[50];
 char addr[50];
public:
 void setData()
 {
 cout << "\nEnter Employee ID :  "; 
 cin >> admno;
 cout << "Enter name : ";
 cin>>name;
 cout<<"Enter the Designation of the Employee : ";
 cin>>addr;
 }
 void showData()
 {
 cout << "\n*Employee ID : " << admno;
 cout << "\n*Employee Name : " << name;
 cout<<"\n*Designation : "<<addr;
 }
 int retAdmno()
 {
 return admno;
 }
};
void write_record()
{
 ofstream outFile;
 outFile.open("employee.dat", ios::binary | ios::app); 
 employee obj;
 obj.setData();
 outFile.write((char*)&obj, sizeof(obj));
 outFile.close();
}
void display()
{
 ifstream inFile;
 inFile.open("employee.dat", ios::binary);
 employee obj;
 while(inFile.read((char*)&obj, sizeof(obj)))
 {
 obj.showData();
 }
 inFile.close();
}
void search(int n)
{
 ifstream inFile;
 inFile.open("employee.dat", ios::binary); 
 employee obj;
 while(inFile.read((char*)&obj, sizeof(obj)))
 {
 if(obj.retAdmno() == n)
 {
 obj.showData();
 break;
 }
 }
 inFile.close();
}
void delete_record(int n)
{
 employee obj;
 ifstream inFile;
 inFile.open("employee.dat", ios::binary);
 ofstream outFile;
 outFile.open("temp.dat", ios::out | ios::binary);
 while(inFile.read((char*)&obj, sizeof(obj)))
 {
 if(obj.retAdmno() != n)
 {
 outFile.write((char*)&obj, sizeof(obj)); 
 }
 }
 inFile.close();
 outFile.close();
 remove("employee.dat");
 rename("temp.dat", "employee.dat");
}
void modify_record(int n)
{
 fstream file;
 file.open("employee.dat",ios::in | ios::out);
 employee obj;
 while(file.read((char*)&obj, sizeof(obj)))
 {
 if(obj.retAdmno() == n)
 {
 cout << "\nEnter the new details of Employee";
 obj.setData();
 int pos = -1 * sizeof(obj);
 file.seekp(pos, ios::cur);
 file.write((char*)&obj, sizeof(obj)); 
 }
 }
 file.close();
}
int main()
{
 int ch;
 do{
 cout<<"\n\n\n********File operations*********\n1.write\n2.display\n3.search\n4.delete\n5.modify";
 cout<<"\nEnter your choice : ";
 cin>>ch;
 switch(ch){
 case 1: cout<<"Enter number of records : ";
 int n;
 cin>>n;
 for(int i = 0; i <n; i++)
 write_record();
 break;
 case 2:
 cout << "\nList of records : ";
 display();
 break; 
 case 3:
 cout<<"Enter Employee ID : ";
 int s;
 cin>>s;
 search(s);
 break;
 case 4:
 cout<<"Enter number to be deleted : ";
 int d;
 cin>>d;
 delete_record(d);
 cout << "\nRecord Deleted";
 break;
 case 5:
 cout<<"Enter number to be modified : ";
 int m;
 cin>>m;
 modify_record(m);
 break;
 case 6: 
 return 0;
 }
}while(ch!=6);
}

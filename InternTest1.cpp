#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>
using namespace std;

    class ContactList{
    private:
    char name[50];
    long number;
    public:
    ContactList(){
    strcpy(name, "NULL");
    number=0;
    }
    void newEntry(){
        cout<<"\nEnter Contact Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout<<"Enter Your Phone Number: ";
        cin>>number;
        }
    void viewEntry(){
        cout<<name<<" | "<<number<<endl;
        }
            int storeEntry();
            void deleteEntry(char*);
            void viewEntry();
            void searchEntry(char *);
            void updateEntry(char *);
            };


int ContactList::storeEntry(){

    if(number==0 && name=="NULL"){
    cout<<"\nFailed to insert";
    return(0); 
    }
    else{
    ofstream fout;
    fout.open("account.txt", ios::app|ios::binary);
    fout.write((char*)this, sizeof(*this));
    fout.close();
    return(1); 
    }
    }
    void ContactList::deleteEntry(char *t)
    {
    ifstream fin;

    ofstream fout;
    
    fin.open("account.txt",ios::in | ios::binary);
    if(!fin)
    cout<<"File Not Found";
    else{
    fout.open("tempfile.txt",ios::out | ios::binary);
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
    if(strcmp(name,t))
    fout.write((char*)this,sizeof(*this));
    fin.read((char *)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    remove("account.txt");
    rename("file.txt","account.txt");
    }
    }
    void ContactList::viewEntry(){

    ifstream fin;
    fin.open("account.txt", ios::in|ios::binary);
    if(!fin){
    cout<<"File Not Found!!!";
    }
    else{
    fin.read((char*)this, sizeof(*this));
    while (!fin.eof()){ 
    viewEntry();
    fin.read((char*)this, sizeof(*this));
    }
    fin.close();
    }
    }
    void ContactList::searchEntry(char *t)

    {
    int counter=0;
    ifstream fin;
    fin.open("account.txt",ios::in|ios::binary);
    if(!fin)
    cout<<"\nFile Not Found";
    else{
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
    if(!strcmp(t, name))
    {
    viewEntry();
    counter++;
    }
    fin.read((char*)this,sizeof(*this));
    }
    if(counter==0)
    cout<<"\nRecord Not found";
    }
    fin.close();
    }

    void ContactList::updateEntry(char *t){

    fstream file;
    file.open("account.txt", ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0); 
    file.read((char*)this, sizeof(*this));
    while (!file.eof())
    {
    if(!strcmp(t, name)){ 
    newEntry();
    file.seekp(file.tellp()-sizeof(*this)); 
    file.write((char*)this, sizeof(*this));
    }
    file.read((char*)this, sizeof(*this));
    }
    }
        int menu(){

        int choice;
        cout<<"\n\n****ContactList Manager****\n\n";
        cout<<"1. New Entry\n";
        cout<<"2. Delete Entry\n";
        cout<<"3. View All Entries\n";
        cout<<"4. Search Entry\n";
        cout<<"5. Update Entry\n";
        cout<<"6. Exit\n";
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        return(choice);
        }
            int main(){
            ContactList p1;
            char name[50];
            while (1)
            {
            switch (menu())
            {
            case 1:{
            p1.newEntry();
            p1.storeEntry();
            cout<<"\nNew Entry Done";
            break;
            }
            case 2:{
            cout<<"\nEnter the name you want to delete: ";
            cin.ignore();
            cin.getline(name, 50);
            p1.deleteEntry(name);
            cout<<"\nEntry Deleted";
            break;
            }
            case 3:{
            p1.viewEntry();
            break;
            }
            case 4:{
            cout<<"\nEnter the name you want to Search: ";
            cin.ignore();
            cin.getline(name, 50);
            p1.searchEntry(name);
            break;
            }
            case 5:{
            cout<<"\nEnter the name you want to Update: ";
            cin.ignore();
            cin.getline(name, 50);
            p1.updateEntry(name);
            cout<<"\nUpdated Successfully";
            break;
            }
            case 6:
            cout<<"\nPress any key to exit";
            getch();
            exit(0);
            break;
            default:
            cout<<"\nInvalid Operation";
            break;
            }
            getch();
            }
            }

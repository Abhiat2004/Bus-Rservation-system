#include <iostream>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
using namespace std;
int i=0,b=0;
class Database
{
    public:
    string name,age,email,mobileno,username,pass,cpass;
    string bname,bnum,bs,be,bt;
    int bamount,seats;
    string pname[10],page[10],pmob[10],pgender[10];
    int tseats,ntickets=0,nbus;

};

class Account:public Database
{
    public:
    void createAcc()
    {
        cout<<"Enter your Name : ";
        cin>>name;
        cout<<"Enter your Age  : ";
        cin>>age;
        cout<<"Enter your E-mail : ";
        cin>>email;
        cout<<"Enter your Mobile number : ";
        cin>>mobileno;
        cout<<"Create your Username : ";
        cin>>username;
        loop:
        cout<<"Create your Password : ";
        cin>>pass;
        cout<<"Confirm your Password : ";
        cin>>cpass;
        if(pass==cpass)
            cout<<"...Account Created...";
        else
            goto loop;
            i++;
    }
}A[100];

class Install:public Database
{
    public:
    void bdis()
    {
                cout<<"Bus Name : "<<bname<<endl;
                cout<<"Bus Number : "<<bnum<<endl;
                cout<<"Bus Starting Point : "<<bs<<endl;
                cout<<"Bus Ending Point : "<<be<<endl;
                cout<<"Bus Timing at Starting Position : "<<bt<<endl;
                cout<<"Number of seats Available in Bus : "<<seats<<endl;
                cout<<"Cost of each Seat : "<<bamount<<endl<<endl<<endl;

    }

    void install()
    {
        cout<<"Bus Name : ";
        cin>>bname;
        cout<<"Bus Number : ";
        cin>>bnum;
        cout<<"Bus Starting Point : ";
        cin>>bs;
        cout<<"Bus Ending Point : ";
        cin>>be;
        cout<<"Bus Timing at Starting Position : ";
        cin>>bt;
        cout<<"Total number of seats in Bus : ";
        cin>>seats;
        cout<<"Cost of each Seat : ";
        cin>>bamount;
        b++;
    }

}I[100];

class Booking: public Database
{
    public:
        int k;
    void booking()
    {
        for(int c=1,k=0;k<b;k++,c++)
                        {
                         cout<<c<<endl;
                         I[k].bdis();
                         cout<<endl<<endl;
                        }
        cout<<"Select a Bus : ";
        cin>>nbus;
        cout<<"Enter number of Passengers : ";
        cin>>tseats;
        for(k=0;k<tseats;k++)
        {
            cout<<"Enter Name of Passenger "<<k+1<<" : ";
            cin>>pname[k];
            cout<<"Enter Age of  "<<pname[k]<<" : ";
            cin>>page[k];
            cout<<"Enter Gender of  "<<pname[k]<<" : ";
            cin>>pgender[k];
            cout<<"Enter Mobile number of  "<<pname[k]<<" : ";
            cin>>pmob[k];
            cout<<endl<<endl;
        }
        I[nbus-1].seats=I[nbus-1].seats-tseats;
        cout<<".....Ticket is booked....."<<endl;
    }
}B[100];

class Ticket:public Database
{
    public:
    void showticket(int m,int s)
    {
        int n;
        cout<<"Bus Name : "<<I[m].bname<<endl;
        cout<<"Bus Number : "<<I[m].bnum<<endl;
        cout<<"Bus Starting Point : "<<I[m].bs<<endl;
        cout<<"Bus Ending Point : "<<I[m].be<<endl;
        cout<<"Bus Timing at Starting Position : "<<I[m].bt<<endl;
        cout<<"No of seats booked : "<<B[m].tseats<<endl;
        cout<<"Total Amount : "<<I[m].bamount*B[m].tseats<<endl<<endl;
        cout<<"Details of Passengers :"<<endl;
        for(n=0;n<B[m].k;n++)
        {
            cout<<"Name of the Passenger "<<n+1<<" : "<<B[m].pname[n]<<endl;
            cout<<"Age of "<<B[m].pname[n]<<" : "<<B[m].age[n]<<endl;
            cout<<"Gender of "<<B[m].pname[n]<<" : "<<B[m].pgender[n]<<endl;
            cout<<"Mobile number of "<<B[m].pname[n]<<" : "<<B[m].pmob[n]<<endl<<endl;
        }
    }
}T;

int main()
{
    int ch,k;
    string aname,apass;
    mloop:
    cout<<"Welcome to SRM BUS Portal"<<endl;
    cout<<"1. Admin Portal"<<endl<<"2. User Portal"<<endl<<"3. Exit"<<endl<<"Enter Your Choice : ";
    cin>>ch;
    system("cls");
    if(ch==1)
    {
        loop:
        cout<<"Enter Admin Username : ";
        cin>>aname;
        if(aname=="srmadmin")
        {
            loop1:
            cout<<"Enter Admin Password : ";
            cin>>apass;
            if(apass=="Admin22")
            {
                cout<<"Welcome to Admin Portal"<<endl;
                aloop:
                cout<<"1. Display "<<endl<<"2. Install"<<endl<<"3. Logout"<<endl<<"Enter your choice : ";
                cin>>ch;
                system("cls");
                if(ch==1)
                    {
                        if(b==0){
                            cout<<"No Busses are Installed!"<<endl;delay(1000);}
                        else{
                        for(int j=0;j<b;j++)
                            I[j].bdis();}
                        goto aloop;
                    }
                if(ch==2)
                {
                    I[b].install();
                    goto aloop;
                }
                if(ch==3)
                    goto mloop;
            }
                else{
                    cout<<"Invalid Password"<<endl;goto loop1;}

        }
        else{
            cout<<"Invalid Username"<<endl;
            goto loop;}

    }
    if(ch==2)
    {
        cout<<"1. Login"<<endl<<"2. Sign Up"<<endl<<"Enter your Choice : ";
        cin>>ch;
        if(ch==1)
        {
            lloop:
            cout<<"Enter Username : ";
            cin>>aname;
            for(int j=0;j<i;j++)
            {
                if(A[j].username==aname)
                {
                     ploop:
                cout<<"Enter Password : ";
                cin>>apass;
                if(apass==A[j].pass){
                    cout<<endl<<"Welcome "<<A[j].name<<endl;
                    tloop:
                    cout<<"1. Book Tickets"<<endl<<"2. Show my Ticket"<<endl<<"3. Display Buses"<<endl<<"4. Logout"<<endl<<"Enter your Choice : ";
                    cin>>ch;
                    if(ch==1)
                    {
                        if(B[j].ntickets==0){
                        B[j].booking();B[j].ntickets++;}
                        else
                            cout<<"...Max Limit is Exceeded..";
                        goto tloop;
                    }
                    if(ch==2)
                    {
                        if(B[j].ntickets==0){cout<<"No Tickets are Booked"<<endl;goto tloop;}
                        else{
                            T.showticket(j,B[j].nbus);
                            goto tloop;}
                    }
                    if(ch==3)
                    {
                        for(k=0;k<b;k++)
                        {
                         I[k].bdis();
                         cout<<endl<<endl;
                        }
                        goto tloop;
                    }
                    if(ch==4)
                    {
                        goto mloop;
                    }
                    }
                    else
                    {
                        cout<<"Invalid Password"<<endl;
                        goto ploop;
                    }
                    k=1;
                    break;
                }
                }
                if(k!=1){
                    cout<<"NO Account found!";
                    goto lloop;}

            }


        if(ch==2)
        {
            A[i].createAcc();
            cout<<endl;
            goto mloop;
        }

    }
    if(ch==3)
    return 0;
}

#include <iostream>
#include <fstream>

//Contains info about all the cars
class car {
  protected: 
    char place[30];
    struct model {
        char name[25];  
        float age;
        char color[10];
        double price;
    };
    char uname[30];
    char A[10];
  public:
    void reddet();
    void bill(int);
    void bill(model);
    car() {
        struct model S[10];
    }
    ~car() {
        cout<<"Thank you...!!!"<<endl<<"Visit again"<<endl;
    }
};

//Object is declared for customer option
class customer :: public car {
  public:
    void cpanel();
    void bill(int);
};

//Object is declared for dealer option
class dealer :: public car {
  public:
    void dpanel();
};

void car::bill(int op) {
    for (int i=0;i<40;i++)
        cout<<"-";
    cout<<endl<<endl;
    cout<<uname<<endl;
    cout<<op+1<<" "<<S[op].name<<" "<<S[op].color<<" "<<S[op].price<<endl;
    cout<<"Total Price = "<<S[op].price*(1.07)<<endl;

}

void car::bill(model C) {
    for (int i=0;i<40;i++)
        cout<<"-";
    cout<<endl<<endl;
    cout<<uname<<endl;
    cout<<C.name<<" "<<C.age<<" "<<C.color<<" "<<C.price<<endl;

}

void customer::cpanel() {
    ifstream in;
    in.open(A);
    int n,op;
    in>>n;
    for (int i=0;i<n;i++)
        in>>S[i].name>>S[i].age>>S[i].color>>S[i].price;
    cout<<"Select a car of your desire"<<endl;
    for (int i=0;i<n;i++)
        cout<<i+1<<" "<<S[i].name<<" "<<S[i].age<<" years "<<S[i].color<<" "<<S[i].price<<endl;
    cin>>op;
    bill(op-1);
    in.close();
    ofstream out(A);
    out<<n-1<<endl;
    for (int i=0;i<n;i++){
        if (i!=op-1)
        out<<S[i].name<<" "<<S[i].age<<" "<<S[i].color<<" "<<S[i].price<<endl;
    }
    out.close();
}

void dealer::dpanel() {
    ifstream in;
    in.open(A);
    int n;
    model C;
    in>>n;
    for (int i=0;i<n;i++)
        in>>S[i].name>>S[i].age>>S[i].color>>S[i].price;
    in.close();
    cout<<"Enter your car details"<<endl;
    in>>C.name>>C.age>>C.color>>C.price;
    bill(C);
    ofstream out(A);
    out<<n+1<<endl;
    for (int i=0;i<n;i++){
        out<<S[i].name<<" "<<S[i].age<<" "<<S[i].color<<" "<<S[i].price<<endl;
    }
    out<<C.name<<" "<<C.age<<" "<<C.color<<" "<<C.price<<endl;
    out.close();

}

void car::reddet() {
    cout<<"Enter your name -";
    cin>>uname;
    cout<<"Select your current location "<<endl;
	cout<<"1:Kukatpally"<<endl;
	cout<<"2:Madhapur"<<endl;
	cout<<"3:Nagole"<<endl;
	cout<<"4:Secunderabad"<<endl;
	cout<<"5:Kompally"<<endl;
	cin>>place;
	switch (place) {
		case 1 :
		case 5 :A="KPHB.txt";
		case 3 :
		case 4 :A="Secunderabad.txt";
		case 2 :A="Tarnaka.txt";
	}
}

int main() {
    do {
        cout<<"Enter your requirement"<<endl;
        cout<<"1:Customer"<<endl;
        cout<<"2:Dealer"<<endl;
        cin>>req;
        switch (req){
            case 1 :customer C;
                    C.redet();
                    C.cpanel();
                    break;
            case 2 :dealer D;
                    D.reddet();
                    D.dpanel();
                    break;
        }
        cout<<"Do you want to exit (Y/N) ";
        char op;
        cin>>op;
    } while(op!=3);
    return 0;
}
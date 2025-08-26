#include <iostream>
#include <string>
using namespace std;

struct V { string reg, owner; bool occ; } lot[10];

int main() {
    for(int i=0;i<10;i++) lot[i].occ = false;
    int o;
    do {
        cout << "\n1.Park 2.Remove 3.Display 4.Exit\nOption: ";
        cin >> o;
        if(o==1) {
            int s=-1;
            for(int i=0;i<10;i++) if(!lot[i].occ) { s=i; break; }
            if(s==-1) { cout << "Full\n"; continue; }
            cout << "Reg: "; cin >> lot[s].reg;
            cout << "Owner: "; cin.ignore(); getline(cin, lot[s].owner);
            lot[s].occ=true;
            cout << "Parked at slot " << s+1 << '\n';
        } else if(o==2) {
            int t; string r;
            cout << "1.Slot 2.Reg\nChoose: "; cin >> t;
            if(t==1) {
                int s; cout << "Slot#: "; cin >> s;
                if(s<1||s>10||!lot[s-1].occ) cout<<"Invalid\n";
                else { lot[s-1].occ=false; cout<<"Removed\n"; }
            } else if(t==2) {
                cout<<"Reg: "; cin>>r;
                bool f=false;
                for(int i=0;i<10;i++)
                    if(lot[i].occ && lot[i].reg==r) { lot[i].occ=false; cout<<"Removed from "<<i+1<<'\n'; f=1; }
                if(!f) cout<<"Not found\n";
            }
        } else if(o==3) {
            for(int i=0;i<10;i++)
                cout << "Slot " << i+1 << ": " <<
                (lot[i].occ ? ("Occupied, Reg:"+lot[i].reg+", Owner:"+lot[i].owner) : "Empty") << '\n';
        } else if(o!=4) cout << "Invalid\n";
    } while(o!=4);
}

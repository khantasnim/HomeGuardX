#include <bits/stdc++.h>
using namespace std;

struct alert {
    string name;
    int score;
    string tips;
};

int yesNo()
{
    char c;
    cin >> c;
    if(c=='Y' || c=='y') return 1;
    return 0;
}

void mergeAlerts(vector<alert>& arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<alert> L(n1), R(n2);

    for(int i=0;i<n1;i++)
        L[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        R[i] = arr[mid+1+i];

    int i=0, j=0, k=l;
     while(i<n1 && j<n2)
     {
        if(L[i].score > R[j].score)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(vector<alert>& arr, int l, int r)
{
    if(l>=r) return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    mergeAlerts(arr, l, mid, r);
}

int calcRisk(string type)
{
    int score = 0;

    cout << "\n-- Checking " << type << " Alert --\n";

    if(type=="Gas Leak Alert"){
        cout<<"Gas smell? (Y/N): "; if(yesNo()) score+=30;
        cout<<"Hissing sound? (Y/N): "; if(yesNo()) score+=25;
        cout<<"Fire color abnormal? (Y/N): "; if(yesNo()) score+=20;
    }

    if(type=="Electrical Alert"){
        cout<<"Burning smell? (Y/N): "; if(yesNo()) score+=30;
        cout<<"Sparks? (Y/N): "; if(yesNo()) score+=30;
        cout<<"Voltage drop? (Y/N): "; if(yesNo()) score+=20;
    }

    if(type=="Fire Alert"){
        cout<<"Smoke? (Y/N): "; if(yesNo()) score+=40;
        cout<<"High heat? (Y/N): "; if(yesNo()) score+=25;
        cout<<"Burning smell? (Y/N): "; if(yesNo()) score+=20;
    }

    if(type=="Structural Alert"){
        cout<<"Cracks seen? (Y/N): "; if(yesNo()) score+=25;
        cout<<"Ceiling vibration? (Y/N): "; if(yesNo()) score+=20;
        cout<<"Door jammed? (Y/N): "; if(yesNo()) score+=15;
    }

    if(type=="Earthquake Alert"){
        cout<<"Shaking felt? (Y/N): "; if(yesNo()) score+=40;
        cout<<"Items falling? (Y/N): "; if(yesNo()) score+=30;
        cout<<"Crack noise? (Y/N): "; if(yesNo()) score+=20;
    }

    if(type=="Flood Alert"){
        cout<<"Water rising? (Y/N): "; if(yesNo()) score+=35;
        cout<<"Drainage blocked? (Y/N): "; if(yesNo()) score+=20;
        cout<<"Heavy rain 3+ hrs? (Y/N): "; if(yesNo()) score+=25;
    }

    if(type=="Cyclone Alert"){
        cout<<"Heavy wind? (Y/N): "; if(yesNo()) score+=30;
        cout<<"Low pressure? (Y/N): "; if(yesNo()) score+=30;
        cout<<"Dark clouds? (Y/N): "; if(yesNo()) score+=20;
    }

    if(type=="Storm Alert"){
        cout<<"Thunder? (Y/N): "; if(yesNo()) score+=25;
        cout<<"Lightning? (Y/N): "; if(yesNo()) score+=20;
        cout<<"Strong wind? (Y/N): "; if(yesNo()) score+=20;
    }

    return score;
}

string getTips(string type, int s)
{
    if(type=="Gas Leak Alert"){
        if(s>=60) return "Danger! Turn off gas, open windows, evacuate.";
        if(s>=30) return "Ventilate area and check regulator.";
        return "Monitor smell.";
    }

    if(type=="Electrical Alert"){
        if(s>=60) return "Turn off main switch immediately!";
        if(s>=30) return "Avoid using devices.";
        return "Minor, but inspect soon.";
    }

    if(type=="Fire Alert"){
        if(s>=60) return "Evacuate and call fire service immediately.";
        if(s>=30) return "Remove flammable items.";
        return "Low fire risk.";
    }

    if(type=="Structural Alert"){
        if(s>=60) return "Danger! Leave the building.";
        if(s>=30) return "Repair needed soon.";
        return "Minor cracks.";
    }

    if(type=="Earthquake Alert"){
        if(s>=60) return "DROP–COVER–HOLD immediately.";
        if(s>=30) return "Move away from heavy objects.";
        return "Stay alert.";
    }

    if(type=="Flood Alert"){
        if(s>=60) return "Move to higher ground now!";
        if(s>=30) return "Protect documents and store dry food.";
        return "Monitor water level.";
    }

    if(type=="Cyclone Alert"){
        if(s>=60) return "Go to cyclone shelter immediately!";
        if(s>=30) return "Secure windows.";
        return "Stay updated.";
    }

    if(type=="Storm Alert"){
        if(s>=60) return "Stay indoors and unplug electronics.";
        if(s>=30) return "Avoid open areas.";
        return "Mild storm.";
    }

    return "No tips found.";
}

void showChecklist()
{
    cout<<"\n  CHECKLIST  \n";
    cout<<"• Gas stove locked\n";
    cout<<"• Electrical wiring safe\n";
    cout<<"• Fire extinguisher available\n";
    cout<<"• First aid kit\n";
    cout<<"• Torch + batteries\n";
    cout<<"• Dry food and water\n";
    cout<<"• Phone fully charged\n";
    cout<<"• Documents in waterproof bag\n";
}

void needHelp()
{
    cout<<"\n   NEED HELP?  \n";
    cout<<"• Move to safe area\n";
    cout<<"• Stay calm\n";
    cout<<"• Call family\n";
    cout<<"• Contact emergency services\n";
}

void showContacts()
{
    cout<<"\n*** EMERGENCY CONTACTS ***\n";
    cout<<"999  - Police / Fire / Ambulance\n";
    cout<<"102  - Fire Service\n";
    cout<<"16263 - Health Care\n";
    cout<<"109  - Emergency Help\n";
    cout<<"1616 - Cyclone Relief\n";
    cout<<"158  - Flood Control\n";
}

int main()
{
    vector<alert> record;
    int ch;

    while(true)
    {
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-\n";
        cout<<"  HomeGaurdX \n";
        cout<<"-*-*-*-*-*-*-*-*-*-*-\n";
        cout<<"1. Gas Leak Alert\n";
        cout<<"2. Electrical Alert\n";
        cout<<"3. Fire Alert\n";
        cout<<"4. Structural Alert\n";
        cout<<"5. Earthquake Alert\n";
        cout<<"6. Flood Alert\n";
        cout<<"7. Cyclone Alert\n";
        cout<<"8. Storm Alert\n";
        cout<<"9. Checklist\n";
        cout<<"10. Need Help?\n";
        cout<<"11. Emergency Contacts\n";
        cout<<"12. Show Sorted Alerts\n";
        cout<<"13. Exit\n";
        cout<<"Choose: ";
        cin>>ch;

        if(ch==13) break;
        string type="";

        if(ch==1) type="Gas Leak Alert";
        if(ch==2) type="Electrical Alert";
        if(ch==3) type="Fire Alert";
        if(ch==4) type="Structural Alert";
        if(ch==5) type="Earthquake Alert";
        if(ch==6) type="Flood Alert";
        if(ch==7) type="Cyclone Alert";
        if(ch==8) type="Storm Alert";

        if(ch>=1 && ch<=8)
        {
            int score = calcRisk(type);

            alert h;
            h.name = type;
            h.score = score;
            h.tips = getTips(type, score);
            record.push_back(h);
           cout<<"\nRisk Score: "<<score<<"\n";
            cout<<"Tips: "<<h.tips<<"\n";

            if(score >= 60){
                cout<<"\n!!! HIGH ALERT !!!\n";
                for(int i=0;i<3;i++) cout<<"\a";
                showContacts();
            }
        }
        else if(ch==9) showChecklist();
        else if(ch==10) needHelp();
        else if(ch==11) showContacts();
        else if(ch==12)
        {
            if(record.empty()) cout<<"No reports yet.\n";
            else{
                mergeSort(record, 0, record.size()-1);
                cout<<"\n  SORTED ALERTS  \n";
                for(auto &h : record)
                    cout<<h.name<<" | Score: "<<h.score<<" | "<<h.tips<<"\n";
            }
        }
        else cout<<"Invalid choice.\n";
    }
   return 0;
}

///O(27+36+6*25*36+27+36)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
    vector<string>TeacherPrep;//27 persons
    vector<string>TeacherPrim;//36 persons
    map<string,ll>mpPrep;
    map<string,ll>mpPrim;
    map<pair<string,string>,ll> PAIR;
    map<pair<string,string>,pair<ll,ll>> SAVEPAIR;

    vector<ll> LowestDay(string who)
{
    vector<ll>idx;
    ll mn = INT_MAX;
    if(who == "prep")
       {
           for(ll i = 0;i < (ll)TeacherPrep.size();i++)
           {
               if(mpPrep[ TeacherPrep[i] ] < mn) mn =  mpPrep[ TeacherPrep[i] ] ;
           }
                for(ll i = 0;i < (ll)TeacherPrep.size();i++)
           {
               if(mpPrep[ TeacherPrep[i] ] == mn) idx.push_back(i) ;
           }
       }
        else
        {
              for(ll i = 0;i < (ll)TeacherPrim.size();i++)
           {
               if(mpPrim[ TeacherPrim[i] ] < mn)  mn =  mpPrim[ TeacherPrim[i] ] ;
           }
                for(ll i = 0;i<TeacherPrim.size();i++)
           {
               if(mpPrim[ TeacherPrim[i] ] == mn) idx.push_back(i) ;
           }
        }

    return idx;
}
int main()
{
   for(ll i = 1;i <= 27;i++){
   string str;
   getline(cin,str);
   TeacherPrep.push_back(str);
    }
string line;
getline(cin,line);
    for(ll i = 1;i <= 36;i++){
   string str;
   getline(cin,str);
   TeacherPrim.push_back(str);
    }
for(ll days = 1;days <= 6;days++)
{
     srand(time(0));
     cout<<"Day "<<days<<"\n";
    for(ll lagna = 1;lagna<=25;lagna++)
    {
        FINDOTHERPAIR:
        HERE1:
        vector<ll> idx = LowestDay("prep");
        ll idx_prep = idx[(rand() % ((ll)idx.size()) )];
        if(mpPrep[TeacherPrep[idx_prep] ] >= days ) goto HERE1;
        HERE2:
        idx = LowestDay("prim");
        ll idx_prim = idx[(rand() % ((ll)idx.size()) )];
        if(mpPrim[TeacherPrim[idx_prim] ] >= days ) goto HERE2;
        if(PAIR[ { TeacherPrep[idx_prep] , TeacherPrim[idx_prim]} ] >= 1 ) goto FINDOTHERPAIR;
else
{
    PAIR[ { TeacherPrep[idx_prep] , TeacherPrim[idx_prim]} ] ++;
    SAVEPAIR[ { TeacherPrep[idx_prep] , TeacherPrim[idx_prim]} ] = {days , lagna};
}
        mpPrep[ TeacherPrep[idx_prep] ] ++;
        mpPrim[ TeacherPrim[idx_prim] ] ++;
        cout<<"Lagna No."<<lagna<<"----->  "<<TeacherPrep[idx_prep] <<"    ---- Prep.\t\t";
        cout<<TeacherPrim[idx_prim] <<"    ---- Prim.\n";
        //cout<<idx_prep<<" "<<idx_prim<<"\n";
    }
}
    cout<<"\n\n\nPrep. Teachers\n";
    for(auto it : mpPrep) cout<<it.first<<" Worked "<<it.second<<" Days\n";
    cout<<"\n\n\nPrim. Teachers\n";
    for(auto it : mpPrim) cout<<it.first<<" Worked "<<it.second<<" Days\n";
    cout<<"\n\n\n";
    for(auto it : SAVEPAIR) cout<<it.first.first<<"\tWith\t"<<it.first.second<<"\tDAY\t"<<it.second.first<<"\tLagna\t"<<it.second.second<<"\n";

    return 0;
}


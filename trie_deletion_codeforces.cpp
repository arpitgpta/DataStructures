//Jai Sai Ram 
// Please help me in every situation 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
//OMG I am implementing tries.
struct info{
 ll count=0;//for counting number of nodes ending currently
 info *binary[2];
 bool ending;
};
info *create_a_new_branch()
{
    info *root=new info;
    root->ending=false;
    root->count=0;
    for(int i=0;i<2;i++)
    root->binary[i]=NULL;
    return root;
}
void insert(info *root,string data)
{
    info *temp=root;//no new initialisation.
    for(int i=0;i<data.length();i++)
    {
        if(temp->binary[data[i]-'0']==NULL)
        {
            temp->binary[data[i]-'0']=create_a_new_branch();
        }
        //cout<<data[i]-'0'<<endl;
        temp->binary[data[i]-'0']->count++;
        temp=temp->binary[data[i]-'0'];
        temp->ending=true;
    }
}
void remove_an_occurence(info *root,string data)
{
    info *temp=root;//remmener this is not copying this is just using same reference                            with a  differet name,
    for(int i=0;i<data.length();i++)
    {
        temp->binary[data[i]-'0']->count--;
        temp=temp->binary[data[i]-'0'];
        if(temp!=NULL&&temp->count<=0)
        {
            temp->ending=false;
        }
    }
}
bool search(string data, info *root)
{
    info *temp=root;
    for(int i=0;i<data.length();i++)
    {
        if(temp->binary[data[i]-'0']==NULL)
            return false;
        temp=temp->binary[data[i]-'0']; 
    }
    if(temp!=NULL&&temp->ending)
    return true;
    return false;
}
ll a[500001],b[500001];
void solve()
{
    ll i,j,k,l,m,n,o;
    cin>>n;
    info *root=new info;
    root=create_a_new_branch();
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
        string s=string(31,'0');
        for(j=0;j<31;j++)
        {
            if((1<<j)&b[i])
            s[30-j]='1';
        }
        insert(root,s);
    }
    for(i=0;i<n;i++)
    {
        string representation=string(31,'0');
        for(j=0;j<31;j++)
        {
            if((1<<j)&a[i])
            representation[30-j]='1';
        }
        // now we got the representation.
        string required="";
        for(j=0;j<31;j++)
        {
            required+=representation[j];
            if(search(required,root))
            {

            }
            else 
            {
                if(required[required.length()-1]=='1')
                required[required.length()-1]='0';
                else
                required[required.length()-1]='1';
            }
        }
       remove_an_occurence(root,required);
        reverse(required.begin(),required.end());
        ll ans=0;
        for(j=0;j<31;j++)
        ans+=(required[j]-'0')*(1<<j);
        cout<<(ans^a[i])<<" ";

    }
}

int main()
{
    ll t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i=1;
   // cin>>t;
    while(t--)
    {
        solve();
        i++;
    }
    return 0;
}

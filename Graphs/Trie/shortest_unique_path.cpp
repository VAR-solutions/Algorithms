Q-Find shortest unique prefix to represent each word in the list.

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov

given a solution class edit in prefix function whith given vector of string input

link-https://www.interviewbit.com/problems/shortest-unique-prefix/

struct TrNode{
    int val;
    TrNode* arr[26];
    bool endOfWord=false;
    TrNode(int x){
        val=x;
        for(int i=0;i<26;i++) arr[i]=NULL;
    }
};


void insert(TrNode* root, string s){
    TrNode* ptr=root;
    
    for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
        
        if(ptr->arr[x]==NULL){
            ptr->arr[x]= new TrNode(-1);
        }else{
            int y=ptr->arr[x]->val+1;
            ptr->arr[x]->val=y;
        }
        
        ptr=ptr->arr[x];
    }
    ptr->endOfWord = true;
}


string search(TrNode* root,string s){
    TrNode* ptr=root;
    
    string ans="";
    
    for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
        
        if(ptr->arr[x]->val==-1){
            ans+=s[i];
            return ans;
        }
        ans+=s[i];
        ptr=ptr->arr[x];
    }
    
    return ans;
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> ans;
    
    TrNode* root = new TrNode(0);
    
    for(string i:A) insert(root,i);
    
    for(string i:A){
        string s=search(root,i);
        ans.push_back(s);
    }
    return ans;
}

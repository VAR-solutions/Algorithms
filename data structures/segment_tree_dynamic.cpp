typedef struct node_container
{
    int val;
    int lazy;
    struct node_container *left,*right;
}tree;

vector< tree > arr;

int idx = 0;
tree* get_node()
{
    arr.push_back({0,0,nullptr,nullptr});
    return &arr[idx++];
}

tree* create()
{
    arr.reserve(15000010);
    return get_node();
}

void update(tree* ptr, int l, int r, int& beg, int& end, int& k)
{
    if(l>end || r<beg)  return;

    if(beg<=l && r<=end)
    {
        if(k==1)    ptr->val=(r-l+1);
        else    ptr->val=0;
        ptr->lazy=k;
        return;
    }

    if(ptr->left ==nullptr) ptr->left=get_node();
    if(ptr->right ==nullptr) ptr->right=get_node();
    int mid=(l+r)>>1;

    if(ptr->lazy==1)
    {
        ptr->left->val=mid-l+1;
        ptr->right->val=r-mid;
        ptr->left->lazy=1;
        ptr->right->lazy=1;
        ptr->lazy=0;
    }
    else if(ptr->lazy==2)
    {
        ptr->left->val=0;
        ptr->right->val=0;
        ptr->left->lazy=2;
        ptr->right->lazy=2;
        ptr->lazy=0;
    }

    update(ptr->left, l, mid, beg, end, k);
    update(ptr->right, mid+1, r, beg, end, k);
    ptr->val=(ptr->left->val + ptr->right->val);
}

tree *root=create();
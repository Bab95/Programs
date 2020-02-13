void bottom_viewutil(Node *root,map<int,pair<int,int> >& my_map,int hd,int level){
    if(root==NULL){
        return;
    }
    if(my_map.find(hd)==my_map.end()){
        pair<int,int> p;
        p.first = level;
        p.second = root->data;
        my_map[hd] = p;
    }else{
        if(my_map[hd].first<=level){
            my_map[hd].first = level;
            my_map[hd].second = root->data;
        }
    }
    bottom_viewutil(root->left,my_map,hd-1,level+1);
    bottom_viewutil(root->right,my_map,hd+1,level+1);
}
void bottomView(Node *root)
{
   // Your Code Here
   map<int,pair<int,int> > my_map;
   bottom_viewutil(root,my_map,0,0);
   map<int,pair<int,int> >::iterator itr;
   for(itr=my_map.begin();itr!=my_map.end();itr++){
       cout<<itr->second.second<<" ";
   }
}

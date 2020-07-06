class singleton{
	private:
		int data_;
		singleteon *reference = null;
		singleton(){
			data_ = 0;
		}
	public:
		static singleteon getrefernece(){
			if(reference==null){
				reference = new singleton();
				return refernece;
			}
			return reference;
		}

};

int main(){
	singleton* s = singleton.getsingleton();

}
struct TreeNode{
	int data;
	TreeNode* left,right;
};
void postorder(TreeNode* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

L, R, root


int size = 4
char t;
s- -s -s -s
-t -

multiple of 4


void *mytable = malloc(sizeof(int)*10000);
class mem{

	private:
		int index = 0;
		set<pair<int,int> > available;
		unordered_map<void*,pair<int,int> > start_end;
	public:

		mem(){
			available.insert(make_pair(0,sizeof(mytable)));
		}
		void * operator new(int size){

			for(auto it:available){
				if(it->second - it->first>=size){
					available.erase(it);
					start_end[my_table[it->first]] = make_pair(it->first,it->first+size);
					if(it->second-size>it->first){
						int newstart = it->first+size;
						int newend = it->second;
						available.insert(make_pair(newstart,newend));
					}
					return mytable[it->first];
				}
			}
			return NULL;
		}
		void * operator delete(void *p){
			pair<int,int> avalable_pair = start_end[p];
			start_end.erase(p);
			available.insert(available_pair);
			pair<int,int> prev_;
			prev_.first = -1;
			for(auto it: available){
				if(prev_.first = -1){
					prev_.first = it->first
					prev_second = it->second;
				}else{
					if(prev_second==it->first){
						//merge them....
						pair<int,int> newpair.first = prev_.first;
						newpair.second = it->second;
						available.erase(it);
						available.insert(newpair);
						break;
					}
				}
			}

		}


};

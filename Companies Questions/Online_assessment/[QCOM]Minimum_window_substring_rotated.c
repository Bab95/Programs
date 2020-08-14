/*
Minimum window in rotated string s such that it contains another string t.
example s = "Melody" t = "ldym"
ans = "lodym" = >length = 5.
*/



#include <stdio.h>
#include <string.h>
#include <limits.h>
int func(char* source,char* target){
	int hash[256];
	int _hash[256];
	memset(hash,0,sizeof(hash));
	memset(_hash,0,sizeof(_hash));
	int len = strlen(source);
	int target_length = strlen(target);
	for(int i=0;i<target_length;i++){
		int c = (int)target[i];
		_hash[c] = _hash[c] + 1;
	}

	int start_index = -1;

	int count = 0;
	int start = 0;
	int ans = INT_MIN;
	for(int step=0;step<2*len;step++){
		hash[(int)source[step%len]] += 1;
		if(_hash[(int)source[step%len]]!=0&&hash[(int)source[step%len]]<=_hash[(int)source[step%len]]){
			count++;
			if(count>len){
				return -1;
			}
		}
		if(target_length==count){
			while(hash[(int)source[start%len]]>_hash[(int)source[start%len]]||_hash[(int)source[start%len]]==0){
				if(hash[(int)source[start%len]]>_hash[(int)source[start%len]]){
					hash[(int)source[start%len]]--;
				}
				start++;
			}
			int window = step-start+1;
			if(ans>window){
				ans = window;
				start_index = start;
			}
		}
	}
	if(ans==INT_MIN){
		cout<<-1<<endl;
	}else{
		int index = start_index%len;
		for(int i=index;i<=index+ans-1;++i){
			printf("%c",source[i]);
		}
	}
	return  ans;
}

#include<iostream>

using namespace std;

void print(char arr[10][10],int m,int n){
	cout<<"\n\nResult\n\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void input(char arr[10][10],char *p[10][10],int *m,int *n){
	cout<<"Row = ";
	cin>>*m;
	cout<<"Column = ";
	cin>>*n;
	cout<<"\n";
	cout<<"\nInput Picture\n";
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			cin>>arr[i][j];
			p[i][j]=&arr[i][j];
		}
	}
}

void remove(char *p_arr[10][10],int x,int y){
	bool check=false;
	//check left
	int left=y-1;
	while(*p_arr[x][left]==*p_arr[x][y]){
		*p_arr[x][left]='-';
		left--;
		check=true;
	}
	//check right
	int right=y+1;
	while(*p_arr[x][right]==*p_arr[x][y]){
		*p_arr[x][right]='-';
		right++;
		check=true;
	}
	//check down
	int down=x+1;
	while(*p_arr[down][y]==*p_arr[x][y]){
		*p_arr[down][y]='-';
		down++;
		check=true;
	}
	if(check==true){
		*p_arr[x][y]='-';
	}
}

void move_remove(char *p_arr[10][10],int x,int y,int move_to){
	if(*p_arr[x][y]!='#'&&move_to=='L'){
		if(*p_arr[x][y-1]=='-'){
			*p_arr[x][y-1]=*p_arr[x][y];
			*p_arr[x][y]='-';
			y--;
			bool pass=false;
			while(pass!=true){
				if(*p_arr[x+1][y]=='-'){
					*p_arr[x+1][y]=*p_arr[x][y];
					*p_arr[x][y]='-';
			        x++;
				}
				else{
					pass=true;
				}
			}
			remove(p_arr,x,y);
		}
	}
	else if(*p_arr[x][y]!='#'&&move_to=='R'){
		if(*p_arr[x][y+1]=='-'){
			*p_arr[x][y+1]=*p_arr[x][y];
			*p_arr[x][y]='-';
			y++;
			bool pass=false;
			while(pass!=true){
				if(*p_arr[x+1][y]=='-'){
					*p_arr[x+1][y]=*p_arr[x][y];
					*p_arr[x][y]='-';
			        x++;
				}
				else{
					pass=true;
				}
			}
			remove(p_arr,x,y);
		}
	}
}

void Down(char *p_arr[10][10],int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(*p_arr[i][j]!='-'&&*p_arr[i][j]!='#'){
				if(*p_arr[i+1][j]=='-'){
					*p_arr[i+1][j]=*p_arr[i][j];
					*p_arr[i][j]='-';
				}
			}
		}
	}
}

void process_print(char *p_arr[10][10],int *m,int *n){
	int x,y,number_move;
	char move_to;
	cout<<"Number Of Move Order : ";
	cin>>number_move;
	for(int i=0;i<number_move;i++){
		cout<<i+1<<" : Choose Position : ";
	    cin>>x>>y;
	    cout<<"Move To -> ";
	    cin>>move_to;
	    Down(p_arr,*m,*n);
	    move_remove(p_arr,x,y,move_to);
	}
	
}


int main(){
	char arr[10][10],*p[10][10];
	int m,n;
	input(arr,p,&m,&n);
	
	process_print(p,&m,&n);
	print(arr,m,n);
}

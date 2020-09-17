#include <iostream> 

using namespace std;  
  
void swap(int *a, int *b){  
    int temp=*a;  
    *a=*b;  
    *b=temp;  
}  
int split (int arr[100],int Size_Low,int Size_High){  
    int Keep=arr[Size_High];   
    int i=Size_Low - 1;   
  
    for (int j=Size_Low;j<=Size_High-1;j++){  
        if (arr[j]<Keep){  
            i++;  
            swap(&arr[i],&arr[j]);  
        }  
    }  
    swap(&arr[i+1],&arr[Size_High]);  
    return (i+1);  
}  
  
void Quick_Sort(int arr[100],int Size_Low,int Size_High){  
    if (Size_Low<Size_High)  
    {  
        int index = split(arr,Size_Low,Size_High);  
  
        Quick_Sort(arr,Size_Low,index-1);  
        Quick_Sort(arr,index + 1,Size_High);  
    }  
}  

int Count(int arr[100]){
	int re=0;
	while(arr[re]!='\0'){
		re++;
	}
	return re;
}
  
void print(int arr[100],int Size){   
    for (int i=0;i<Size;i++){
        cout<<arr[i]<<" "; 
	}
}  
  
int main(){  
    int arr[100];
	int number;
	cout<<"Number of Input : ";
	cin>>number;
	for(int i=0;i<number;i++){
		cin>>arr[i];
	}
    int Size=Count(arr)-1;  
    Quick_Sort(arr,0,Size);  
    cout <<"\nAfter Sorted \n";  
    print(arr, Size);  
    return 0;  
}  

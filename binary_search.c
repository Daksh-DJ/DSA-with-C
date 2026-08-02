#include<stdio.h>
int main(){
	int n;
	printf("enter how many elements you want to add");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		printf("enter the elements you want to add");
		scanf("%d",&arr[i]);
	}
	int a;
	printf("enter the number you want to find ");
	scanf("%d",&a);
	int min=0;
	int max=n-1;
	int mid=0;
	while(min<=max){
		mid=min+(max-min)/2;
		if(arr[mid]==a){
			printf("the element has been found and its position is %d",mid);
			return 0;
		}
		else if(arr[mid]>a){
			max=mid-1;
		}
		else if(arr[mid]<a){
			min=mid+1;
		}
	}
	printf("the element is not on the array");
	return 0;
}